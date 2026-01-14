/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03-parse_cub_file_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:19:47 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:22:36 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

static bool	all_textures_parsed(t_parsing_data *parsing_data)
{
	return (parsing_data->north_texture_path && parsing_data->south_texture_path
		&& parsing_data->west_texture_path && parsing_data->east_texture_path
		&& parsing_data->floor_color[0] != -1
		&& parsing_data->ceiling_color[0] != -1);
}

static char	*next_line(int fd, char *current)
{
	char	*line;

	free(current);
	line = get_next_line(fd);
	return (line);
}

static int	handle_texture_line(t_parsing_data *parsing_data, char *line)
{
	if (!parse_textures_cub(line, parsing_data))
		return (0);
	parsing_data->textures_complete = all_textures_parsed(parsing_data);
	return (1);
}

static int	handle_map_line(t_parsing_data *parsing_data, char *line,
		bool *started)
{
	if (is_whitespace_str(line) && !*started)
		return (1);
	*started = true;
	return (parse_map_line(line, parsing_data));
}

int	parse_cub_file_loop(int fd, t_parsing_data *parsing_data, char *line,
		bool *map_started)
{
	while (line)
	{
		if (is_whitespace_str(line) && !*map_started)
		{
			line = next_line(fd, line);
			continue ;
		}
		if (parsing_data->textures_complete == false
			&& handle_texture_line(parsing_data, line))
		{
			line = next_line(fd, line);
			continue ;
		}
		if (parsing_data->dup_found == true)
		{
			free(line);
			return (0);
		}
		if (parsing_data->textures_complete == false)
			return (msg_error_and_free(MISSING_TEXTURE, 0, line));
		if (!handle_map_line(parsing_data, line, map_started))
			return (cleanup(parsing_data, 0, NULL));
		line = next_line(fd, line);
	}
	return (1);
}
