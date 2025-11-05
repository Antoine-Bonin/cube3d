/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2025/11/05 17:51:18 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "init.h"
#include "parsing.h"
#include "stdio.h"
#include "stdlib.h"

t_parsing_data	*init_parsing_data(void)
{
	t_parsing_data	*data;
	int				i;

	data = (t_parsing_data *)malloc(sizeof(t_parsing_data));
	if (!data)
		return (NULL);
	data->north_texture_path = NULL;
	data->south_texture_path = NULL;
	data->south_texture_path = NULL;
	data->west_texture_path = NULL;
	data->east_texture_path = NULL;
	data->map = NULL;
	i = 0;
	while (i < 3)
	{
		data->ceiling_color[i] = -1;
		data->floor_color[i] = -1;
		i++;
	}
	data->map_height = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_direction = '\0';
	data->textures_complete = false;
	return (data);
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
	return (data);
}

int	main(int ac, char **av)
{
	t_parsing_data	*data;
	t_mlx_data *mlx_data;
	int				i;

	data = init_parsing_data();
	if (!data)
		return (1);
	mlx_data = init_mlx();
	if (!mlx_data)
		return (1);
	if (ac > 1)
	{
		if (start_of_parsing(av[1], data, mlx_data))
			return (error_cleanup(data, 1, mlx_data));
		i = 0;
		if (data->map)
		{
			while (data->map[i])
			{
				printf("%s", data->map[i]);
				i++;
			}
			printf("\n%s\n", data->north_texture_path);
			printf("%s\n", data->east_texture_path);
			printf("%s\n", data->south_texture_path);
			printf("%s\n", data->west_texture_path);
			printf("floor color : %d,%d,%d\n", data->floor_color[0],
				data->floor_color[1], data->floor_color[2]);
			printf("ceiling color : %d,%d,%d\n", data->ceiling_color[0],
				data->ceiling_color[1], data->ceiling_color[2]);
			printf("player direction : %c\n", data->player_direction);
			printf("player x : %d\n", data->player_x);
			printf("player y : %d\n", data->player_y);
		}
	}
	return (error_cleanup(data, 0, mlx_data));
}
