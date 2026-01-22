/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:08:34 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 14:33:21 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "stdlib.h"
#include "window.h"
#include <sys/time.h>

void	draw_fps(t_game *game)
{
	char	*fps_str;
	char	*fps_num;

	fps_num = ft_itoa(game->render.frame_count);
	if (!fps_num)
		return ;
	fps_str = ft_strjoin("FPS: ", fps_num);
	if (!fps_str)
	{
		free(fps_num);
		return ;
	}
	mlx_string_put(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr, LENGTH
		- 100, 20, 0xFFFFFF, fps_str);
	free(fps_num);
	free(fps_str);
}

void	count_fps(t_game *game)
{
	struct timeval	tv;
	long			current_time_ms;

	game->render.frame_count++;
	gettimeofday(&tv, NULL);
	current_time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (current_time_ms - game->render.last_frame_ms >= 1000)
	{
		game->render.current_fps = game->render.frame_count;
		game->render.frame_count = 0;
		game->render.last_frame_ms = current_time_ms;
	}
}
