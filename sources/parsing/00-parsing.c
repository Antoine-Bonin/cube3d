/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:16:43 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/18 13:19:17 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "messages.h"

int	parsing(char *FileName, t_parsing_data *parsing_data)
{
	if (!is_file_name_correct(FileName))
		return (msg_error(INVALID_NAME, 0));
	if (!parse_cub_file(FileName, parsing_data))
		return (0);
	if (!floor_ceiling_color_valid(parsing_data))
		return (0);
	if (!is_map_valid(parsing_data))
		return (0);
	return (1);
}
