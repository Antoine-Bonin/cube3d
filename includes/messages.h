/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:14:22 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 16:49:27 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define INVALID_NAME "Error\nMake sure to use a .cub map\n"
# define MALLOC_ERR "Error\nMalloc failed\n"
# define INVALID_MAP "Error\nMake sure to use a valid map\n"
# define INVALID_FC "Eror\nMake sure to use valid rgb for floor and ceiling\n"
# define MISSING_TEXTURE "Error\nMake sure to have all textures/colors valid and they're before the map in the file\n"
# define MISSING_MAP "Error\nMake sure to have a map\n"
# define MISSING_ALL "Error\nDon't make me parse an empty file next time\n"
# define MULTI_PLAYER "Error\nCan only have one player per map\n"
# define FLOOD_FILL "Error\nFlood fill failed make sur the player is surrounded by walls\n"
# define MAP_TOO_BIG "Error\nMap is too big for us to handle sorry to let you down like that\n"
# define WRONG_RGB "Error\nMake sure to have an rgb value between 0 and 255\n"
# define TEXTURE_PATH "Error\nMake sure to use a valid path or the right to open the file\n"
# define INVALID_CHAR "Error\n only valid chars are 'S' 'N' 'W' 'E' '1' '0' and ' ' for the map\n"
# define DUPLICATE_TEXTURE "Error\nTexture is defined multiple times\n"
# define DUPLICATE_FLOOR "Error\nFloor color is defined multiple times\n"
# define DUPLICATE_CEILING "Error\nCeiling color is defined multiple times\n"
# define OPEN_ERROR "Error\n failed to open the file\n"
# define NO_PLAYER "Error\nMap must contain exactly one player N, S, E,or W\n"
# define MAP_TOO_SMALL "Error\nMap is too small (minimum 3x3)\n"
int	msg_error(char *str, int error);

#endif