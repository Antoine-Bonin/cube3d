/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:20:44 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 13:52:54 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "stdbool.h"

typedef struct s_parsing_data
{
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map;
	int			map_height;
	int			map_width;
	bool		textures_complete;
	int			player_x;
	int			player_y;
	char		player_direction;
	bool		dup_found;
}				t_parsing_data;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[4];
	int			img_width;
	int			img_height;
}				t_mlx_data;

typedef enum e_direction
{
	NORTH = 0,
	WEST = 1,
	EAST = 2,
	SOUTH = 3
}				t_direction;

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

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		fov_x;
	double		fov_y;
	double		move_speed;
	bool		jumping;
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
}				t_game;

#endif
