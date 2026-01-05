/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/05 19:09:16 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "draw.h"
#include "init.h"
#include "mlx.h"
#include "parsing.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define SENSITIVITY 0.020

void init_parsing_data(t_parsing_data *parsing_data)
{
	int i;

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
	parsing_data->map_width = 0;
	parsing_data->player_x = 0;
	parsing_data->player_y = 0;
	parsing_data->player_direction = '\0';
	parsing_data->textures_complete = false;
	parsing_data->dup_found = false;
}

void init_mlx(t_mlx_data *mlx_data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mlx_data->textures[i++] = NULL;
	}
	mlx_data->mlx_ptr = NULL;
	mlx_data->win_ptr = NULL;
	mlx_data->img_height = 64;
	mlx_data->img_width = 64;
}

void init_game(t_game *game, t_mlx_data *data)
{
	game->mlx_data = data;
	game->ceiling_color = 0;
	game->floor_color = 0;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player = NULL;
}

int mouse_handler(int x, int y, t_game *game)
{
	int delta_x;
	int center_x = LENGTH / 2;
	(void)y;
	if (x == center_x)
		return (0);
	delta_x = x - center_x;
	game->player->deg += delta_x * SENSITIVITY;
	mlx_mouse_move(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr, center_x, HEIGHT / 2);
	return 0;
}

int environment(t_game *game)
{
	calc_trigo_for_draw(game);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr, game->mlx_data->img.img_ptr, 0, 0);
	return 0;
}

int main(int ac, char **av)
{
	t_parsing_data parsing_data;
	t_mlx_data mlx_data;
	t_game game;

	init_parsing_data(&parsing_data);
	init_mlx(&mlx_data);
	init_game(&game, &mlx_data);
	if (ac > 1)
	{
		if (!parsing(av[1], &parsing_data))
			return (cleanup(&parsing_data, 1, &game));
		if (!init_wdwimg_and_textures(&parsing_data, &mlx_data))
			return (cleanup(&parsing_data, 1, &game));
		if (!parse_game_data(&game, &parsing_data))
			return (cleanup(&parsing_data, 0, &game));
		mlx_hook(mlx_data.win_ptr, 17, 0, (int (*)())close_window, &game);
		mlx_hook(mlx_data.win_ptr, MotionNotify, PointerMotionMask, mouse_handler, &game);
		mlx_hook(mlx_data.win_ptr, KeyPress, KeyPressMask,
				 (int (*)())handle_keypress, &game);
		mlx_loop_hook(mlx_data.mlx_ptr, environment, &game);

		mlx_loop(mlx_data.mlx_ptr);
	}
	return (cleanup(NULL, 0, &game));
}

// x = 0;
// y = 0;
// while (x < game.map_height)
// {
// 	y = 0;
// 	while (game.map[x][y].type != '\0')
// 	{
// 		printf("%c",game.map[x][y].type);
// 		y++;
// 	}
// 	printf("\n");
// 	x++;
// }
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