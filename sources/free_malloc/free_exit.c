/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:39:40 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/26 15:33:42 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "free_malloc.h"
#include "stdlib.h"
#include "mlx.h"

void    free_mlx(t_mlx_data *mlx_data)
{
    if(mlx_data->mlx_ptr)
    {
    if (mlx_data->east_mlx_ptr)
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->east_mlx_ptr);
     if (mlx_data->west_mlx_ptr)
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->west_mlx_ptr);
     if (mlx_data->south_mlx_ptr)
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->south_mlx_ptr);
     if (mlx_data->north_mlx_ptr)
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->north_mlx_ptr);
    if (mlx_data->win_ptr)
        mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
    if (mlx_data->img.addr)
    {
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img.img_ptr);
    }
    mlx_destroy_display(mlx_data->mlx_ptr);  
    free(mlx_data->mlx_ptr);
    free(mlx_data);
    }
}

void    free_parsing(t_parsing_data *parsing_data)
{
    free_and_set_null(parsing_data->east_texture_path);
	free_and_set_null(parsing_data->north_texture_path);
	free_and_set_null(parsing_data->south_texture_path);
	free_and_set_null(parsing_data->west_texture_path);
	ft_free_tab(parsing_data->map);
	free(parsing_data);
}

void    free_data_mlx_parsing(t_game *game)
{
    free_mlx(game->mlx_data);
    free_parsing(game->parsing_data);
}