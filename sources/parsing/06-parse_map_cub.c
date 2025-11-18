/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06-parse_map_cub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:50:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/18 13:14:03 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/includes/libft.h"
#include "stdlib.h"

int	parse_map_line(char *line, t_parsing_data *parsing_data)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (parsing_data->map_height + 2));
	if (!new_map)
		return (0);
	i = 0;
	while (i < parsing_data->map_height)
	{
		new_map[i] = parsing_data->map[i];
		i++;
	}
	new_map[parsing_data->map_height] = ft_strdup(line);
	if (!new_map[parsing_data->map_height])
	{
		free(new_map);
		return (0);
	}
	new_map[parsing_data->map_height + 1] = NULL;
	free(parsing_data->map);
	parsing_data->map = new_map;
	parsing_data->map_height++;
	return (1);
}
