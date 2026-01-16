/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:33:59 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/16 14:38:47 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <math.h>

int	check_collision(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->map_width || map_y < 0
		|| map_y >= game->map_height)
		return (1);
	if (game->map[map_y][map_x].type == ' ')
	{
		game->player->pos_x = game->player->base_pos_x;
		game->player->pos_y = game->player->base_pos_y;
		return (1);
	}
	if (game->map[map_y][map_x].is_solid)
		return (1);
	return (0);
}

int	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = game->player->deg * (M_PI / 180.0);
	new_x = game->player->pos_x + cos(rad) * game->player->move_speed;
	new_y = game->player->pos_y + sin(rad) * game->player->move_speed;
	if (!check_collision(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
		return (0);
	}
	return (1);
}

int	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = game->player->deg * (M_PI / 180.0);
	new_x = game->player->pos_x - cos(rad) * game->player->move_speed;
	new_y = game->player->pos_y - sin(rad) * game->player->move_speed;
	if (!check_collision(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
		return (0);
	}
	return (1);
}

int	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = (game->player->deg - 90) * (M_PI / 180.0);
	new_x = game->player->pos_x + cos(rad) * game->player->move_speed;
	new_y = game->player->pos_y + sin(rad) * game->player->move_speed;
	if (!check_collision(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
		return (0);
	}
	return (1);
}

int	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	rad;

	rad = (game->player->deg + 90) * (M_PI / 180.0);
	new_x = game->player->pos_x + cos(rad) * game->player->move_speed;
	new_y = game->player->pos_y + sin(rad) * game->player->move_speed;
	if (!check_collision(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
		return (0);
	}
	return (1);
}
