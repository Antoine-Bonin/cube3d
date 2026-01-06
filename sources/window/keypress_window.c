/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/06 11:39:32 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "minimap.h"
#include "mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"
#include <X11/keysym.h>
#define W_KEY 16779592
#define A_KEY 16779595
#define S_KEY 16779591
#define D_KEY 16779597

#define ESC_KEY 65307

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx_data->mlx_ptr);
	return (0);
}

int	move_player(int keysym, t_game *game)
{
    if (keysym == W_KEY || keysym == XK_Up)
        return (move_forward(game));
    else if (keysym == S_KEY || keysym == XK_Down)
        return (move_backward(game));
    else if (keysym == A_KEY || keysym == XK_Left)
        return (strafe_left(game));
    else if (keysym == D_KEY || keysym == XK_Right)
        return (strafe_right(game));
    return (1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		return (close_window(game));
	if (keycode == 65289)
		game->show_minimap = !game->show_minimap;
	move_player(keycode, game);
	return (0);
}
