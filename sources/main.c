/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2025/11/26 16:22:47 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "init.h"
#include "mlx.h"
#include "parsing.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"
#include <X11/X.h>
#include <X11/keysym.h>

t_parsing_data *init_parsing_data(void)
{
	t_parsing_data *parsing_data;
	int i;

	parsing_data = (t_parsing_data *)malloc(sizeof(t_parsing_data));
	if (!parsing_data)
		return (NULL);
	parsing_data->north_texture_path = NULL;
	parsing_data->south_texture_path = NULL;
	parsing_data->south_texture_path = NULL;
	parsing_data->west_texture_path = NULL;
	parsing_data->east_texture_path = NULL;
	parsing_data->map = NULL;
	i = -1;
	while (++i < 3)
	{
		parsing_data->ceiling_color[i] = -1;
		parsing_data->floor_color[i] = -1;
	}
	parsing_data->map_height = 0;
	parsing_data->player_x = 0;
	parsing_data->player_y = 0;
	parsing_data->player_direction = '\0';
	parsing_data->textures_complete = false;
	parsing_data->dup_found = false;
	return (parsing_data);
}

t_mlx_data *init_mlx(void)
{
	t_mlx_data *data;
	

	data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	data->east_mlx_ptr = NULL;
	data->south_mlx_ptr = NULL;
	data->north_mlx_ptr = NULL;
	data->west_mlx_ptr = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_height = 0;
	data->img_width = 0;
	data->exit = 0;
	return (data);
}

int main(int ac, char **av)
{
	t_parsing_data *parsing_data;
	t_mlx_data *mlx_data;
	t_game game;

	parsing_data = init_parsing_data();
	if (!parsing_data)
		return (1);
	mlx_data = init_mlx();
	game.parsing_data = parsing_data;
	game.mlx_data = mlx_data;
	if (!mlx_data)
		return (1);
	if (ac > 1)
	{
		if (!parsing(av[1], parsing_data))
			return (error_cleanup(parsing_data, 1, mlx_data));
		if (!init_wdwimg_and_textures(parsing_data, mlx_data))
			return (error_cleanup(parsing_data, 1, mlx_data));
		mlx_hook(mlx_data->win_ptr, 17, 0, (int (*)())close_window, mlx_data);
		mlx_hook(mlx_data->win_ptr, KeyPress, KeyPressMask,
				 (int (*)())handle_keypress, mlx_data);
		mlx_loop(mlx_data->mlx_ptr);
	}

	return (error_cleanup(parsing_data, 0, mlx_data));
}

// int i = 0;
// if (parsing_data->map)
// {
// 	while (parsing_data->map[i])
// 	{
// 		printf("%s", parsing_data->map[i]);
// 		i++;
// 	}
// 	printf("\n%s\n", parsing_data->north_texture_path);
// 	printf("%s\n", parsing_data->east_texture_path);
// 	printf("%s\n", parsing_data->south_texture_path);
// 	printf("%s\n", parsing_data->west_texture_path);
// 	printf("floor color : %d,%d,%d\n", parsing_data->floor_color[0],
// 		parsing_data->floor_color[1], parsing_data->floor_color[2]);
// 	printf("ceiling color : %d,%d,%d\n", parsing_data->ceiling_color[0],
// 		parsing_data->ceiling_color[1], parsing_data->ceiling_color[2]);
// 	printf("player direction : %c\n", parsing_data->player_direction);
// 	printf("player x : %d\n", parsing_data->player_x);
// 	printf("player y : %d\n", parsing_data->player_y);
// }