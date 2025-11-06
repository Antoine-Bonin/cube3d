/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-check_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:46 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 14:51:31 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "messages.h"
#include "mlx.h"
#include "parsing.h"
#include "stdlib.h"

bool	is_file_name_correct(char *map)
{
	int	map_len;

	map_len = ft_strlen(map);
	if (map_len < 5)
		return (0);
	if (map[map_len - 3] == 'c' && map[map_len - 2] == 'u' && map[map_len
		- 1] == 'b')
		return (1);
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
	if (!parse_cub_file_loop(fd, data, line, &map_started))
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

int	floor_ceiling_color_valid(t_parsing_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((data->floor_color[i] > 255 || data->floor_color[i] < 0)
			|| (data->ceiling_color[i] < 0 || data->ceiling_color[i] > 255))
			return (msg_error(WRONG_RGB, 0));
		i++;
	}
	return (1);
}

int	texture_to_mlx(t_parsing_data *data, t_mlx_data *mlx_data)
{
	int	width;
	int	height;

	width = 80;
	height = 80;
	mlx_data->north_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			data->north_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	mlx_data->south_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			data->south_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	mlx_data->west_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			data->west_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	mlx_data->east_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			data->east_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	if (!mlx_data->north_mlx_ptr || !mlx_data->south_mlx_ptr
		|| !mlx_data->west_mlx_ptr || !mlx_data->east_mlx_ptr)
		return (0);
	return (msg_error(TEXTURE_PATH, 0));
	return (0);
}

int	start_of_parsing(char *FileName, t_parsing_data *data, t_mlx_data *mlx_data)
{
	if (!is_file_name_correct(FileName))
		return (msg_error(INVALID_NAME, 1));
	if (parse_cub_file(FileName, data))
		return (1);
	if (texture_to_mlx(data, mlx_data))
		return (1);
	if (!floor_ceiling_color_valid(data))
		return (1);
	if (!is_map_valid(data))
		return (1);
	// if (!valid_map(data->map))
	// 	return (1);
	return (0);
}
