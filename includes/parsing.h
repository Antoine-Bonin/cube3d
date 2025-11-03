/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:20 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/03 18:53:40 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
# define PARSING_HPP

typedef struct parsing_data
{
	char	**map;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	south;
	char	north;
    char    west;
    char    east;
};

#endif