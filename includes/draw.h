/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:07:12 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/13 18:01:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "structures.h"
# include <math.h>

int		calc_trigo_for_draw(t_game *game);
void	calc_init_for_ray(t_player *player, t_game *game);
void	check_block_by_block(t_dir for_x, t_dir for_y, t_game *game,
			double proj_to_screen);
t_dir	calc_direction(t_dir value, t_game *game, char x_or_y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		x_find_pixel_for_img(t_game *game, t_dir dda_point, int length);
int		resize_height(int value);
int		size_block_in_height(double proj_to_screen, t_dir dda, t_game *game);
double	deg_to_rad(double deg);
bool	block_is_solid(t_tile block);
double	delta_dist(double ray_dir);
void	draw(t_game *game, t_dir dda, t_compass compass, double proj_to_screen);
void	calc_player_to_intersection_x_or_y(t_dir for_x, t_dir for_y,
			t_game *game, double proj_to_screen);

#endif