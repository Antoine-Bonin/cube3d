/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:20 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 11:17:03 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define INVALID_NAME "Error\nMake sure to use a .cub map\n"
# define MALLOC_ERR "Error\nMalloc failed\n"
# define INVALID_MAP "Error\nMake sure to use a valid map\n"
# define INVALID_FC "Eror\nMake sure to use valid rgb for floor and ceiling\n"
# define MISSING_TEXTURE "Error\nMake sure to use NO, SO, EA and WE textures\n"
# define MISSING_MAP "Error\nMake sure to have a map\n"
# define MISSING_ALL "Error\nDon't make me parse an empty file next time\n"

# include "structures.h"

int	start_of_parsing(char *fileName, t_parsing_data *data);
int	parse_cub_file(char *filename, t_parsing_data *data);
int	parse_textures_cub(char *line, t_parsing_data *data);
int	get_color_in_data(int *color, char *line);
int	parse_map_line(char *line, t_parsing_data *data);

#endif