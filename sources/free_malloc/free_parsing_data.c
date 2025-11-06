/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:06 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 18:07:40 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
#include "stdlib.h"

static void	free_and_set_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_tab(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
	}
}

void	free_mlx(t_mlx_data *mlx_data)
{
	free_and_set_null(mlx_data->north_mlx_ptr);
	free_and_set_null(mlx_data->west_mlx_ptr);
	free_and_set_null(mlx_data->east_mlx_ptr);
	free_and_set_null(mlx_data->south_mlx_ptr);
	free_and_set_null(mlx_data->win_ptr);
	free_and_set_null(mlx_data->mlx_ptr);
	free(mlx_data);
}

int	error_cleanup(t_parsing_data *data, int error, t_mlx_data *mlx_data)
{
	if (data->east_texture_path)
	{
		free(data->east_texture_path);
		data->east_texture_path = NULL;
	}
	if (data->north_texture_path)
	{
		free(data->north_texture_path);
		data->north_texture_path = NULL;
	}
	if (data->south_texture_path)
	{
		free(data->south_texture_path);
		data->south_texture_path = NULL;
	}
	if (data->west_texture_path)
	{
		free(data->west_texture_path);
		data->west_texture_path = NULL;
	}
	free_mlx(mlx_data);
	ft_free_tab(data->map);
	free(data);
	return (error);
}

int	malloc_error_parsing(t_parsing_data *data)
{
	free_and_set_null(data->east_texture_path);
	free_and_set_null(data->north_texture_path);
	free_and_set_null(data->south_texture_path);
	free_and_set_null(data->west_texture_path);
	ft_free_tab(data->map);
	free(data);
	exit(1);
}
