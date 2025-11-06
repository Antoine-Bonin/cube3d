/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-check_cub_filename.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:46 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 15:21:20 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "messages.h"
#include "mlx.h"
#include "parsing.h"
#include "stdlib.h"

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
