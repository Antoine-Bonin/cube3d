/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08-check_char_map_validity.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:07:04 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/13 15:15:00 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"
#include "parsing.h"

int	is_different_char_from(char c)
{
	return (c != 'N' && c != 'W' && c != 'E' && c != 'S' && c != '0' && c != ' '
		&& c != '1' && c != '\0' && c != '\n' && c != 'V');
}

int	find_invalid_char(t_parsing_data *parsing_data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (parsing_data->map)
	{
		while (parsing_data->map[x])
		{
			y = 0;
			while (parsing_data->map[x][y])
			{
				if (is_different_char_from(parsing_data->map[x][y]))
					return (1);
				y++;
			}
			x++;
		}
	}
	return (0);
}
