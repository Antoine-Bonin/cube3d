/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04-parse_texture_cub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:57:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 15:25:19 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

int	get_texture(char **texture_ptr, char *trimmed, int offset,
		t_parsing_data *parsing_data)
{
	if (*texture_ptr != NULL)
	{
		parsing_data->dup_found = true;
		return (msg_error(DUPLICATE_TEXTURE, 0));
	}
	*texture_ptr = ft_strtrim(trimmed + offset, " \t\n");
	if (!*texture_ptr)
		malloc_error_in_parsing_exit(parsing_data);
	return (1);
}

int	parse_textures(char *trimmed, t_parsing_data *parsing_data)
{
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (get_texture(&parsing_data->north_texture_path, trimmed, 3,
				parsing_data));
	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (get_texture(&parsing_data->south_texture_path, trimmed, 3,
				parsing_data));
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (get_texture(&parsing_data->west_texture_path, trimmed, 3,
				parsing_data));
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (get_texture(&parsing_data->east_texture_path, trimmed, 3,
				parsing_data));
	return (0);
}

int	parse_color(char *trimmed, t_parsing_data *parsing_data)
{
	int	result;

	result = 0;
	if (ft_strncmp(trimmed, "F ", 2) == 0)
	{
		if (parsing_data->floor_color[0] != -1)
		{
			parsing_data->dup_found = true;
			return (msg_error(DUPLICATE_FLOOR, 0));
		}
		result = get_color_in_data(parsing_data->floor_color, trimmed + 2);
		return (result);
	}
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
	{
		if (parsing_data->ceiling_color[0] != -1)
		{
			parsing_data->dup_found = true;
			return (msg_error(DUPLICATE_CEILING, 0));
		}
		result = get_color_in_data(parsing_data->ceiling_color, trimmed + 2);
		return (result);
	}
	return (0);
}

int	parse_textures_cub(char *line, t_parsing_data *parsing_data)
{
	char	*trimmed;
	int		result;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (0);
	result = 0;
	if (parse_textures(trimmed, parsing_data))
		result = 1;
	else
		result = parse_color(trimmed, parsing_data);
	free(trimmed);
	return (result);
}
