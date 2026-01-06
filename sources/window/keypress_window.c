/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/09 10:53:05 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "minimap.h"
#include "mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"
#include <X11/keysym.h>

#define ESC_KEY 65307

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx_data->mlx_ptr);
	return (0);
}

static int	check_collision(t_game *game, int x, int y)
{
	if (game->map[y][x].is_solid)
		return (1);
	return (0);
}

int	move_player(int keysym, t_game *game)
{
	double	old_x;
	double	old_y;

	old_x = game->player->pos_x;
	old_y = game->player->pos_y;
	if (keysym == 16779592 || keysym == XK_Up)
		game->player->pos_y--;
	else if (keysym == 16779591 || keysym == XK_Down)
		game->player->pos_y++;
	else if (keysym == 16779595 || keysym == XK_Left)
		game->player->pos_x--;
	else if (keysym == 16779597 || keysym == XK_Right)
		game->player->pos_x++;
	else
		return (1);
	if (check_collision(game, (int)game->player->pos_x,
			(int)game->player->pos_y))
	{
		game->player->pos_x = old_x;
		game->player->pos_y = old_y;
		return (1);
	}
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		return (close_window(game));
	if (keycode == 65289)
	{
		mlx_clear_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr);
		game->show_minimap = !game->show_minimap;
		if (game->show_minimap)
			draw_big_minimap(game, game->size_minimap + 5);
		else
			draw_minimap(game, game->size_minimap);
	}
	if (move_player(keycode, game) == 0)
	{
		mlx_clear_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr);
		if (game->show_minimap)
			draw_big_minimap(game, game->size_minimap + 5);
		else
			draw_minimap(game, game->size_minimap);
	}
	return (0);
}
