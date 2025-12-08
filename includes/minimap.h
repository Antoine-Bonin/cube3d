/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:47:52 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/08 11:30:57 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "structures.h"

typedef struct s_minimap_render
{
	int	pixel;
	int	view_range;
	int	offset_x;
	int	offset_y;
	int	player_x;
	int	player_y;
}		t_minimap_render;

void	init_minimap_render(t_minimap_render *render, t_game *game,
			int view_range);
void	draw_minimap(t_game *game, int view_range);
void	recreate_minimap_images(t_game *game, int size);

#endif