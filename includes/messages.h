/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:14:22 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 14:14:24 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define INVALID_NAME "Error\nMake sure to use a .cub map\n"
# define MALLOC_ERR "Error\nMalloc failed\n"
# define INVALID_MAP "Error\nMake sure to use a valid map\n"
# define INVALID_FC "Eror\nMake sure to use valid rgb for floor and ceiling\n"
# define MISSING_TEXTURE "Error\nMake sure to have all fours NO,WE,SO,EA in the map file\n"
# define MISSING_MAP "Error\nMake sure to have a map\n"
# define MISSING_ALL "Error\nDon't make me parse an empty file next time\n"
# define MULTI_PLAYER "Error\nCan only have one player per map\n"
# define FLOOD_FILL "Error\nFlood fill failed make sur the player is surrounded by walls\n"
# define MAP_TO_BIG "Error\nMap is too big for us to handle sorry to let you down like that\n"
# define WRONG_RGB "Error\nMake sure to have an rgb value between 0 and 255\n"
# define TEXTURE_PATH "Error\nMake sure to use a valid path or the right to open the file\n"

int	msg_error(char *str, int error);

#endif