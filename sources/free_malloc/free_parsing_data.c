/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:06 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 11:03:56 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "messages.h"
#include "stdlib.h"

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

int	error_cleanup(t_parsing_data *data, int error)
{
	if (data->ea_texture)
	{
		free(data->ea_texture);
		data->ea_texture = NULL;
	}
	if (data->no_texture)
	{
		free(data->no_texture);
		data->no_texture = NULL;
	}
	if (data->so_texture)
	{
		free(data->so_texture);
		data->so_texture = NULL;
	}
	if (data->we_texture)
	{
		free(data->we_texture);
		data->we_texture = NULL;
	}
	ft_free_tab(data->map);
	free(data);
	return (error);
}

int	malloc_error_parsing(t_parsing_data *data)
{
	if (data->ea_texture)
	{
		free(data->ea_texture);
		data->ea_texture = NULL;
	}
	if (data->no_texture)
	{
		free(data->no_texture);
		data->no_texture = NULL;
	}
	if (data->so_texture)
	{
		free(data->so_texture);
		data->so_texture = NULL;
	}
	if (data->we_texture)
	{
		free(data->we_texture);
		data->we_texture = NULL;
	}
	ft_free_tab(data->map);
	free(data);
	exit(1);
}
