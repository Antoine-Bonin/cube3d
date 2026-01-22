/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:06:16 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:06:57 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "window.h"
#include "mlx.h"

int	mouse_handler(int x, int y, t_game *game)
{
	int			delta_x;
	static int	center_x = LENGTH / 2;
	static int	center_y = HEIGHT / 2;
	int			delta_y;

	delta_x = x - center_x;
	delta_y = y - center_y;
	if (delta_x != 0)
		game->player->deg += delta_x * SENSITIVITY;
	if (y != center_y)
	{
		game->render.params.orientation_vert -= delta_y * (SENSITIVITY * 8);
		if (game->render.params.orientation_vert >= HEIGHT)
			game->render.params.orientation_vert = HEIGHT - 1;
		if (game->render.params.orientation_vert <= -HEIGHT)
			game->render.params.orientation_vert = -HEIGHT + 1;
	}
	if (x != center_x || y != center_y)
		mlx_mouse_move(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
			center_x, center_y);
	return (0);
}
