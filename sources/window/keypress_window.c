/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:20:20 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window.h"
#include <X11/keysym.h>
#define W_KEY 16779592
#define A_KEY 16779595
#define S_KEY 16779591
#define D_KEY 16779597
#define Q_KEY 16779596
#define ESC_KEY 65307

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx_data->mlx_ptr);
	return (0);
}

static void	set_key_state(int keycode, t_game *game, bool state)
{
	if (keycode == W_KEY)
		game->keys.w = state;
	else if (keycode == A_KEY)
		game->keys.a = state;
	else if (keycode == S_KEY)
		game->keys.s = state;
	else if (keycode == D_KEY)
		game->keys.d = state;
	else if (keycode == Q_KEY)
		game->keys.q = state;
	else if (keycode == XK_Left)
		game->keys.left = state;
	else if (keycode == XK_Right)
		game->keys.right = state;
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		return (close_window(game));
	if (keycode == 65289)
		game->show_minimap = !game->show_minimap;
	set_key_state(keycode, game, true);
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	set_key_state(keycode, game, false);
	return (0);
}

void	move_player(t_game *game)
{
	sprint(game);
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
		strafe_left(game);
	if (game->keys.d)
		strafe_right(game);
	if (game->keys.right)
		see_to_the_right(game);
	if (game->keys.left)
		see_to_the_left(game);
}
