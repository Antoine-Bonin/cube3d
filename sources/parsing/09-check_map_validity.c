/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09-check_map_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:48:47 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 18:04:29 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

int	find_player(t_parsing_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				*x = j;
				*y = i;
				data->player_direction = data->map[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_multi_player(t_parsing_data *data, int found_player)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				found_player++;
			j++;
		}
		i++;
	}
	if (found_player > 1)
		return (1);
	return (0);
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

int	flood_fill(char **map, int x, int y, t_parsing_data *data)
{
	if (y < 0 || y >= data->map_height)
		return (0);
	if (x < 0)
		return (0);
	if (x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	map[y][x] = 'V';
	if (!flood_fill(map, x + 1, y, data))
		return (0);
	if (!flood_fill(map, x - 1, y, data))
		return (0);
	if (!flood_fill(map, x, y + 1, data))
		return (0);
	if (!flood_fill(map, x, y - 1, data))
		return (0);
	return (1);
}

int	is_map_valid(t_parsing_data *data)
{
	char	**map_copy;
	int		result;

	if (data->map_height < 3)
		return (msg_error(MAP_TOO_SMALL, 0));
	if (data->map_height > 1000)
		return (msg_error(MAP_TOO_BIG, 0));
	if (!find_player(data, &data->player_x, &data->player_y))
		return (msg_error(NO_PLAYER, 0));
	if (find_multi_player(data, 0))
		return (msg_error(MULTI_PLAYER, 0));
	if (find_invalid_char(data))
		return (msg_error(INVALID_CHAR, 0));
	map_copy = copy_map(data->map, data->map_height);
	if (!map_copy)
		return (0);
	result = flood_fill(map_copy, data->player_x, data->player_y, data);
	if (!result)
	{
		ft_free_tab(map_copy);
		return (msg_error(FLOOD_FILL, 0));
	}
	ft_free_tab(map_copy);
	return (result);
}
