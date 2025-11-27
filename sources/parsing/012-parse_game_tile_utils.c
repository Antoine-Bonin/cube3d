/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   012-parse_game_tile_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:07:30 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 15:08:24 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_wall(t_tile *tile, char c, int x, int y)
{
	tile->type = c;
	tile->map_x = x;
	tile->map_y = y;
	tile->is_player = false;
	tile->is_solid = true;
	tile->is_transparent = false;
	tile->floor_height = 0.0;
	tile->ceiling_height = 1.0;
}

void	is_floor(t_tile *tile, char c, int x, int y)
{
	tile->type = c;
	tile->map_x = x;
	tile->map_y = y;
	tile->is_player = false;
	tile->is_solid = false;
	tile->is_transparent = true;
	tile->floor_height = 0.0;
	tile->ceiling_height = 1.0;
}

void	is_hole(t_tile *tile, char c, int x, int y)
{
	tile->type = c;
	tile->map_x = x;
	tile->map_y = y;
	tile->is_player = false;
	tile->is_solid = false;
	tile->is_transparent = true;
	tile->floor_height = -1.0;
	tile->ceiling_height = 0.0;
}

void	is_player(t_tile *tile, char c, int x, int y)
{
	tile->type = c;
	tile->map_x = x;
	tile->map_y = y;
	tile->is_player = true;
	tile->is_solid = false;
	tile->is_transparent = true;
	tile->floor_height = -1.0;
	tile->ceiling_height = 0.0;
}
