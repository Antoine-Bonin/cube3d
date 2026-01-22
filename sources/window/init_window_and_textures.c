/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_and_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:14:59 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:06:57 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "messages.h"
#include "mlx.h"
#include "window.h"

int	init_img(t_mlx_data *mlx_data)
{
	mlx_data->graphics.screen.img_ptr = NULL;
	mlx_data->graphics.screen.addr = NULL;
	mlx_data->graphics.screen.img_ptr = mlx_new_image(mlx_data->mlx_ptr, LENGTH,
			HEIGHT);
	if (mlx_data->graphics.screen.img_ptr == NULL)
		return (0);
	mlx_data->graphics.screen.addr = \
mlx_get_data_addr(mlx_data->graphics.screen.img_ptr,
			&mlx_data->graphics.screen.bits_per_pixel,
			&mlx_data->graphics.screen.line_length,
			&mlx_data->graphics.screen.endian);
	if (mlx_data->graphics.screen.addr == NULL)
		return (0);
	return (1);
}

static int	init_textures(t_parsing_data *parsing_data, t_mlx_data *mlx_data)
{
	char	*paths[4];
	int		i;

	paths[NORTH] = parsing_data->north_texture_path;
	paths[SOUTH] = parsing_data->south_texture_path;
	paths[EAST] = parsing_data->east_texture_path;
	paths[WEST] = parsing_data->west_texture_path;
	i = 0;
	while (i < 4)
	{
		mlx_data->graphics.textures[i].img_ptr = \
mlx_xpm_file_to_image(mlx_data->mlx_ptr,
				paths[i], &mlx_data->graphics.textures[i].img_width,
				&mlx_data->graphics.textures[i].img_height);
		if (!mlx_data->graphics.textures[i].img_ptr)
			return (msg_error(TEXTURE_PATH, 0));
		mlx_data->graphics.textures[i].addr = \
mlx_get_data_addr(mlx_data->graphics.textures[i].img_ptr,
				&mlx_data->graphics.textures[i].bits_per_pixel,
				&mlx_data->graphics.textures[i].line_length,
				&mlx_data->graphics.textures[i].endian);
		if (!mlx_data->graphics.textures[i].addr)
			return (msg_error(TEXTURE_PATH, 0));
		i++;
	}
	return (1);
}

int	init_img_and_textures(t_parsing_data *parsing_data, t_mlx_data *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (0);
	if (!init_textures(parsing_data, mlx_data))
		return (0);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, LENGTH, HEIGHT,
			"Cub3D");
	if (!mlx_data->win_ptr)
		return (0);
	if (init_img(mlx_data) == 0)
		return (0);
	return (1);
}
