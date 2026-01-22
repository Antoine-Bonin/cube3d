/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:16:47 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:06:57 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "window.h"

void	see_to_the_left(t_game *game)
{
	game->player->deg -= SENSITIVITY * 50;
}

void	see_to_the_right(t_game *game)
{
	game->player->deg += SENSITIVITY * 50;
}
