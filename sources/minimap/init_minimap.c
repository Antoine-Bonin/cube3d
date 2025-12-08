/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:51:46 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/08 11:31:26 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parsing.h"
#include <stddef.h>

static void	fill_image(char *data, int size, int color, int *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			((unsigned int *)(data + (i * info[0] + j * (info[1]
								/ 8))))[0] = color;
			j++;
		}
		i++;
	}
}

void	*cc(void *mlx_ptr, int size, int color)
{
	void	*img;
	char	*data;
	int		info[3];

	img = mlx_new_image(mlx_ptr, size, size);
	data = mlx_get_data_addr(img, &info[1], &info[0], &info[2]);
	fill_image(data, size, color, info);
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
	game->mlx_data->minimap_wall_img = cc(game->mlx_data->mlx_ptr, size,
			0xFFFFFF);
	game->mlx_data->minimap_floor_img = cc(game->mlx_data->mlx_ptr, size,
			0x808080);
	game->mlx_data->minimap_empty_img = cc(game->mlx_data->mlx_ptr, size,
			0x000000);
	game->mlx_data->minimap_player_img = cc(game->mlx_data->mlx_ptr, size / 2,
			0xFF0000);
	game->mlx_data->minimap_tile_size = size;
}
