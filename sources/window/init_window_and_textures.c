/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_and_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:14:59 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/07 21:06:44 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "messages.h"
#include "mlx.h"
#include "stdio.h"
#include "window.h"

int init_img(t_mlx_data *mlx_data)
{
	mlx_data->img.img_ptr = NULL;
	mlx_data->img.addr = NULL;
	mlx_data->img.img_ptr = mlx_new_image(mlx_data->mlx_ptr, LENGTH, HEIGHT);
	if (mlx_data->img.img_ptr == NULL)
		return (0);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.img_ptr,
										   &mlx_data->img.bits_per_pixel, &mlx_data->img.line_length,
										   &mlx_data->img.endian);
	if (mlx_data->img.addr == NULL)
		return (0);
	return (1);
}

static int init_textures(t_parsing_data *parsing_data, t_mlx_data *mlx_data)
{
	char *paths[4];
	int i;

	paths[NORTH] = parsing_data->north_texture_path;
	paths[SOUTH] = parsing_data->south_texture_path;
	paths[EAST] = parsing_data->east_texture_path;
	paths[WEST] = parsing_data->west_texture_path;
	i = 0;
	while (i < 4)
	{
		mlx_data->textures[i].img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
															  paths[i], &mlx_data->textures[i].img_width, &mlx_data->textures[i].img_height);
		if (!mlx_data->textures[i].img_ptr)
			return (msg_error(TEXTURE_PATH, 0));
		mlx_data->textures[i].addr = mlx_get_data_addr(
			mlx_data->textures[i].img_ptr,
			&mlx_data->textures[i].bits_per_pixel,
			&mlx_data->textures[i].line_length,
			&mlx_data->textures[i].endian);
		if (!mlx_data->textures[i].addr)
			return (msg_error(TEXTURE_PATH, 0));
		i++;
	}
	return (1);
}

int init_wdwimg_and_textures(t_parsing_data *parsing_data, t_mlx_data *mlx_data)
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
