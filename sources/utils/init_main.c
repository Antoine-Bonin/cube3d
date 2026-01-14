/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:12:34 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:13:14 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

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
