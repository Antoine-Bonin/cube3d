/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:44:04 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:18:36 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "free_malloc.h"
#include "stdlib.h"
#define MAX_MAP_SIZE 16000000

int	flood_fill_iterative_loop(char **map, int *front, int *rear, t_point *queue)
{
	t_point	p;

	if (*rear + 4 >= MAX_MAP_SIZE)
		return (free_return(queue, 0));
	p = queue[(*front)++];
	if (p.y < 0 || p.x < 0 || !map[p.y] || !map[p.y][p.x])
		return (free_return(queue, 0));
	if (map[p.y][p.x] == '1' || map[p.y][p.x] == 'V' || map[p.y][p.x] == ' ')
		return (1);
	if (map[p.y][p.x] == '\n' || map[p.y][p.x] == '\0')
		return (free_return(queue, 0));
	map[p.y][p.x] = 'V';
	queue[(*rear)++] = (t_point){p.x + 1, p.y};
	queue[(*rear)++] = (t_point){p.x - 1, p.y};
	queue[(*rear)++] = (t_point){p.x, p.y + 1};
	queue[(*rear)++] = (t_point){p.x, p.y - 1};
	return (2);
}

int	flood_fill_iterative(char **map, int start_x, int start_y, int front)
{
	t_point	*queue;
	int		rear;
	int		result;

	result = 0;
	queue = ft_calloc(sizeof(t_point), MAX_MAP_SIZE);
	if (!queue)
		return (0);
	rear = 0;
	queue[rear++] = (t_point){start_x, start_y};
	while (front < rear)
	{
		result = flood_fill_iterative_loop(map, &front, &rear, queue);
		if (result == 0)
			return (0);
		if (result == 1)
			continue ;
	}
	free(queue);
	return (1);
}
