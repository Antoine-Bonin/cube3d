/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wich_minimap_to_use.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:52:56 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/21 19:55:11 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	choose_which_minimap_to_draw(t_game *game)
{
	if (game->show_minimap && (game->map_width >= 80 || game->mlx_data->img.img_height >= 80))
		draw_minimap_big_map(game);
	else if (game->show_minimap && (game->map_width < 80
			&& game->mlx_data->img.img_height < 80))
		draw_minimap(game);
}
