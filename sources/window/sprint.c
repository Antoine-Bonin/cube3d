/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:10:55 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/16 16:27:23 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sys/time.h"
#include "window.h"

void	sprint(t_game *game)
{
	struct timeval	tv;
	long			current_time_ms;

	gettimeofday(&tv, NULL);
	current_time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (game->keys.q)
	{
		if (current_time_ms - game->for_speed_last_time_ms >= 50)
		{
			if (game->player->move_speed < game->player->sprint_speed)
				game->player->move_speed += 0.05;
			game->for_speed_last_time_ms = current_time_ms;
		}
	}
	else
	{
		if (current_time_ms - game->for_speed_last_time_ms >= 100)
		{
			if (game->player->move_speed > game->player->base_speed)
				game->player->move_speed -= 0.02;
			else
				game->player->move_speed = game->player->base_speed;
			game->for_speed_last_time_ms = current_time_ms;
		}
	}
}
