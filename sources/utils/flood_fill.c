/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:44:04 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/16 14:12:00 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "free_malloc.h"
#include "stdlib.h"

int	flood_fill_iterative_loop(char **map, t_flood_fill_data *ff)
{
	t_point	p;

	if (ff->rear + 4 >= ff->max_size)
		return (free_return(ff->queue, 0));
	p = ff->queue[(ff->front)++];
	if (p.y < 0 || p.x < 0 || !map[p.y] || !map[p.y][p.x])
		return (free_return(ff->queue, 0));
	if (map[p.y][p.x] == '1' || map[p.y][p.x] == 'V' || map[p.y][p.x] == ' ')
		return (1);
	if (map[p.y][p.x] == '\n' || map[p.y][p.x] == '\0')
		return (free_return(ff->queue, 0));
	map[p.y][p.x] = 'V';
	ff->queue[(ff->rear)++] = (t_point){p.x + 1, p.y};
	ff->queue[(ff->rear)++] = (t_point){p.x - 1, p.y};
	ff->queue[(ff->rear)++] = (t_point){p.x, p.y + 1};
	ff->queue[(ff->rear)++] = (t_point){p.x, p.y - 1};
	return (2);
}

int	flood_fill_iterative(char **map, t_parsing_data *parsing_data)
{
	t_flood_fill_data	ff;
	int					result;

	result = 0;
	ff.max_size = (parsing_data->map_height * parsing_data->map_width) * 4;
	ff.queue = ft_calloc(sizeof(t_point), ff.max_size);
	if (!ff.queue)
		return (0);
	ff.front = 0;
	ff.rear = 0;
	ff.queue[ff.rear++] = (t_point){parsing_data->player_x,
		parsing_data->player_y};
	while (ff.front < ff.rear)
	{
		result = flood_fill_iterative_loop(map, &ff);
		if (result == 0)
			return (0);
		if (result == 1)
			continue ;
	}
	free(ff.queue);
	return (1);
}
