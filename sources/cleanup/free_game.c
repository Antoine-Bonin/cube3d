/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:51:27 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:22 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "mlx.h"
#include "stdlib.h"

t_tile	**free_map_tile(t_tile **map, int height)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	free(map);
	return (NULL);
}

void	free_mlx_image(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	if (mlx_data->win_ptr)
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	while (i != MAX)
	{
		if (mlx_data->graphics.minimap_img[i])
			mlx_destroy_image(mlx_data->mlx_ptr,
				mlx_data->graphics.minimap_img[i]);
		i++;
	}
}

void	destroy_mlx_img(t_mlx_data *mlx_data)
{
	if (mlx_data->graphics.screen.img_ptr)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->graphics.screen.img_ptr);
		mlx_data->graphics.screen.img_ptr = NULL;
	}
	if (mlx_data->graphics.minimap_buffer_created
		&& mlx_data->graphics.map_buf.img_ptr)
	{
		mlx_destroy_image(mlx_data->mlx_ptr,
			mlx_data->graphics.map_buf.img_ptr);
		mlx_data->graphics.map_buf.img_ptr = NULL;
	}
	if (mlx_data->mlx_ptr)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
	}
}

void	free_mlx(t_mlx_data *mlx_data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (mlx_data->graphics.textures[i].img_ptr)
			mlx_destroy_image(mlx_data->mlx_ptr,
				mlx_data->graphics.textures[i].img_ptr);
		mlx_data->graphics.textures[i].img_ptr = NULL;
	}
	free_mlx_image(mlx_data);
	destroy_mlx_img(mlx_data);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map.tiles)
	{
		free_map_tile(game->map.tiles, game->map.height);
		game->map.tiles = NULL;
	}
	if (game->mlx_data)
	{
		free_mlx(game->mlx_data);
		game->mlx_data = NULL;
	}
	if (game->player)
	{
		free(game->player);
		game->player = NULL;
	}
}
