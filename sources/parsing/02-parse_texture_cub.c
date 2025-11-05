/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-parse_texture_cub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:57:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 11:03:33 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "free_malloc.h"
#include "parsing.h"
#include "stdlib.h"

int	get_texture(char **texture_ptr, char *trimmed, int offset,
		t_parsing_data *data)
{
	*texture_ptr = ft_strtrim(trimmed + offset, " \t\n");
	if (!*texture_ptr)
		malloc_error_parsing(data);
	return (1);
}

int	parse_only_textures(char *trimmed, t_parsing_data *data)
{
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (get_texture(&data->no_texture, trimmed, 3, data));
	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (get_texture(&data->so_texture, trimmed, 3, data));
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (get_texture(&data->we_texture, trimmed, 3, data));
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (get_texture(&data->ea_texture, trimmed, 3, data));
	return (0);
}

int	parse_color(char *trimmed, t_parsing_data *data)
{
	int	result;

	result = 0;
	if (ft_strncmp(trimmed, "F ", 2) == 0)
	{
		result = get_color_in_data(data->floor_color, trimmed + 2);
		return (result);
	}
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
	{
		result = get_color_in_data(data->ceiling_color, trimmed + 2);
		return (result);
	}
	return (0);
}

int	parse_textures_cub(char *line, t_parsing_data *data)
{
	char	*trimmed;
	int		result;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (0);
	result = 0;
	if (parse_only_textures(trimmed, data))
		result = 1;
	else if (parse_color(trimmed, data))
		result = 1;
	free(trimmed);
	return (result);
}
