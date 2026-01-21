/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:36:35 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/21 19:51:44 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <float.h>
#include <math.h>
#define FOV_DEG 90

t_dir	calc_side_dist(t_dir value, int pos, double pos_in_double)
{
	if (value.ray.raydir > 0 && value.ray.raydir != DBL_MAX)
	{
		value.positive = true;
		value.side_dist = ((1 + pos) - pos_in_double) * value.ray.delta_dist;
	}
	else if (value.ray.raydir != DBL_MAX)
	{
		value.positive = false;
		value.side_dist = (pos_in_double - pos) * value.ray.delta_dist;
	}
	else
		value.side_dist = DBL_MAX;
	return (value);
}

t_dir	calc_direction(t_dir value, t_game *game, char x_or_y)
{
	value.x_or_y = x_or_y;
	value.steps = 1;
	if (x_or_y == 'x')
	{
		value = calc_side_dist(value, game->player->pos_x_int,
				game->player->pos_x);
		if (value.positive == 1)
			value.texture_use = EAST;
		else
			value.texture_use = WEST;
	}
	else
	{
		value = calc_side_dist(value, game->player->pos_y_int,
				game->player->pos_y);
		if (value.positive == 1)
			value.texture_use = NORTH;
		else
			value.texture_use = SOUTH;
	}
	if (value.positive != 1)
		value.steps = -1;
	return (value);
}

void	check_block_by_block(t_dir for_x, t_dir for_y, t_game *game,
		double proj_to_screen)
{
	t_dir	*choice;

	while (1)
	{
		if (for_x.side_dist <= for_y.side_dist)
		{
			choice = &for_x;
			game->player->pos_x_int += for_x.steps;
		}
		else
		{
			choice = &for_y;
			game->player->pos_y_int += for_y.steps;
		}
		if (block_is_solid(game->map[game->player->pos_y_int]\
[game->player->pos_x_int]) == true)
			break ;
		choice->side_dist += choice->ray.delta_dist;
	}
	for_x.for_inverse_point = &for_y;
	for_y.for_inverse_point = &for_x;
	draw(game, *choice, choice->texture_use, proj_to_screen);
}

void	calc_derivative_and_delta_dist(double rad, double proj_to_screen,
		t_game *game)
{
	t_dir	for_x;
	t_dir	for_y;

	for_x.ray.raydir = cos(rad);
	for_y.ray.raydir = sin(rad);
	for_x.ray.delta_dist = delta_dist(for_x.ray.raydir);
	for_y.ray.delta_dist = delta_dist(for_y.ray.raydir);
	return (calc_player_to_intersection_x_or_y(for_x, for_y, game,
			proj_to_screen));
}

void	calc_init_for_ray(t_player *player, t_game *game)
{
	static bool		init = false;
	static double	proj_to_screen;
	double			rad_player;
	int				position_x_to_center;

	if (!init)
	{
		proj_to_screen = (double)(LENGTH >> 1) / tan(deg_to_rad(FOV_DEG >> 1));
		init = true;
	}
	game->param_draw.x_pixel = 0;
	rad_player = deg_to_rad(player->deg);
	while (game->param_draw.x_pixel < LENGTH)
	{
		position_x_to_center = game->param_draw.x_pixel - (LENGTH >> 1);
		player->pos_x_int = (int)player->pos_x;
		player->pos_y_int = (int)player->pos_y;
		game->param_draw.rad_for_x = rad_player + atan(position_x_to_center
				/ proj_to_screen);
		calc_derivative_and_delta_dist(game->param_draw.rad_for_x, proj_to_screen, game);
		game->param_draw.x_pixel++;
	}
}
