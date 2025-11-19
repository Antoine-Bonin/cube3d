/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010-parse_game_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:06 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 15:28:21 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
#include "parsing.h"

int	parse_game_data(t_game *game, t_parsing_data *parsing)
{
	game->map = parse_map_tile(parsing->map, parsing->map_height, -1,
			-1);
	if (!game->map)
		return (msg_error(MALLOC_ERR, 0));
	game->map_height = parsing->map_height;
	game->map_width = parsing->map_width;
	game->floor_color = (parsing->floor_color[0] << 16)
		| (parsing->floor_color[1] << 8) | parsing->floor_color[2];
	game->ceiling_color = (parsing->ceiling_color[0] << 16)
		| (parsing->ceiling_color[1] << 8) | parsing->ceiling_color[2];
	free_parsing(parsing);
	return (1);
}
