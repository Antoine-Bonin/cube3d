/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:20 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 17:42:50 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "structures.h"

int		start_of_parsing(char *fileName, t_parsing_data *data, t_mlx_data *mlx_data);
int		parse_cub_file(char *filename, t_parsing_data *data);
int		parse_textures_cub(char *line, t_parsing_data *data);
int		get_color_in_data(int *color, char *line);
int		parse_map_line(char *line, t_parsing_data *data);
int		parse_cub_file_loop(int fd, t_parsing_data *data, char *line,
			bool *map_started);
char	**copy_map(char **map, int height);
int		flood_fill(char **map, int x, int y, t_parsing_data *data);
int		is_map_valid(t_parsing_data *data);

#endif