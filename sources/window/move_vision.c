/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:16:47 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 17:43:33 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "window.h"

void	see_to_the_left(t_game *game)
{
	game->player->deg -= SENSITIVITY * 50;
}

void	see_to_the_right(t_game *game)
{
	game->player->deg += SENSITIVITY * 50;
}
