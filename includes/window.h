/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:15:48 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/27 15:58:06 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "structures.h"

int	init_wdwimg_and_textures(t_parsing_data *game, t_mlx_data *mlx_data);

int	close_window(t_game *data);

int	handle_keypress(int keycode, t_game *data);

#endif