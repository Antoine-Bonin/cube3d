/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_and_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:14:59 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/18 13:20:44 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "messages.h"
#include "mlx.h"
#include "window.h"

static int	init_textures(t_parsing_data *parsing_data, t_mlx_data *mlx_data)
{
	int	width;
	int	height;

	width = 80;
	height = 80;
	mlx_data->north_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			parsing_data->north_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	mlx_data->south_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			parsing_data->south_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	mlx_data->west_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			parsing_data->west_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	mlx_data->east_mlx_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			parsing_data->east_texture_path, &mlx_data->img_width,
			&mlx_data->img_height);
	if (!mlx_data->north_mlx_ptr || !mlx_data->south_mlx_ptr
		|| !mlx_data->west_mlx_ptr || !mlx_data->east_mlx_ptr)
		return (msg_error(TEXTURE_PATH, 0));
	return (1);
}

int	init_window_and_textures(t_parsing_data *game, t_mlx_data *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (0);
	if (!init_textures(game, mlx_data))
		return (0);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, LENGTH, HEIGHT,
			"Cub3D");
	if (!mlx_data->win_ptr)
		return (0);
	return (1);
}
