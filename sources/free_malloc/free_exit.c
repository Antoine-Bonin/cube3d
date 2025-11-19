/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:39:40 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 10:39:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "free_malloc.h"
#include "stdlib.h"
#include "mlx.h"

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
	if (mlx_data->mlx_ptr)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
	}
}

void    free_parsing(t_parsing_data *parsing_data)
{
    free_and_set_null(parsing_data->east_texture_path);
	free_and_set_null(parsing_data->north_texture_path);
	free_and_set_null(parsing_data->south_texture_path);
	free_and_set_null(parsing_data->west_texture_path);
	ft_free_tab(parsing_data->map);
}

static void	free_map(t_tile **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
	{
		free(game->player);
		game->player = NULL;
	}
	if (game->map)
	{
		free_map(game->map, game->map_height);
		game->map = NULL;
	}
}
