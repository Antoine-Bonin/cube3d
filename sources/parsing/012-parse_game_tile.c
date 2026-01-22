/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   012-parse_game_tile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:07:15 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:22 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "libft.h"
#include "parsing.h"
#include "stdlib.h"

int	find_index(char type)
{
	int	i;

	i = 0;
	if (type == 'N' || type == 'S' || type == 'E' || type == 'W')
		return (find_index('P'));
	else
	{
		while (g_type_index[i] != '\0')
		{
			if (g_type_index[i] == type)
				return (i);
			i++;
		}
	}
	return (-1);
}

static void	parse_tile_line(t_tile *tiles, char *line, int y, int max_len)
{
	int	x;
	int	line_len;
	int	result;

	line_len = (int)ft_strlen(line);
	x = -1;
	while (++x < max_len)
	{
		if (x < line_len && line[x] != '\0' && line[x] != '\n')
		{
			result = find_index(line[x]);
			if (result < 0 || result >= MAX)
				tiles[x] = g_type_block[HOLE];
			else
				tiles[x] = g_type_block[result];
		}
		else
			tiles[x] = g_type_block[END];
		tiles[x].map_x = x;
		tiles[x].map_y = y;
	}
}

t_tile	**parse_map_tile(char **map, int height, int y, int width)
{
	t_tile	**tiles;
	int		i;

	tiles = (t_tile **)ft_calloc(sizeof(t_tile *), height);
	if (!tiles)
		return (NULL);
	i = -1;
	while (++i < height)
		tiles[i] = NULL;
	while (++y < height && tiles)
	{
		tiles[y] = (t_tile *)malloc(sizeof(t_tile) * width);
		if (!tiles[y])
			return (free_map_tile(tiles, height));
		parse_tile_line(tiles[y], map[y], y, width);
	}
	return (tiles);
}
