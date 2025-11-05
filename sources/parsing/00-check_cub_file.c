/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-check_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:46 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 11:06:11 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "messages.h"
#include "parsing.h"
#include "stdlib.h"

bool	is_file_name_correct(char *map)
{
	size_t	map_len;

	map_len = ft_strlen(map);
	if (map_len < 5)
		return (0);
	if (map[map_len - 3] == 'c' && map[map_len - 2] == 'u' && map[map_len
			- 1] == 'b')
		return (1);
	return (0);
}

int	start_of_parsing(char *FileName, t_parsing_data *data)
{
	if (!is_file_name_correct(FileName))
		return (msg_error(INVALID_NAME, 1));
	if (parse_cub_file(FileName, data))
		return (1);
	// if (!valid_map(data->map))
	// 	return (1);
	return (0);
}
