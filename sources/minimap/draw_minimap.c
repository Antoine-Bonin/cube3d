/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:46:46 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/06 11:59:25 by antbonin         ###   ########.fr       */
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
	if (index == PLAYER)
		return ;
	if (index < 0 || index >= END)
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

/*
 /2 character

For y dived by 16 = to the left,
 and by 2 to the right, 4 in the middle

for X divided by 16 = to the top
 and by 2 to the bottom, 4 in the middle

 /4 character :

 divided per 3 for the middle
 for x divided by 1.3 to the bottom and 30 for top
 for y dived by 30 for left and 1.3 to the right

 */
