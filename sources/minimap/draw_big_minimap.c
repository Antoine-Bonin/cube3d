/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_big_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:38:42 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/09 10:52:29 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "minimap.h"
#include "mlx.h"

static void	draw_tile(t_game *game, t_minimap_render *render, int map_x,
		int map_y)
{
	void	*img;
	int		screen_x;
	int		screen_y;
	int		index;

	screen_x = render->offset_x + ((map_x - (render->player_x
					- render->view_range)) * render->pixel);
	screen_y = render->offset_y + ((map_y - (render->player_y
					- render->view_range)) * render->pixel);
	index = find_index(game->map[map_y][map_x].type);
	if (index < 0 || index >= END)
		return ;
	if (index == PLAYER)
		return ;
	img = game->mlx_data->minimap_img[index];
	if (!img)
		return ;
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		img, screen_x, screen_y);
}

static void	draw_background(t_game *game, t_minimap_render *render)
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
				game->mlx_data->win_ptr, game->mlx_data->minimap_img[FLOOR],
				render->offset_x + x * render->pixel, render->offset_y + y
				* render->pixel);
			x++;
		}
		y++;
	}
}

static void	init_minimap_render(t_minimap_render *render, t_game *game,
		int view_range)
{
	int	minimap_size;

	render->view_range = view_range;
	render->player_x = (int)game->player->pos_x;
	render->player_y = (int)game->player->pos_y;
	if (LENGTH < HEIGHT)
		minimap_size = LENGTH * 3 / 3.5;
	else
		minimap_size = HEIGHT * 3 / 3.5;
	render->pixel = minimap_size / (view_range * 2 + 1);
	render->offset_x = (LENGTH - minimap_size) / 2;
	render->offset_y = (HEIGHT - minimap_size) / 2;
}

void	draw_big_minimap(t_game *game, int view_range)
{
	t_minimap_render	render;
	int					map_x;
	int					map_y;

	init_minimap_render(&render, game, view_range);
	if (game->mlx_data->minimap_tile_size != render.pixel)
		recreate_minimap_images(game, render.pixel, -1);
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
		game->mlx_data->minimap_img[PLAYER], render.offset_x + (view_range
			* render.pixel) + render.pixel / 4, render.offset_y + (view_range
			* render.pixel) + render.pixel / 4);
}
