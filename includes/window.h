/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:15:48 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/08 15:36:35 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "structures.h"

int	init_wdwimg_and_textures(t_parsing_data *game, t_mlx_data *mlx_data);

int	close_window(t_game *data);

int	handle_keypress(int keycode, t_game *data);
int	handle_keyrelease(int keycode, t_game *data);
int	move_forward(t_game *game);
int	move_backward(t_game *game);
int	strafe_left(t_game *game);
int	strafe_right(t_game *game);

#endif