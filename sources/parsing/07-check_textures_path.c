/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07-check_textures_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:11:13 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 15:11:44 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "mlx.h"
#include "messages.h"

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
