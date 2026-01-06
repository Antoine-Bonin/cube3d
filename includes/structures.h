/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:44 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/06 10:15:28 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "stdbool.h"
# include <stdint.h>

typedef struct s_data
{
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

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

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_data			img;
	void			*textures[4];
	int				img_width;
	int				img_height;
	void			*minimap_img[MAX];
	int				minimap_tile_size;
}					t_mlx_data;



typedef struct s_tile
{
	char		type;
	bool		is_player;
	bool		is_solid;
	bool		is_transparent;
	double		floor_height;
	double		ceiling_height;
	int			map_x;
	int			map_y;
}				t_tile;
/*
t_tile mur =
{
	type = '1',
	is_solid = true,
	is_transparent = false,
	is_door = false,
	floor_height = 0.0,
	ceiling_height = 1.0,
};

// Trou traversable (on voit le vide)
t_tile			trou = {
	type = ' ',
	is_solid = false,
	is_transparent = true,
	is_door = false,
	floor_height = -1.0,  // Très bas
	ceiling_height = 0.0,
};

*/
typedef enum s_compass 
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FOG,
} t_compass;

typedef struct s_ray
{
	double raydir;
	double delta_dist;
} t_ray;

typedef struct s_dir
{
	t_ray ray;
	int steps;
	char x_or_y;
	bool positif;
	double side_dist;
	t_compass texture_use;
} t_dir;

typedef struct s_vec
{
	int pos_x;
	int pos_y;
} t_vec;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	int			pos_x_int;
	int			pos_y_int;
	t_compass		direction;
	t_vec		ray_limit;
	double		move_speed;
	bool		jumping;
	int			nb_ray;
	double 		deg;
}				t_player;

typedef struct s_game
{
	t_mlx_data	*mlx_data;
	t_player	*player;
	t_tile		**map;
	int			map_height;
	int			map_width;
	int			floor_color;
	int			ceiling_color;
	int			x_pixel;
	double			rad_for_col;
}				t_game;

#endif
