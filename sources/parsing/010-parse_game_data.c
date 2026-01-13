/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010-parse_game_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:06 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/13 16:54:50 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"
#include "utils.h"

void	get_player_data(t_player *player, t_parsing_data *parsing)
{
	player->pos_x = (double)parsing->player_x + 0.5;
	player->pos_y = (double)parsing->player_y + 0.5;
	player->base_pos_x = player->pos_x;
	player->base_pos_y = player->pos_y;
	if (parsing->player_direction == 'E')
		player->direction = EAST;
	else if (parsing->player_direction == 'W')
		player->direction = WEST;
	else if (parsing->player_direction == 'N')
		player->direction = NORTH;
	else if (parsing->player_direction == 'S')
		player->direction = SOUTH;
	player->jumping = false;
	player->base_speed = 0.07;
	player->sprint_speed = 0.20;
	player->move_speed = player->base_speed;
}

int	parse_game_data(t_game *game, t_parsing_data *pars)
{
	game->map = parse_map_tile(pars->map, pars->map_height, -1,
			pars->map_width);
	if (!game->map)
		return (msg_error(MALLOC_ERR, 0));
	game->player = (t_player *)malloc(sizeof(t_player));
	if (!game->player)
		return (msg_error(MALLOC_ERR, 0));
	get_player_data(game->player, pars);
	game->map_height = pars->map_height;
	game->map_width = pars->map_width;
	game->floor_color.value = (pars->floor_color[0] << 16)
		| (pars->floor_color[1] << 8) | pars->floor_color[2];
	game->ceiling_color.value = (pars->ceiling_color[0] << 16)
		| (pars->ceiling_color[1] << 8) | pars->ceiling_color[2];
	free_parsing(pars);
	return (1);
}
