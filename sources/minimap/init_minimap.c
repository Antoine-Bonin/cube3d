/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:51:46 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/16 16:29:32 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "mlx.h"
#include "utils.h"

static void	*cc(void *mlx_ptr, int size, int color)
{
	void	*img;
	char	*data;
	int		info[3];
	int		i;
	int		j;

	img = mlx_new_image(mlx_ptr, size, size);
	data = mlx_get_data_addr(img, &info[1], &info[0], &info[2]);
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
	return (img);
}

static void	save_old_images(void **temp, t_mlx_data *mlx_data)
{
	int	i;

	i = -1;
	while (++i < MAX)
		temp[i] = mlx_data->minimap_img[i];
}

static void	create_new_images(t_game *game, int size)
{
	int	i;

	i = -1;
	while (++i < MAX)
	{
		if (i == PLAYER)
		{
			game->mlx_data->minimap_img[i] = cc(game->mlx_data->mlx_ptr, size
					/ 1.5, color_argb(CONTRAST,
						g_type_block[i].color_mini_map[0],
						g_type_block[i].color_mini_map[1],
						g_type_block[i].color_mini_map[2]));
		}
		else
		{
			game->mlx_data->minimap_img[i] = cc(game->mlx_data->mlx_ptr, size,
					color_argb(CONTRAST,
						g_type_block[i].color_mini_map[0],
						g_type_block[i].color_mini_map[1],
						g_type_block[i].color_mini_map[2]));
		}
	}
}

static void	destroy_old_images(void **temp, void *mlx_ptr)
{
	int	i;

	i = -1;
	while (++i < MAX)
	{
		if (temp[i])
			mlx_destroy_image(mlx_ptr, temp[i]);
	}
}

void	recreate_minimap_images(t_game *game, int size)
{
	void	*temp[MAX];

	save_old_images(temp, game->mlx_data);
	create_new_images(game, size);
	destroy_old_images(temp, game->mlx_data->mlx_ptr);
	game->mlx_data->minimap_tile_size = size;
}
