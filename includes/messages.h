/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:14:22 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:06:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/* ************************************************************************** */
/*                          FILE & PARSING ERRORS                             */
/* ************************************************************************** */

# define INVALID_NAME "Error\nMake sure to use a .cub map\n"
# define OPEN_ERROR "Error\nFailed to open file\n"
# define MISSING_ALL "Error\nEmpty file\n"

/* ************************************************************************** */
/*                          TEXTURE ERRORS                                    */
/* ************************************************************************** */

# define TEXTURE_PATH "Error\nInvalid texture path\n"
# define MISSING_TEXTURE "Error\nMissing or invalid texture/color\n"
# define DUPLICATE_TEXTURE "Error\nTexture defined multiple times\n"

/* ************************************************************************** */
/*                          COLOR ERRORS                                      */
/* ************************************************************************** */

# define INVALID_FC "Error\nInvalid RGB for floor or ceiling\n"
# define WRONG_RGB "Error\nRGB value must be between 0 and 255\n"
# define DUPLICATE_FLOOR "Error\nFloor color defined multiple times\n"
# define DUPLICATE_CEILING "Error\nCeiling color defined multiple times\n"

/* ************************************************************************** */
/*                          MAP ERRORS                                        */
/* ************************************************************************** */

# define INVALID_MAP "Error\nMake sure to use a valid map\n"
# define MISSING_MAP "Error\nMake sure to have a map\n"
# define MAP_TOO_BIG "Error\nMap is too big\n"
# define MAP_TOO_SMALL "Error\nMap is too small (minimum 3x3)\n"
# define FLOOD_FILL "Error\nMap not closed by walls\n"
# define INVALID_CHAR "Error\nInvalid character in map\n"

/* ************************************************************************** */
/*                          PLAYER ERRORS                                     */
/* ************************************************************************** */

# define MULTI_PLAYER "Error\nCan only have one player per map\n"
# define NO_PLAYER "Error\nMap must contain exactly one player\n"

/* ************************************************************************** */
/*                          MEMORY ERRORS                                     */
/* ************************************************************************** */

# define MALLOC_ERR "Error\nMalloc failed\n"

/* ************************************************************************** */
/*                          ERROR HANDLING FUNCTION                           */
/* ************************************************************************** */

int	msg_error(char *str, int error);

#endif