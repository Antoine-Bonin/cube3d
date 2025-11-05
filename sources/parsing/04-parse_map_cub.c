/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04-parse_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:50:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 10:02:47 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/includes/libft.h"
#include "stdlib.h"

int	parse_map_line(char *line, t_parsing_data *data)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (data->map_height + 2));
	if (!new_map)
		return (0);
	i = 0;
	while (i < data->map_height)
	{
		new_map[i] = data->map[i];
		i++;
	}
	new_map[data->map_height] = ft_strdup(line);
	if (!new_map[data->map_height])
	{
		free(new_map);
		return (0);
	}
	new_map[data->map_height + 1] = NULL;
	free(data->map);
	data->map = new_map;
	data->map_height++;
	return (1);
}
