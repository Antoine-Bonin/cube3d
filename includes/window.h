/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:15:48 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/18 13:29:56 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "structures.h"

int	init_window_and_textures(t_parsing_data *game, t_mlx_data *mlx_data);

int	close_window(t_game *game);

int	handle_keypress(int keycode, t_game *game);

#endif