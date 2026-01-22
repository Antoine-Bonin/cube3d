/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_argb_minimap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:41:19 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 14:50:10 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "structures.h"

int	color_argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return ((a << 24) | (r << 16) | (g << 8) | b);
}
