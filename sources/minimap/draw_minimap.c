/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:36:58 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 17:41:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "minimap.h"
#include "mlx.h"

#define MIN_TILE_SIZE 6
#define MAX_MINIMAP_SIZE 200

static int	calculate_tile_size(t_game *game)
{
	int	pixel_width;
	int	pixel_height;
	int	tile_size;

	pixel_width = MAX_MINIMAP_SIZE / (game->map_width - 1);
	pixel_height = MAX_MINIMAP_SIZE / game->map_height;
	if (pixel_width < pixel_height)
		tile_size = pixel_width;
	else
		tile_size = pixel_height;
	if (tile_size < MIN_TILE_SIZE)
		tile_size = MIN_TILE_SIZE;
	return (tile_size);
}

static void	copy_tile_to_buffer(char *dest, char *src, int pixel, t_img *buffer)
{
	int				y;
	int				x;
	unsigned int	*dst_pixel;
	unsigned int	*src_pixel;

	y = 0;
	while (y < pixel)
	{
		x = 0;
		while (x < pixel)
		{
			dst_pixel = (unsigned int *)(dest + (y * buffer->line_length + x
						* (buffer->bits_per_pixel / 8)));
			src_pixel = (unsigned int *)(src + (y * pixel * 4 + x * 4));
			*dst_pixel = *src_pixel;
			x++;
		}
		y++;
	}
}

static void	draw_tile_to_buffer(t_game *game, int map_x, int map_y, int pixel)
{
	int		index;
	void	*tile_img;
	char	*tile_data;
	char	*buffer_pos;
	int		info[3];

	index = find_index(game->map[map_y][map_x].type);
	if (index < 0 || index >= END)
		return ;
	if (index == PLAYER)
		index = FLOOR;
	tile_img = game->mlx_data->minimap_img[index];
	if (!tile_img)
		return ;
	tile_data = mlx_get_data_addr(tile_img, &info[1], &info[0], &info[2]);
	buffer_pos = game->mlx_data->map_buf.addr + (map_y * pixel
			* game->mlx_data->map_buf.line_length) + (map_x * pixel
			* (game->mlx_data->map_buf.bits_per_pixel / 8));
	copy_tile_to_buffer(buffer_pos, tile_data, pixel, &game->mlx_data->map_buf);
}

void	create_minimap_buffer(t_game *g)
{
	int	pixel;
	int	map_x;
	int	map_y;

	pixel = calculate_tile_size(g);
	if (g->mlx_data->minimap_tile_size != pixel)
		recreate_minimap_images(g, pixel);
	if (g->mlx_data->minimap_buffer_created)
		mlx_destroy_image(g->mlx_data->mlx_ptr,
			g->mlx_data->map_buf.img_ptr);
	g->mlx_data->map_buf.img_ptr = mlx_new_image(g->mlx_data->mlx_ptr,
			(g->map_width - 1) * pixel, g->map_height * pixel);
	g->mlx_data->map_buf.addr = mlx_get_data_addr(g->mlx_data->map_buf.img_ptr,
			&g->mlx_data->map_buf.bits_per_pixel,
			&g->mlx_data->map_buf.line_length,
			&g->mlx_data->map_buf.endian);
	map_y = -1;
	while (++map_y < g->map_height)
	{
		map_x = -1;
		while (++map_x < g->map_width - 1)
			draw_tile_to_buffer(g, map_x, map_y, pixel);
	}
	g->mlx_data->minimap_buffer_created = true;
}

void	draw_minimap(t_game *game)
{
	int	player_x;
	int	player_y;
	int	tile_size;
	int	player_img_size;

	tile_size = calculate_tile_size(game);
	player_img_size = tile_size / 3;
	player_x = 18 + (game->player->pos_x * tile_size) - (player_img_size / 2);
	player_y = 18 + (game->player->pos_y * tile_size) - (player_img_size / 2);
	if (!game->mlx_data->minimap_buffer_created)
		create_minimap_buffer(game);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->map_buf.img_ptr, 20, 20);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->minimap_img[PLAYER], player_x, player_y);
}
