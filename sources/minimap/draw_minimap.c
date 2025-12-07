/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:46:46 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/07 19:55:31 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "mlx.h"
#include "init.h"

// void	draw_cell(t_game *game, int x, int y, int cell_size)
// {
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, x
// 		* cell_size, y * cell_size);
// 	if (game->map[y][x] == '1')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img, x
// 			* cell_size, y * cell_size);
// 	else if (game->map[y][x] == 'C')
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 			game->collectible_img, x * cell_size, y * cell_size);
// 	else if (game->map[y][x] == 'E')
// 	{
// 		if (game->collectibles_remaining == 0)
// 			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 				game->exit_img, x * cell_size, y * cell_size);
// 		else
// 			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 				game->door_open, x * cell_size, y * cell_size);
// 	}
// }

void	draw_tile(t_game *game, int map_x, int map_y, int screen_x, int screen_y)
{
	void	*img;

	if (game->map[map_y][map_x].type == '1')
		img = game->mlx_data->minimap_wall_img;
	else if (game->map[map_y][map_x].type == '0')
		img = game->mlx_data->minimap_floor_img;
	else if (game->map[map_y][map_x].type == ' ')
		img = game->mlx_data->minimap_empty_img;
	else
		return ;
	mlx_put_image_to_window(game->mlx_data->mlx_ptr,
		game->mlx_data->win_ptr, img, screen_x, screen_y);
}

void	draw_background(t_game *game, int size, int pixel)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_image_to_window(game->mlx_data->mlx_ptr,
				game->mlx_data->win_ptr, game->mlx_data->minimap_floor_img,
				10 + x * pixel, 10 + y * pixel);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	int	pixel;
	int	map_x;
	int	map_y;
	int	screen_idx;
	int	view_range;
	int	screen_x;
	int	screen_y;
	int	minimap_size;

	view_range = 5;
	if (LENGTH < HEIGHT)
		minimap_size = LENGTH / 4;
	else
		minimap_size = HEIGHT / 4;
	pixel = minimap_size / (view_range * 2 + 1);
	if (game->mlx_data->minimap_tile_size != pixel)
		recreate_minimap_images(game, pixel);
	draw_background(game, view_range * 2 + 1, pixel);
	map_y = (int)game->player->pos_y - view_range;
	screen_idx = 0;
	while (map_y <= (int)game->player->pos_y + view_range)
	{
		map_x = (int)game->player->pos_x - view_range;
		while (map_x <= (int)game->player->pos_x + view_range)
		{
			screen_x = 10 + ((map_x - ((int)game->player->pos_x - view_range))
					* pixel);
			screen_y = 10 + ((map_y - ((int)game->player->pos_y - view_range))
					* pixel);
			if (map_x >= 0 && map_x < game->map_width && map_y >= 0
				&& map_y < game->map_height)
				draw_tile(game, map_x, map_y, screen_x, screen_y);
			map_x++;
		}
		map_y++;
	}
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->minimap_player_img, 10 + (view_range * pixel)
		+ pixel / 4, 10 + (view_range * pixel) + pixel / 4);
}
