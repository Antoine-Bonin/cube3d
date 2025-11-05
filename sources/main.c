/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2025/11/05 11:05:01 by antbonin         ###   ########.fr       */
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
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->map = NULL;
	i = 0;
	while (i < 3)
	{
		data->ceiling_color[i] = -1;
		data->floor_color[i] = -1;
		i++;
	}
	data->map_height = 0;
	data->textures_complete = false;
	return (data);
}

int	main(int ac, char **av)
{
	t_parsing_data	*data;
	int				i;

	data = init_parsing_data();
	if (!data)
		return (1);
	if (ac > 1)
	{
		start_of_parsing(av[1], data);
		i = 0;
		if (data->map)
		{
			while (data->map[i])
			{
				printf("%s", data->map[i]);
				i++;
			}
			printf("\n%s\n", data->no_texture);
			printf("%s\n", data->ea_texture);
			printf("%s\n", data->so_texture);
			printf("%s\n", data->we_texture);
			printf("floor color : %d,%d,%d\n", data->floor_color[0],
				data->floor_color[1], data->floor_color[2]);
			printf("ceiling color : %d,%d,%d\n", data->ceiling_color[0],
				data->ceiling_color[1], data->ceiling_color[2]);
		}
	}
	return (error_cleanup(data, 0));
}
