/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-parse_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:07 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/11 15:22:45 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "messages.h"

int	parse_cub_file(char *filename, t_parsing_data *data)
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
	if (!parse_cub_file_loop(fd, data, line, &map_started))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (data->textures_complete == false && !map_started)
		return (msg_error(MISSING_ALL, 0));
	if (data->textures_complete == false)
		return (msg_error(MISSING_TEXTURE, 0));
	if (!map_started)
		return (msg_error(MISSING_MAP, 0));
	return (1);
}

