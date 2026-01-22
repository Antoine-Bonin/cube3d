/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:10:55 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 14:58:02 by antbonin         ###   ########.fr       */
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
		if (current_time_ms - game->render.movement_update_ms >= 50)
		{
			if (game->player->move.speed < game->player->move.sprint_speed)
				game->player->move.speed += 0.05;
			game->render.movement_update_ms = current_time_ms;
		}
	}
	else
	{
		if (current_time_ms - game->render.movement_update_ms >= 100)
		{
			if (game->player->move.speed > game->player->move.base_speed)
				game->player->move.speed -= 0.02;
			else
				game->player->move.speed = game->player->move.base_speed;
			game->render.movement_update_ms = current_time_ms;
		}
	}
}
