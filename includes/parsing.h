/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:50:20 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/16 14:07:59 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

/* ************************************************************************** */
/*                          MAIN PARSING                                      */
/* ************************************************************************** */

int		parsing(char *fileName, t_parsing_data *parsing_data);
int		parse_cub_file(char *filename, t_parsing_data *parsing_data);
int		parse_cub_file_loop(int fd, t_parsing_data *parsing_data, char *line,
			bool *map_started);

/* ************************************************************************** */
/*                          TEXTURE & COLOR PARSING                           */
/* ************************************************************************** */

int		parse_textures_cub(char *line, t_parsing_data *parsing_data);
int		get_color_in_data(int *color, char *line);
int		floor_ceiling_color_valid(t_parsing_data *parsing_data);

/* ************************************************************************** */
/*                          MAP PARSING & VALIDATION                          */
/* ************************************************************************** */

int		parse_map_line(char *line, t_parsing_data *parsing_data);
int		is_map_valid(t_parsing_data *parsing_data);
int		find_invalid_char(t_parsing_data *parsing_data);
int		is_different_char_from(char c);

/* ************************************************************************** */
/*                          FLOOD FILL ALGORITHM                              */
/* ************************************************************************** */

int		flood_fill_iterative(char **map, t_parsing_data *parsing_data);
char	**copy_map(char **map, int height);

/* ************************************************************************** */
/*                          DATA CONVERSION                                   */
/* ************************************************************************** */

t_tile	**parse_map_tile(char **map, int height, int y, int x);
int		parse_game_data(t_game *game, t_parsing_data *parsing_data);

/* ************************************************************************** */
/*                          FILE VALIDATION                                   */
/* ************************************************************************** */

bool	is_file_name_correct(char *map);

#endif