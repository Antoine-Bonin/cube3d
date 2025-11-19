/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:06 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 15:25:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
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

int	error_cleanup(t_parsing_data *parsing_data, int error, t_mlx_data *mlx_data,
		t_game *game)
{
	if (parsing_data)
		free_parsing(parsing_data);
	if (mlx_data)
		free_mlx(mlx_data);
	if (game)
		free_game(game);
	return (error);
}

int	malloc_error_in_parsing_exit(t_parsing_data *parsing_data)
{
	free_parsing(parsing_data);
	exit(1);
}
