/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:39:40 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/27 16:01:50 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "mlx.h"
#include "stdlib.h"
#include "structures.h"

void	free_mlx(t_mlx_data *mlx_data)
{
	int	i;

	if (!mlx_data)
		return ;
	i = 0;
	while (i < 4)
	{
		if (mlx_data->textures[i])
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->textures[i]);
		i++;
	}
	if (mlx_data->win_ptr)
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	
	if (mlx_data->img.img_ptr)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img.img_ptr);
		mlx_data->img.img_ptr = NULL;
	}
	if (mlx_data->mlx_ptr)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
	}
}

void	free_parsing(t_parsing_data *parsing_data)
{
	free_and_set_null(parsing_data->east_texture_path);
	free_and_set_null(parsing_data->north_texture_path);
	free_and_set_null(parsing_data->south_texture_path);
	free_and_set_null(parsing_data->west_texture_path);
	ft_free_tab(parsing_data->map);
}

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

void	free_game(t_game *game)
{
	if (!game)
		return ;
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
	if (game->map)
	{
		free_map_tile(game->map, game->map_height);
		game->map = NULL;
	}
}
