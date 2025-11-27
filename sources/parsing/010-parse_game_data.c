/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010-parse_game_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:06 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 16:17:13 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

void	get_player_data(t_player *player, t_parsing_data *parsing)
{
	player->pos_x = (double)parsing->player_x + 0.5;
	player->pos_y = (double)parsing->player_y + 0.5;
	if (parsing->player_direction == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->fov_x = 0.0;
		player->fov_y = 0.66;
	}
	if (parsing->player_direction == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->fov_x = 0.0;
		player->fov_y = -0.66;
	}
	if (parsing->player_direction == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->fov_x = 0.66;
		player->fov_y = 0.0;
	}
	if (parsing->player_direction == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->fov_x = -0.66;
		player->fov_y = 0.0;
	}
	player->jumping = false;
	player->move_speed = 0.4;
}

int	parse_game_data(t_game *game, t_parsing_data *parsing)
{
	game->map = parse_map_tile(parsing->map, parsing->map_height, -1, -1);
	if (!game->map)
		return (msg_error(MALLOC_ERR, 0));
	game->player = (t_player *)malloc(sizeof(t_player));
	if (!game->player)
		return (msg_error(MALLOC_ERR, 0));
	get_player_data(game->player, parsing);
	game->map_height = parsing->map_height;
	game->map_width = parsing->map_width;
	game->floor_color = (parsing->floor_color[0] << 16) | (parsing->floor_color[1] << 8) | parsing->floor_color[2];
	game->ceiling_color = (parsing->ceiling_color[0] << 16) | (parsing->ceiling_color[1] << 8) | parsing->ceiling_color[2];
	free_parsing(parsing);
	return (1);
}
