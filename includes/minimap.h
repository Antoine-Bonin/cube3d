/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:47:52 by antbonin          #+#    #+#             */
/*   Updated: 2025/12/07 19:30:54 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "structures.h"

void	draw_map(t_game *game);
void	init_minimap_images(t_game *game);
void	recreate_minimap_images(t_game *game, int size);

#endif