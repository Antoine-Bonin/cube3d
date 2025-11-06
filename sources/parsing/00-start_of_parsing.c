/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-start_of_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:16:43 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 15:22:47 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "messages.h"

int	start_of_parsing(char *FileName, t_parsing_data *data, t_mlx_data *mlx_data)
{
	if (!is_file_name_correct(FileName))
		return (msg_error(INVALID_NAME, 1));
	if (!parse_cub_file(FileName, data))
		return (1);
	if (!floor_ceiling_color_valid(data))
		return (1);
	if (texture_to_mlx(data, mlx_data))
		return (1);
	if (!is_map_valid(data))
		return (1);
	return (0);
}