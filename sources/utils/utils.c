/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:40:30 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/11 16:55:46 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"

const char		type_index[] = {'0', '1', ' ', 'P', '\n', '\0'};
const t_tile	type_block[] = {
{.color_mini_map = {164, 162, 162}, .is_player = 0, .is_solid = 0,
	.is_transparent = 0, .type = '0'},
{.color_mini_map = {255, 255, 255}, .is_player = 0, .is_solid = 1,
	.is_transparent = 0, .type = '1'},
{.color_mini_map = {0, 0, 0}, .is_player = 0, .is_solid = 1,
	.is_transparent = 0, .type = ' '},
{.color_mini_map = {255, 0, 0}, .is_player = 1, .is_solid = 0,
	.is_transparent = 0, .type = 'P'},
{.color_mini_map = {164, 162, 162}, .is_player = 0, .is_solid = 0,
	.is_transparent = 1, .type = '\n'},
{.color_mini_map = {0, 0, 0}, .is_player = 0, .is_solid = 1,
	.is_transparent = 1, .type = '\0'},
};

int	color_argb(int a, int r, int g, int b)
{
	return (a * 16777216 + r * 65536 + g * 256 + b);
}

int	find_index(char type)
{
	int	i;

	i = 0;
	if (type == 'N' || type == 'S' || type == 'E' || type == 'W')
		return (find_index('P'));
	else
	{
		while (type_index[i] != '\0')
		{
			if (type_index[i] == type)
				return (i);
			i++;
		}
	}
	return (-1);
}
