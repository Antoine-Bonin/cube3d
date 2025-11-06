/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:14:22 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 18:11:32 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define INVALID_NAME "Error\nMake sure to use a .cub map\n"
# define MALLOC_ERR "Error\nMalloc failed\n"
# define INVALID_MAP "Error\nMake sure to use a valid map\n"
# define INVALID_FC "Error\nInvalid RGB for floor or ceiling\n"
# define MISSING_TEXTURE "Error\nMissing or invalid texture/color\n"
# define MISSING_MAP "Error\nMake sure to have a map\n"
# define MISSING_ALL "Error\nEmpty file\n"
# define MULTI_PLAYER "Error\nCan only have one player per map\n"
# define FLOOD_FILL "Error\nMap not closed by walls\n"
# define MAP_TOO_BIG "Error\nMap is too big\n"
# define WRONG_RGB "Error\nRGB value must be between 0 and 255\n"
# define TEXTURE_PATH "Error\nInvalid texture path\n"
# define INVALID_CHAR "Error\nInvalid character in map\n"
# define DUPLICATE_TEXTURE "Error\nTexture defined multiple times\n"
# define DUPLICATE_FLOOR "Error\nFloor color defined multiple times\n"
# define DUPLICATE_CEILING "Error\nCeiling color defined multiple times\n"
# define OPEN_ERROR "Error\nFailed to open file\n"
# define NO_PLAYER "Error\nMap must contain exactly one player\n"
# define MAP_TOO_SMALL "Error\nMap is too small (minimum 3x3)\n"

int	msg_error(char *str, int error);

#endif