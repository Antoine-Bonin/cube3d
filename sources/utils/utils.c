/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:40:30 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/21 19:38:14 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

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

int	color_argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
    t_argb	color;

    color.argb.a = a;
    color.argb.r = r;
    color.argb.g = g;  // Attention : dans votre struct c'est 'b' en 3e position
    color.argb.b = b;  // Attention : dans votre struct c'est 'g' en 4e position
    return (color.value);
}

int	find_index(char type)
{
	int	i;

	i = 0;
	if (type == 'N' || type == 'S' || type == 'E' || type == 'W')
		return (find_index('P'));
	else
	{
		while (g_type_index[i] != '\0')
		{
			if (g_type_index[i] == type)
				return (i);
			i++;
		}
	}
	return (-1);
}
