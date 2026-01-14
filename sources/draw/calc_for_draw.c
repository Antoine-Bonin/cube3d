/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_for_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:40:21 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:28:05 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "init.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

int	resize_height(int value)
{
	if (value < 0)
		value = 0;
	if (value > HEIGHT)
		value = HEIGHT - 1;
	return (value);
}

int	x_find_pixel_for_img(t_game *game, t_dir dda_point, int length)
{
	double	x_find;

	if (dda_point.x_or_y == 'x')
		x_find = game->player->pos_y + (dda_point.side_dist
				* dda_point.for_inverse_point->ray.raydir);
	else
		x_find = game->player->pos_x + (dda_point.side_dist
				* dda_point.for_inverse_point->ray.raydir);
	x_find = x_find - (int)x_find;
	if ((dda_point.x_or_y == 'x' && dda_point.ray.raydir < 0)
		|| (dda_point.x_or_y == 'y' && dda_point.ray.raydir > 0))
	{
		x_find = 1.0 - x_find;
	}
	return (x_find * length);
}
