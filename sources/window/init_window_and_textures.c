/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_and_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:14:59 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 10:53:54 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "messages.h"
#include "mlx.h"
#include "window.h"
#include "free_malloc.h"

static int	init_textures(t_parsing_data *parsing_data, t_mlx_data *mlx_data)
{
	char	*paths[4];
	int		i;

	paths[0] = parsing_data->north_texture_path;
	paths[1] = parsing_data->west_texture_path;
	paths[2] = parsing_data->east_texture_path;
	paths[3] = parsing_data->south_texture_path;
	i = 0;
	while (i < 4)
	{
		mlx_data->textures[i] = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
				paths[i], &mlx_data->img_width, &mlx_data->img_height);
		if (!mlx_data->textures[i])
			return (msg_error(TEXTURE_PATH, 0));
		i++;
	}
	return (1);
}

int	init_window_and_textures(t_parsing_data *parsing_data, t_mlx_data *mlx_data)
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
	return (1);
}
