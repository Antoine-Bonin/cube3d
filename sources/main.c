/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/13 17:22:16 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "free_malloc.h"
#include "init.h"
#include "libft.h"
#include "minimap.h"
#include "mlx.h"
#include "parsing.h"
#include "stdio.h"
#include "stdlib.h"
#include "tile.h"
#include "window.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	init_parsing_data(t_parsing_data *parsing_data)
{
	int	i;

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

void	init_mlx(t_mlx_data *mlx_data)
{
	int	i;

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
	mlx_data->map_buf.img_ptr = NULL;
	mlx_data->minimap_buffer_created = false;
}

void	init_game(t_game *game, t_mlx_data *data)
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
	game->keys.q = false;
	game->keys.left = false;
	game->keys.right = false;
	game->frame_count = 0;
	game->last_time_ms = 0;
	game->for_speed_last_time_ms = 0;
	game->fps = 0;
	game->param_draw.orientation_vert = 0;
}

int	environment(t_game *game)
{
	move_player(game);
	count_fps(game);
	calc_trigo_for_draw(game);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->img.img_ptr, 0, 0);
	if (game->show_minimap)
		draw_minimap(game);
	draw_fps(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_parsing_data	parsing_data;
	t_mlx_data		mlx_data;
	t_game			game;

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
		mlx_hook(mlx_data.win_ptr, 6, 1L << 6, mouse_handler, &game);
		mlx_loop_hook(mlx_data.mlx_ptr, environment, &game);
		mlx_loop(mlx_data.mlx_ptr);
	}
	return (cleanup(NULL, 0, &game));
}
