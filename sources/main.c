/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/09 21:09:56 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "free_malloc.h"
#include "init.h"
#include "minimap.h"
#include "mlx.h"
#include "parsing.h"
#include "stdio.h"
#include "stdlib.h"
#include "tile.h"
#include "window.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "libft.h"

#define SENSITIVITY 0.02

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

	i = -1;
	while (++i < 4)
		mlx_data->textures[i].img_ptr = NULL;
	i = -1;
	while (++i < MAX)
		mlx_data->minimap_img[i] = NULL;
	mlx_data->mlx_ptr = NULL;
	mlx_data->win_ptr = NULL;
	mlx_data->img.img_ptr = NULL;
	mlx_data->img_height = 64;
	mlx_data->img_width = 64;
	mlx_data->minimap_tile_size = 0;
}

void init_game(t_game *game, t_mlx_data *data)
{
	game->mlx_data = data;
	game->ceiling_color.value = 0;
	game->floor_color.value = 0;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player = NULL;
	game->show_minimap = false;
	game->size_minimap = 5;
	game->keys.w = false;
	game->keys.a = false;
	game->keys.s = false;
	game->keys.d = false;
	game->keys.up = false;
	game->keys.down = false;
	game->keys.left = false;
	game->keys.right = false;
	game->frame_count = 0;
	game->last_time = time(NULL);
	game->fps = 0;
}

int mouse_handler(int x, int y, t_game *game)
{
	int delta_x;
	static int center_x = LENGTH / 2;
	static int center_y = HEIGHT / 2;
	int delta_y;
	// if (x == center_x)
	// 	return (0);

	delta_x = x - center_x;
	delta_y = y - center_y;
	if (delta_x != 0)
		game->player->deg += delta_x * SENSITIVITY;
	if (y != center_y)
	{
		game->param_draw.orientation_vert -= delta_y * (SENSITIVITY * 8);
		// if (game->param_draw.orientation_vert > 0)
		// 	game->param_draw.orientation_vert -= game->param_draw.orientation_vert * 2;
		// else 
		// 	game->param_draw.orientation_vert -= game->param_draw.orientation_vert;
		if (game->param_draw.orientation_vert >= HEIGHT)
			game->param_draw.orientation_vert = HEIGHT - 1;
		if (game->param_draw.orientation_vert <= -HEIGHT )
			game->param_draw.orientation_vert = -HEIGHT + 1;
	}
	if (x != center_x || y != center_y)
		mlx_mouse_move(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr, center_x,
					   center_y);
	return (0);
}

void draw_fps(t_game *game)
{
	char *fps_str;
	char *fps_num;

	fps_num = ft_itoa(game->fps);
	fps_str = ft_strjoin("FPS: ", fps_num);
	mlx_string_put(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr, LENGTH - 100, 20,
				   0xFFFFFF, fps_str);
	free(fps_num);
	free(fps_str);
}

void count_fps(t_game *game)
{
	time_t current_time;
	game->frame_count++;
	current_time = time(NULL);
	if (current_time != game->last_time)
	{
		game->fps = game->frame_count;
		game->frame_count = 0;
		game->last_time = current_time;
	}
}

static void move_player(t_game *game)
{
	if (game->keys.w || game->keys.up)
		move_forward(game);
	if (game->keys.s || game->keys.down)
		move_backward(game);
	if (game->keys.a || game->keys.left)
		strafe_left(game);
	if (game->keys.d || game->keys.right)
		strafe_right(game);
}

int environment(t_game *game)
{

	move_player(game);
	count_fps(game);
	calc_trigo_for_draw(game);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
							game->mlx_data->img.img_ptr, 0, 0);
	if (game->show_minimap)
		draw_minimap(game, game->size_minimap + 5);
	else
		draw_minimap(game, game->size_minimap);
	draw_fps(game);
	return (0);
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
			return (cleanup(&parsing_data, 1, &game));
		mlx_hook(mlx_data.win_ptr, 17, 0, (int (*)())close_window, &game);
		mlx_hook(mlx_data.win_ptr, KeyPress, KeyPressMask,
				 (int (*)())handle_keypress, &game);
		mlx_hook(mlx_data.win_ptr, KeyRelease, KeyReleaseMask,
				 (int (*)())handle_keyrelease, &game);
		mlx_hook(mlx_data.win_ptr, MotionNotify, PointerMotionMask,
				 mouse_handler, &game);
		mlx_loop_hook(mlx_data.mlx_ptr, environment, &game);
		mlx_loop(mlx_data.mlx_ptr);
	}
	return (cleanup(NULL, 0, &game));
}
