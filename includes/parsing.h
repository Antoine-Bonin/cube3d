/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:20 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/18 13:12:34 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "structures.h"

int		parsing(char *fileName, t_parsing_data *parsing_data);
int		parse_cub_file(char *filename, t_parsing_data *parsing_data);
int		parse_textures_cub(char *line, t_parsing_data *parsing_data);
int		get_color_in_data(int *color, char *line);
int		parse_map_line(char *line, t_parsing_data *parsing_data);
int		parse_cub_file_loop(int fd, t_parsing_data *parsing_data, char *line,
			bool *map_started);
char	**copy_map(char **map, int height);
int		flood_fill(char **map, int x, int y, t_parsing_data *parsing_data);
int		is_map_valid(t_parsing_data *parsing_data);
int		is_different_char_from(char c);
int		find_invalid_char(t_parsing_data *parsing_data);
bool	is_file_name_correct(char *map);
int		floor_ceiling_color_valid(t_parsing_data *parsing_data);
#endif