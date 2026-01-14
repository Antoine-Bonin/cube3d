/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-check_cub_filename.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:46 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:21:50 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

bool	is_file_name_correct(char *map)
{
	int	map_len;

	map_len = ft_strlen(map);
	if (map_len < 5)
		return (0);
	if (map[map_len - 3] == 'c' && map[map_len - 2] == 'u' && map[map_len
			- 1] == 'b')
		return (1);
	return (0);
}
