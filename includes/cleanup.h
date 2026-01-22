/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:21:31 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:10 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include "structures.h"

/* ************************************************************************** */
/*                          CLEANUP FUNCTIONS                                 */
/* ************************************************************************** */

int		cleanup(t_parsing_data *parsing_data, int error, t_game *mlx_data);
void	free_parsing(t_parsing_data *parsing_data);
void	free_mlx(t_mlx_data *mlx_data);
void	free_game(t_game *game);

/* ************************************************************************** */
/*                          MEMORY DEALLOCATION                               */
/* ************************************************************************** */

void	ft_free_tab(char **map);
t_tile	**free_map_tile(t_tile **map, int height);
void	free_and_set_null(void *ptr);

/* ************************************************************************** */
/*                          ERROR HANDLING                                    */
/* ************************************************************************** */

int		malloc_error_in_parsing_exit(t_parsing_data *parsing_data);
int		msg_error_and_free(char *str, int error, void *to_free);

#endif