/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:18:10 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/13 15:14:28 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_H
# define TILE_H

typedef enum s_type
{
	FLOOR,
	VOID,
	WALL,
	HOLE,
	PLAYER,
	END,
	MAX
}	t_type;

int	find_index(char s);

#endif