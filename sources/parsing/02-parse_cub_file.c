/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-parse_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:07 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:22:04 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "messages.h"
#include "parsing.h"

int	close_fd_and_return(int fd, int error)
{
	close(fd);
	return (error);
}

int	parse_cub_file(char *filename, t_parsing_data *parsing_data)
{
	int		fd;
	char	*line;
	bool	map_started;

	fd = open_file(filename);
	if (fd == 0)
		return (msg_error(OPEN_ERROR, 0));
	map_started = false;
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (msg_error(MALLOC_ERR, 0));
	}
	if (!parse_cub_file_loop(fd, parsing_data, line, &map_started))
		return (close_fd_and_return(fd, 0));
	close(fd);
	if (parsing_data->textures_complete == false && !map_started)
		return (msg_error(MISSING_ALL, 0));
	if (parsing_data->textures_complete == false)
		return (msg_error(MISSING_TEXTURE, 0));
	if (!map_started)
		return (msg_error(MISSING_MAP, 0));
	return (1);
}
