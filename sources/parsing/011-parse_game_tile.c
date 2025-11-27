/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   011-parse_game_tile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:07:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 15:16:21 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "libft.h"
#include "parsing.h"
#include "stdlib.h"

void	init_null_tile(t_tile *tile)
{
	tile->type = '\0';
	tile->is_player = false;
	tile->is_solid = false;
	tile->is_transparent = true;
	tile->floor_height = 0.0;
	tile->ceiling_height = 0.0;
	tile->map_x = -1;
	tile->map_y = -1;
}

static void	parse_tile_line(t_tile *tiles, char *line, int y)
{
	int	x;
	int	line_len;

	line_len = (int)ft_strlen(line);
	x = -1;
	while (++x <= line_len)
		init_null_tile(&tiles[x]);
	x = -1;
	while (++x < line_len)
	{
		if (line[x] == '1')
			is_wall(&tiles[x], line[x], x, y);
		else if (line[x] == '0')
			is_floor(&tiles[x], line[x], x, y);
		else if (line[x] == ' ')
			is_hole(&tiles[x], line[x], x, y);
		else if (line[x] == 'E' || line[x] == 'N' || line[x] == 'W'
			|| line[x] == 'S')
			is_player(&tiles[x], line[x], x, y);
	}
}

t_tile	**parse_map_tile(char **map, int height, int y, int x)
{
	t_tile	**tiles;
	int		i;
	int		line_len;

	(void)x;
	tiles = (t_tile **)malloc(sizeof(t_tile *) * height);
	if (!tiles)
		return (NULL);
	i = -1;
	while (++i < height)
		tiles[i] = NULL;
	while (++y < height && tiles)
	{
		line_len = (int)ft_strlen(map[y]);
		tiles[y] = (t_tile *)malloc(sizeof(t_tile) * (line_len + 1));
		if (!tiles[y])
			return (free_map_tile(tiles, height));
		parse_tile_line(tiles[y], map[y], y);
	}
	return (tiles);
}
