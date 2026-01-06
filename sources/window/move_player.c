/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:33:59 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/06 11:35:41 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <math.h>

int	check_collision(t_game *game, int x, int y)
{
	if (game->map[y][x].is_solid)
		return (1);
	return (0);
}

int	move_forward(t_game *game)
{
    double	new_x;
    double	new_y;
    double	rad;

    rad = game->player->deg * (M_PI / 180.0);
    new_x = game->player->pos_x + cos(rad) * game->player->move_speed;
    new_y = game->player->pos_y + sin(rad) * game->player->move_speed;
    
    if (!check_collision(game, new_x, new_y))
    {
        game->player->pos_x = new_x;
        game->player->pos_y = new_y;
        return (0);
    }
    return (1);
}

int	move_backward(t_game *game)
{
    double	new_x;
    double	new_y;
    double	rad;

    rad = game->player->deg * (M_PI / 180.0);
    new_x = game->player->pos_x - cos(rad) * game->player->move_speed;
    new_y = game->player->pos_y - sin(rad) * game->player->move_speed;
    
    if (!check_collision(game, new_x, new_y))
    {
        game->player->pos_x = new_x;
        game->player->pos_y = new_y;
        return (0);
    }
    return (1);
}

int	strafe_left(t_game *game)
{
    double	new_x;
    double	new_y;
    double	rad;

    rad = (game->player->deg - 90) * (M_PI / 180.0);  // 90° à gauche
    new_x = game->player->pos_x + cos(rad) * game->player->move_speed;
    new_y = game->player->pos_y + sin(rad) * game->player->move_speed;
    
    if (!check_collision(game, new_x, new_y))
    {
        game->player->pos_x = new_x;
        game->player->pos_y = new_y;
        return (0);
    }
    return (1);
}

int	strafe_right(t_game *game)
{
    double	new_x;
    double	new_y;
    double	rad;

    rad = (game->player->deg + 90) * (M_PI / 180.0);  // 90° à droite
    new_x = game->player->pos_x + cos(rad) * game->player->move_speed;
    new_y = game->player->pos_y + sin(rad) * game->player->move_speed;
    
    if (!check_collision(game, new_x, new_y))
    {
        game->player->pos_x = new_x;
        game->player->pos_y = new_y;
        return (0);
    }
    return (1);
}
