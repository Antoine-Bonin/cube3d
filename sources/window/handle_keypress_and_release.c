/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_and_release.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 14:57:55 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window.h"
#define ESC_KEY 65307

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx_data->mlx_ptr);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		return (close_window(game));
	if (keycode == 65289)
		game->minimap.visible = !game->minimap.visible;
	set_key_state(keycode, game, true);
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	set_key_state(keycode, game, false);
	return (0);
}
