/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:47:52 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/13 14:05:15 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define CONTRAST 255

# include "structures.h"

void	draw_minimap(t_game *game);
void	recreate_minimap_images(t_game *game, int size);
void	create_minimap_buffer(t_game *game);

#endif