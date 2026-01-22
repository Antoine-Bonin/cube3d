/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   013-tile_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:40:30 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 14:58:45 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

const char		g_type_index[] = {'0', '1', ' ', 'P', '\n', '\0'};
const t_tile	g_type_block[] = {
[FLOOR] = {.color_mini_map = {164, 162, 162}, .is_player = 0, .is_solid = 0,
	.is_transparent = 0, .type = '0'},
[WALL] = {.color_mini_map = {255, 255, 255}, .is_player = 0, .is_solid = 1,
	.is_transparent = 0, .type = '1'},
[HOLE] = {.color_mini_map = {255, 0, 0}, .is_player = 0, .is_solid = 0,
	.is_transparent = 0, .type = ' '},
[PLAYER] = {.color_mini_map = {255, 0, 0}, .is_player = 1, .is_solid = 0,
	.is_transparent = 0, .type = 'P'},
[END] = {.color_mini_map = {164, 162, 162}, .is_player = 0, .is_solid = 0,
	.is_transparent = 1, .type = '\n'},
[MAX] = {.color_mini_map = {0, 0, 0}, .is_player = 0, .is_solid = 1,
	.is_transparent = 1, .type = '\0'},
};
