/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:48:18 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:07:36 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "init.h"
#include <X11/X.h>
#include "window.h"
#include "draw.h"
#include "minimap.h"
#include "mlx.h"

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
		mlx_data->graphics.textures[i].img_ptr = NULL;
	i = -1;
	while (++i < MAX)
		mlx_data->graphics.minimap_img[i] = NULL;
	mlx_data->mlx_ptr = NULL;
	mlx_data->win_ptr = NULL;
	mlx_data->graphics.screen.img_ptr = NULL;
	mlx_data->graphics.screen.img_width = 64;
	mlx_data->graphics.screen.img_height = 64;
	mlx_data->graphics.minimap_tile_size = 0;
	mlx_data->graphics.map_buf.img_ptr = NULL;
	mlx_data->graphics.minimap_buffer_created = false;
}

void	init_game(t_game *game, t_mlx_data *data)
{
	game->mlx_data = data;
	game->map.ceiling_color.value = 0;
	game->map.floor_color.value = 0;
	game->map.tiles = NULL;
	game->mlx_data->graphics.screen.img_height = 0;
	game->map.width = 0;
	game->map.height = 0;
	game->player = NULL;
	game->minimap.visible = false;
	game->minimap.size = 5;
	game->keys.w = false;
	game->keys.a = false;
	game->keys.s = false;
	game->keys.d = false;
	game->keys.q = false;
	game->keys.left = false;
	game->keys.right = false;
	game->render.frame_count = 0;
	game->render.last_frame_ms = 0;
	game->render.movement_update_ms = 0;
	game->render.current_fps = 0;
	game->render.params.orientation_vert = 0;
}

int	environment(t_game *game)
{
	move_player(game);
	calc_trigo_for_draw(game);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->graphics.screen.img_ptr, 0, 0);
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
