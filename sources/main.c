/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/22 15:07:36 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "cleanup.h"
#include "mlx.h"
#include "parsing.h"
#include "init.h"
#include "window.h"

int	main(int ac, char **av)
{
	t_parsing_data	parsing_data;
	t_mlx_data		mlx_data;
	t_game			game;

	init_parsing_data(&parsing_data);
	init_mlx(&mlx_data);
	init_game(&game, &mlx_data);
	if (ac == 2)
	{
		if (!parsing(av[1], &parsing_data))
			return (cleanup(&parsing_data, 1, &game));
		if (!init_img_and_textures(&parsing_data, &mlx_data))
			return (cleanup(&parsing_data, 1, &game));
		if (!parse_game_data(&game, &parsing_data))
			return (cleanup(&parsing_data, 1, &game));
		mlx_all_hook(&game, mlx_data);
		mlx_loop_hook(mlx_data.mlx_ptr, environment, &game);
		mlx_loop(mlx_data.mlx_ptr);
	}
	else
	{
		printf("Error\nUsage: ./cub3d <map.cub>\n");
		return (cleanup(NULL, 1, &game));
	}
	return (cleanup(NULL, 0, &game));
}
