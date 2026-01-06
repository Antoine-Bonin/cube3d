/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010-parse_game_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:06 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/05 19:22:11 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

void get_player_data(t_player *player, t_parsing_data *parsing)
{
	player->pos_x = (double)parsing->player_x + 0.5;
	player->pos_y = (double)parsing->player_y + 0.5;
	if (parsing->player_direction == 'E')
		player->direction = EAST;
	else if (parsing->player_direction == 'W')
		player->direction = WEST;
	else if (parsing->player_direction == 'N')
		player->direction = NORTH;
	else if (parsing->player_direction == 'S')
		player->direction = SOUTH;
	player->jumping = false;
	player->move_speed = 0.4;
}

int parse_game_data(t_game *game, t_parsing_data *parsing)
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
	game->floor_color.value = (parsing->floor_color[0] << 16) | (parsing->floor_color[1] << 8) | parsing->floor_color[2];
	game->ceiling_color.value = (parsing->ceiling_color[0] << 16) | (parsing->ceiling_color[1] << 8) | parsing->ceiling_color[2];
	free_parsing(parsing);
	return (1);
}
