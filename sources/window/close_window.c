/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/07 19:55:31 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"
#include <X11/keysym.h>
#include "minimap.h"

#define ESC_KEY 65307

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx_data->mlx_ptr);
	return 0;
}

int	move_player(int keysym, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->player->pos_x;
	old_y = game->player->pos_y;
	if (keysym == 16779592 || keysym == XK_Up)
		game->player->pos_y--;
	else if (keysym == 16779591  || keysym == XK_Down)
		game->player->pos_y++;
	else if (keysym == 16779595 || keysym == XK_Left)
		game->player->pos_x--;
	else if (keysym == 16779597 || keysym == XK_Right)
		game->player->pos_x++;
	else
		return (1);
	if (game->map[(int)game->player->pos_y][(int)game->player->pos_x].type == '1' || game->map[(int)game->player->pos_y][(int)game->player->pos_x].type == ' ')
	{
		game->player->pos_x = old_x;
		game->player->pos_y = old_y;
		return (1);
	}
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	printf("keycode : %d\n", keycode);
	if (keycode == ESC_KEY)
		return close_window(game);
	if (keycode == 65289)
		draw_map(game);
	if (move_player(keycode, game) == 0)
		draw_map(game);
	return (0);
}
