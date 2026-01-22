/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:06 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:22 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "stdlib.h"

void	free_and_set_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_tab(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
	}
}

int	malloc_error_in_parsing_exit(t_parsing_data *parsing_data)
{
	free_parsing(parsing_data);
	exit(1);
}

void	free_parsing(t_parsing_data *parsing_data)
{
	free_and_set_null(parsing_data->east_texture_path);
	free_and_set_null(parsing_data->north_texture_path);
	free_and_set_null(parsing_data->south_texture_path);
	free_and_set_null(parsing_data->west_texture_path);
	ft_free_tab(parsing_data->map);
}
