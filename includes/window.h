/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:15:48 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:08:19 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "structures.h"

/* ************************************************************************** */
/*                              CONFIGURATION                                 */
/* ************************************************************************** */

# define SENSITIVITY 0.02

/* ************************************************************************** */
/*                          INITIALIZATION & CLEANUP                          */
/* ************************************************************************** */

int		init_wdwimg_and_textures(t_parsing_data *game, t_mlx_data *mlx_data);
int		close_window(t_game *data);

/* ************************************************************************** */
/*                             INPUT HANDLING                                 */
/* ************************************************************************** */

int		handle_keypress(int keycode, t_game *data);
int		handle_keyrelease(int keycode, t_game *data);
int		mouse_handler(int x, int y, t_game *game);

/* ************************************************************************** */
/*                          PLAYER MOVEMENT                                   */
/* ************************************************************************** */

void	move_player(t_game *game);
int		move_forward(t_game *game);
int		move_backward(t_game *game);
int		strafe_left(t_game *game);
int		strafe_right(t_game *game);
void	sprint(t_game *game);

/* ************************************************************************** */
/*                          CAMERA ROTATION                                   */
/* ************************************************************************** */

void	see_to_the_left(t_game *game);
void	see_to_the_right(t_game *game);

/* ************************************************************************** */
/*                          PERFORMANCE & UI                                  */
/* ************************************************************************** */

void	count_fps(t_game *game);
void	draw_fps(t_game *game);

#endif