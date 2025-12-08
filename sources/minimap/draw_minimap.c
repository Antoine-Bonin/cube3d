/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:46:46 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/08 11:30:49 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "minimap.h"
#include "mlx.h"

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

void	draw_tile(t_game *game, t_minimap_render *render, int map_x, int map_y)
{
	void	*img;
	int		screen_x;
	int		screen_y;

	screen_x = render->offset_x + ((map_x - (render->player_x
					- render->view_range)) * render->pixel);
	screen_y = render->offset_y + ((map_y - (render->player_y
					- render->view_range)) * render->pixel);
	if (game->map[map_y][map_x].type == '1')
		img = game->mlx_data->minimap_wall_img;
	else if (game->map[map_y][map_x].type == '0')
		img = game->mlx_data->minimap_floor_img;
	else if (game->map[map_y][map_x].type == ' ')
		img = game->mlx_data->minimap_empty_img;
	else
		return ;
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		img, screen_x, screen_y);
}

void	draw_background(t_game *game, t_minimap_render *render)
{
	int	x;
	int	y;
	int	size;

	size = render->view_range * 2 + 1;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_image_to_window(game->mlx_data->mlx_ptr,
				game->mlx_data->win_ptr, game->mlx_data->minimap_floor_img,
				render->offset_x + x * render->pixel, render->offset_y + y
				* render->pixel);
			x++;
		}
		y++;
	}
}

void	init_minimap_render(t_minimap_render *render, t_game *game,
		int view_range)
{
	render->view_range = view_range;
	render->offset_x = 0;
	render->offset_y = 0;
	render->player_x = (int)game->player->pos_x;
	render->player_y = (int)game->player->pos_y;
	if (LENGTH < HEIGHT)
		render->pixel = (LENGTH / 4) / (view_range * 2 + 1);
	else
		render->pixel = (HEIGHT / 4) / (view_range * 2 + 1);
}

void	draw_minimap(t_game *game, int view_range)
{
	t_minimap_render	render;
	int					map_x;
	int					map_y;

	init_minimap_render(&render, game, view_range);
	if (game->mlx_data->minimap_tile_size != render.pixel)
		recreate_minimap_images(game, render.pixel);
	draw_background(game, &render);
	map_y = render.player_y - view_range;
	while (map_y <= render.player_y + view_range)
	{
		map_x = render.player_x - view_range;
		while (map_x <= render.player_x + view_range)
		{
			if (map_x >= 0 && map_x < game->map_width && map_y >= 0
				&& map_y < game->map_height)
				draw_tile(game, &render, map_x, map_y);
			map_x++;
		}
		map_y++;
	}
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->minimap_player_img, render.offset_x + (view_range
			* render.pixel) + render.pixel / 4, render.offset_y + (view_range
			* render.pixel) + render.pixel / 4);
}
