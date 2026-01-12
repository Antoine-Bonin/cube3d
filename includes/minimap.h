/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:47:52 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/11 17:28:52 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define CONTRAST 255

# include "structures.h"

typedef struct s_minimap_render
{
	int	pixel;
	int	view_range;
	int	offset_x;
	int	offset_y;
}		t_minimap_render;

void	draw_minimap(t_game *game, int view_range);
void	draw_big_minimap(t_game *game, int view_range);
void	recreate_minimap_images(t_game *game, int size, int i);

#endif