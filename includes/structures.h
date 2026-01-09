/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:44 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/09 20:11:52 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "stdbool.h"
#include "tile.h"
#include <stdint.h>
#include <time.h>

typedef struct s_data
{
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int img_width;
	int img_height;
} t_img;

typedef struct s_parsing_data
{
	char *north_texture_path;
	char *south_texture_path;
	char *west_texture_path;
	char *east_texture_path;
	int floor_color[3];
	int ceiling_color[3];
	char **map;
	int map_height;
	int map_width;
	bool textures_complete;
	int player_x;
	int player_y;
	char player_direction;
	bool dup_found;
} t_parsing_data;

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
	t_img textures[4];
	int img_width;
	int img_height;
	void *minimap_img[MAX];
	int minimap_tile_size;
} t_mlx_data;

#include <stdint.h>

typedef struct s_struct_argb
{
	uint8_t a;
	uint8_t r;
	uint8_t b;
	uint8_t g;
} t_struct_rgb;

typedef union u_argb
{
	uint8_t channels[4];
	unsigned int value;
	t_struct_rgb argb;
} t_argb;

typedef struct s_tile
{
	char type;
	bool is_player;
	bool is_solid;
	bool is_transparent;
	double floor_height;
	double ceiling_height;
	int map_x;
	int map_y;
	int color_mini_map[3];
} t_tile;

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
	double offset_player_grid;
	t_compass texture_use;
	struct s_dir *for_inverse_point;
} t_dir;

typedef struct s_vec
{
	int pos_x;
	int pos_y;
} t_vec;

typedef struct s_player
{
	double pos_x;
	double pos_y;
	int pos_x_int;
	int pos_y_int;
	t_compass direction;
	t_vec ray_limit;
	double move_speed;
	bool jumping;
	int nb_ray;
	double deg;
} t_player;

typedef struct s_param_draw
{
	int size_wall;
	int y_in_wall;
	int x_pixel;
	double rad_for_col;
	int orientation_vert;
} t_param_draw;

typedef struct s_keys
{
	bool w;
	bool a;
	bool s;
	bool d;
	bool up;
	bool down;
	bool left;
	bool right;
} t_keys;

typedef struct s_game
{
	t_mlx_data *mlx_data;
	t_player *player;
	t_tile **map;
	int map_height;
	int map_width;
	t_argb floor_color;
	t_argb ceiling_color;
	int x_pixel;
	double rad_for_col;
	bool show_minimap;
	int size_minimap;
	t_param_draw param_draw;
	t_keys keys;
	int frame_count;
	time_t last_time;
	int fps;
} t_game;

extern const char type_index[];
extern const t_tile type_block[];

#endif
