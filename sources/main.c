/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/21 20:58:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "free_malloc.h"
#include "minimap.h"
#include "mlx.h"
#include "parsing.h"
#include "utils.h"
#include "window.h"
#include <X11/X.h>
#include "stdio.h"

int	environment(t_game *game)
{
	move_player(game);
	calc_trigo_for_draw(game);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->img.img_ptr, 0, 0);
	choose_which_minimap_to_draw(game);
	count_fps(game);
	draw_fps(game);
	return (0);
}

void	mlx_all_hook(t_game *game, t_mlx_data mlx_data)
{
	mlx_hook(mlx_data.win_ptr, 17, 0, (int (*)())close_window, game);
	mlx_hook(mlx_data.win_ptr, KeyPress, KeyPressMask,
		(int (*)())handle_keypress, game);
	mlx_hook(mlx_data.win_ptr, KeyRelease, KeyReleaseMask,
		(int (*)())handle_keyrelease, game);
	mlx_hook(mlx_data.win_ptr, 6, 1L << 6, mouse_handler, game);
}

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
		if (!init_wdwimg_and_textures(&parsing_data, &mlx_data))
			return (cleanup(&parsing_data, 1, &game));
		if (!parse_game_data(&game, &parsing_data))
			return (cleanup(&parsing_data, 1, &game));
		mlx_all_hook(&game, mlx_data);
		mlx_loop_hook(mlx_data.mlx_ptr, environment, &game);
		mlx_loop(mlx_data.mlx_ptr);
	}
	printf("Error\nto test the game : \"./cube.3d maps/map_name\"\n");
	return (cleanup(NULL, 0, &game));
}
