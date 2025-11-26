/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:44 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/26 15:54:10 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "stdbool.h"

typedef struct	s_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				exit;
	t_data 			img;
	void			*north_mlx_ptr;
	void			*south_mlx_ptr;
	void			*west_mlx_ptr;
	void			*east_mlx_ptr;
	int				img_width;
	int				img_height;
}					t_mlx_data;


typedef struct s_parsing_data
{
	char			*north_texture_path;
	char			*south_texture_path;
	char			*west_texture_path;
	char			*east_texture_path;
	int				floor_color[3];
	int				ceiling_color[3];
	char			**map;
	int				map_height;
	int				map_width;
	bool			textures_complete;
	int				player_x;
	int				player_y;
	char			player_direction;
	bool			dup_found;
}					t_parsing_data;

typedef struct s_game
{
	t_mlx_data		*mlx_data;
	t_parsing_data	*parsing_data;
}					t_game;

#endif
