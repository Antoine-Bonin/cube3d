/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010-parse_game_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:06 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/06 10:16:07 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"
#include "utils.h"

void	get_player_direction_data(t_player *player, t_parsing_data *parsing)
{
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
}

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
	player->move_speed = 0.1;
}

int parse_game_data(t_game *game, t_parsing_data *parsing)
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
	game->floor_color = color_argb(0, pars->ceiling_color[0],
			pars->ceiling_color[1], pars->ceiling_color[2]);
	game->ceiling_color = color_argb(0, pars->ceiling_color[0],
			pars->ceiling_color[1], pars->ceiling_color[2]);
	free_parsing(pars);
	return (1);
}
