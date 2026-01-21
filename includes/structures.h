/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:44 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/21 20:25:51 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "stdbool.h"
# include "tile.h"
# include <stdint.h>
# include <time.h>

typedef struct s_img
{
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

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

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_flood_fill_data
{
	t_point			*queue;
	int				front;
	int				rear;
	int				max_size;
}					t_flood_fill_data;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_img			textures[4];
	void			*minimap_img[MAX];
	int				minimap_tile_size;
	t_img			map_buf;
	bool			minimap_buffer_created;
}					t_mlx_data;

typedef struct s_struct_argb
{
	uint8_t			a;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_struct_rgb;

typedef union u_argb
{
	uint8_t			channels[4];
	unsigned int	value;
	t_struct_rgb	argb;
}					t_argb;

typedef struct s_tile
{
	char			type;
	bool			is_player;
	bool			is_solid;
	bool			is_transparent;
	int				map_x;
	int				map_y;
	int				color_mini_map[3];
}					t_tile;

typedef enum s_compass
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}					t_compass;

typedef struct s_ray
{
	double			raydir;
	double			delta_dist;
}					t_ray;

typedef struct s_dir
{
	t_ray			ray;
	int				steps;
	char			x_or_y;
	bool			positive;
	double			side_dist;
	double			offset_player_grid;
	t_compass		texture_use;
	struct s_dir	*for_inverse_point;
}					t_dir;

typedef struct s_draw_data
{
	int				size_block;
	int				pixel_min[2];
	int				pixel_max[2];
	int				current_y;
}					t_draw_data;

typedef struct s_vec
{
	int				pos_x;
	int				pos_y;
}					t_vec;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			base_pos_x;
	double			base_pos_y;
	int				pos_x_int;
	int				pos_y_int;
	t_compass		direction;
	t_vec			ray_limit;
	double			move_speed;
	double			base_speed;
	double			sprint_speed;
	bool			jumping;
	int				nb_ray;
	double			deg;
}					t_player;

typedef struct s_param_draw
{
	int				size_wall;
	int				y_in_wall;
	int				x_pixel;
	double			rad_for_x;
	int				orientation_vert;
}					t_param_draw;

typedef struct s_keys
{
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			q;
	bool			left;
	bool			right;
}					t_keys;

typedef struct s_game
{
	t_mlx_data		*mlx_data;
	t_player		*player;
	t_tile			**map;
	int				map_height;
	int				map_width;
	t_argb			floor_color;
	t_argb			ceiling_color;
	bool			show_minimap;
	int				size_minimap;
	t_param_draw	param_draw;
	t_keys			keys;
	int				frame_count;
	long			last_time_ms;
	long			for_speed_last_time_ms;
	int				fps;
}					t_game;

typedef struct s_minimap_render
{
	int				pixel;
	int				view_range;
	int				offset_x;
	int				offset_y;
	int				player_x;
	int				player_y;
}					t_minimap_render;

extern const char	g_type_index[];
extern const t_tile	g_type_block[];

#endif
