/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:51:46 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/07 19:39:36 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "mlx.h"
#include <stddef.h>

void	*create_colored_square(void *mlx_ptr, int size, int color)
{
	void	*img;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
	int		i;
	int		j;

	img = mlx_new_image(mlx_ptr, size, size);
	data = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			((unsigned int *)(data + (i * line_len + j * (bpp / 8))))[0] = color;
			j++;
		}
		i++;
	}
	return (img);
}

void	recreate_minimap_images(t_game *game, int size)
{
	if (game->mlx_data->minimap_wall_img)
		mlx_destroy_image(game->mlx_data->mlx_ptr,
			game->mlx_data->minimap_wall_img);
	if (game->mlx_data->minimap_floor_img)
		mlx_destroy_image(game->mlx_data->mlx_ptr,
			game->mlx_data->minimap_floor_img);
	if (game->mlx_data->minimap_empty_img)
		mlx_destroy_image(game->mlx_data->mlx_ptr,
			game->mlx_data->minimap_empty_img);
	if (game->mlx_data->minimap_player_img)
		mlx_destroy_image(game->mlx_data->mlx_ptr,
			game->mlx_data->minimap_player_img);
	game->mlx_data->minimap_wall_img = create_colored_square(
			game->mlx_data->mlx_ptr, size, 0xFFFFFF);
	game->mlx_data->minimap_floor_img = create_colored_square(
			game->mlx_data->mlx_ptr, size, 0x808080);
	game->mlx_data->minimap_empty_img = create_colored_square(
			game->mlx_data->mlx_ptr, size, 0x000000);
	game->mlx_data->minimap_player_img = create_colored_square(
			game->mlx_data->mlx_ptr, size / 2, 0xFF0000);
	game->mlx_data->minimap_tile_size = size;
}
