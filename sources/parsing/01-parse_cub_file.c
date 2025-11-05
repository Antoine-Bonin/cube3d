/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-parse_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:07 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 11:26:31 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "fcntl.h"
#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

int	open_file(char *FileName)
{
	int	fd;

	fd = open(FileName, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\nCan't open file", 2);
		return (0);
	}
	return (fd);
}

int	is_whitespace_str(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i])
	{
		if ((str[i] < 9 || str[i] > 13) && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

bool	all_textures_parsed(t_parsing_data *data)
{
	return (data->no_texture && data->so_texture && data->we_texture
		&& data->ea_texture && data->floor_color[0] != -1
		&& data->ceiling_color[0] != -1);
}

int	parse_cub_file_loop(int fd, t_parsing_data *data, char *line,
		bool *map_started)
{
	while (line)
	{
		if (is_whitespace_str(line) && !*map_started)
		{
			line = super_get_next_line(fd, line);
			continue ;
		}
		if (data->textures_complete == false && parse_textures_cub(line, data))
		{
			data->textures_complete = all_textures_parsed(data);
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (!data->textures_complete)
			return (msg_error_and_free(MISSING_TEXTURE, 1, line));
		if (!is_whitespace_str(line))
		{
			*map_started = true;
			if (!parse_map_line(line, data))
				return (error_cleanup(data, 1));
		}
		line = super_get_next_line(fd, line);
	}
	return (0);
}

int	parse_cub_file(char *filename, t_parsing_data *data)
{
	int		fd;
	char	*line;
	bool	map_started;

	fd = open_file(filename);
	if (fd == 0)
		return (1);
	map_started = false;
	line = get_next_line(fd);
	if (parse_cub_file_loop(fd, data, line, &map_started))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (data->textures_complete == false && !map_started)
		return (msg_error(MISSING_ALL, 1));
	if (data->textures_complete == false)
		return (msg_error(MISSING_TEXTURE, 1));
	if (!map_started)
		return (msg_error(MISSING_MAP, 1));
	return (0);
}
