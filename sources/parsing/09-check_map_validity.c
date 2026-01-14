/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09-check_map_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:48:47 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 17:44:36 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

int	find_player(t_parsing_data *parsing_data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < parsing_data->map_height)
	{
		j = 0;
		while (parsing_data->map[i][j])
		{
			if (parsing_data->map[i][j] == 'N' || parsing_data->map[i][j] == 'S'
				|| parsing_data->map[i][j] == 'E'
				|| parsing_data->map[i][j] == 'W')
			{
				*x = j;
				*y = i;
				parsing_data->player_direction = parsing_data->map[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_multi_player(t_parsing_data *parsing_data, int found_player)
{
	int	i;
	int	j;

	i = 0;
	while (i < parsing_data->map_height)
	{
		j = 0;
		while (parsing_data->map[i][j])
		{
			if (parsing_data->map[i][j] == 'N' || parsing_data->map[i][j] == 'S'
				|| parsing_data->map[i][j] == 'E'
				|| parsing_data->map[i][j] == 'W')
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

	copy = (char **)ft_calloc(sizeof(char *), (height + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		if (ft_strlen(map[i]) > 2000)
		{
			msg_error_and_free(MAP_TOO_BIG, 0, copy);
			return (NULL);
		}
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
	}
	copy[height] = NULL;
	return (copy);
}

int	is_map_valid(t_parsing_data *parsing_data)
{
	char	**map_copy;
	int		result;

	if (parsing_data->map_height < 3)
		return (msg_error(MAP_TOO_SMALL, 0));
	if (parsing_data->map_height > 2000)
		return (msg_error(MAP_TOO_BIG, 0));
	if (!find_player(parsing_data, &parsing_data->player_x,
			&parsing_data->player_y))
		return (msg_error(NO_PLAYER, 0));
	if (find_multi_player(parsing_data, 0))
		return (msg_error(MULTI_PLAYER, 0));
	if (find_invalid_char(parsing_data))
		return (msg_error(INVALID_CHAR, 0));
	map_copy = copy_map(parsing_data->map, parsing_data->map_height);
	if (!map_copy)
		return (0);
	result = flood_fill_iterative(map_copy, parsing_data->player_x,
			parsing_data->player_y, 0);
	ft_free_tab(map_copy);
	if (!result)
		return (msg_error(FLOOD_FILL, 0));
	return (result);
}
