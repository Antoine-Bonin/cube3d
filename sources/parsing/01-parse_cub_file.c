/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-parse_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:07 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 17:54:17 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "fcntl.h"
#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdio.h"
#include "stdlib.h"

bool	all_textures_parsed(t_parsing_data *data)
{
	return (data->north_texture_path && data->south_texture_path && data->west_texture_path
		&& data->east_texture_path && data->floor_color[0] != -1
		&& data->ceiling_color[0] != -1);
}

static char	*next_line(int fd, char *current)
{
	char	*line;

	free(current);
	line = get_next_line(fd);
	return (line);
}

static int	handle_texture_line(t_parsing_data *data, char *line)
{
	if (!parse_textures_cub(line, data))
		return (0);
	data->textures_complete = all_textures_parsed(data);
	return (1);
}

static int	handle_map_line(t_parsing_data *data, char *line, bool *started)
{
	if (is_whitespace_str(line))
		return (1);
	*started = true;
	return (parse_map_line(line, data));
}

int	parse_cub_file_loop(int fd, t_parsing_data *data, char *line,
		bool *map_started)
{
	while (line)
	{
		if (is_whitespace_str(line) && !*map_started)
		{
			line = next_line(fd, line);
			continue ;
		}
		if (!data->textures_complete && handle_texture_line(data, line))
		{
			line = next_line(fd, line);
			continue ;
		}
		if (!data->textures_complete)
			return (msg_error_and_free(MISSING_TEXTURE, 1, line));
		if (!handle_map_line(data, line, map_started))
			return (error_cleanup(data, 1, NULL));
		line = next_line(fd, line);
	}
	return (0);
}
