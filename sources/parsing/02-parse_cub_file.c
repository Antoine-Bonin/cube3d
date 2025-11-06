/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-parse_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:07 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 15:28:15 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/includes/libft.h"
#include "messages.h"

int	parse_cub_file(char *filename, t_parsing_data *data)
{
	int		fd;
	char	*line;
	bool	map_started;

	fd = open_file(filename);
	if (fd == 0)
		return (0);
	map_started = false;
	line = get_next_line(fd);
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
