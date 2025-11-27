/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07-check_floor_ceiling_color.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:13:32 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 15:25:22 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"
#include "parsing.h"

int	floor_ceiling_color_valid(t_parsing_data *parsing_data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((parsing_data->floor_color[i] > 255
				|| parsing_data->floor_color[i] < 0)
			|| (parsing_data->ceiling_color[i] < 0
				|| parsing_data->ceiling_color[i] > 255))
			return (msg_error(WRONG_RGB, 0));
		i++;
	}
	return (1);
}
