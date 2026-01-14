/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_for_dda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:40:21 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:27:56 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <float.h>
#include <math.h>

bool	block_is_solid(t_tile block)
{
	if (block.is_solid == true)
		return (true);
	return (false);
}

int	size_block_in_height(double proj_to_screen, t_dir dda, t_game *game)
{
	double	side_dist_recalc;

	side_dist_recalc = dda.side_dist * cos(game->rad_for_col
			- deg_to_rad(game->player->deg));
	if (side_dist_recalc == 0)
		side_dist_recalc = DBL_MIN;
	return (proj_to_screen / side_dist_recalc);
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

bool	check_if_after_limit(int point, int size_max)
{
	if (point >= 0 || point <= size_max)
		return (true);
	return (false);
}

double	delta_dist(double ray_dir)
{
	if (fabs(ray_dir) < 1e-5)
		return (DBL_MAX);
	return (fabs(1.00 / ray_dir));
}
