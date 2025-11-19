/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:29:58 by pde-petr          #+#    #+#             */
/*   Updated: 2025/11/19 11:29:57 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "init.h"
#include "mlx.h"
#include "parsing.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	init_parsing_data(t_parsing_data *parsing_data)
{
	parsing_data->north_texture_path = NULL;
	parsing_data->south_texture_path = NULL;
	parsing_data->south_texture_path = NULL;
	parsing_data->west_texture_path = NULL;
	parsing_data->east_texture_path = NULL;
	parsing_data->map = NULL;
	int i = -1;
	while (++i < 3)
	{
		parsing_data->ceiling_color[i] = -1;
		parsing_data->floor_color[i] = -1;
	}
	parsing_data->map_height = 0;
	parsing_data->player_x = 0;
	parsing_data->player_y = 0;
	parsing_data->player_direction = '\0';
	parsing_data->textures_complete = false;
	parsing_data->dup_found = false;
}

void	init_mlx(t_mlx_data *mlx_data)
{
	int i = 0;
	while (i < 4)
	{
		mlx_data->textures[i++] = NULL;
	}
	mlx_data->mlx_ptr = NULL;
	mlx_data->win_ptr = NULL;
	mlx_data->img_height = 64;
	mlx_data->img_width = 64;
}

void	init_game(t_game *game, t_mlx_data *data)
{
	game->mlx_data = data;
	game->ceiling_color = 0;
	game->floor_color = 0;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player = NULL;
	
}

#include "free_malloc.h"
#include "stdlib.h"
#include "libft.h"

t_tile **init_tiles_from_map(char **map, int height)
{
    t_tile **tiles = (t_tile **)malloc(sizeof(t_tile *) * height);
    int y = -1;
	int map_len = 0;
    
    while (++y < height)
    {
		map_len = ft_strlen(map[y]);
        tiles[y] = (t_tile *)malloc(sizeof(t_tile) * map_len);
        int x = -1;
        while (++x < map_len)
        {
            tiles[y][x].type = map[y][x];
            tiles[y][x].map_x = x;
            tiles[y][x].map_y = y;
            
            if (map[y][x] == '1')
				is_wall()
            else if (map[y][x] == '0')
				is_floor()
			else if (map[y][x] == ' ')
				is_hole()
        }
    }
    return (tiles);
}

int parse_tile(t_game *game, t_parsing_data *parsing_data)
{
	
	game->map = parse_map_tile(parsing_data->map, parsing_data->map_height);
	free_parsing(parsing_data); 
	if (!game->map)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parsing_data	parsing_data;
	t_mlx_data		mlx_data;
	t_game			game;

	init_parsing_data(&parsing_data);
	init_mlx(&mlx_data);
	init_game(&game, &mlx_data);
	if (ac > 1)
	{
		if (!parsing(av[1], &parsing_data))
			return (error_cleanup(&parsing_data, 1, &mlx_data, &game));
		if (!init_window_and_textures(&parsing_data, &mlx_data))
			return (error_cleanup(&parsing_data, 1, &mlx_data, &game));
		if (!parse_tile)
			return (error_cleanup(NULL, 0, &mlx_data, &game));
		mlx_hook(mlx_data.win_ptr, 17, 0, (int (*)())close_window, &game);
		mlx_hook(mlx_data.win_ptr, KeyPress, KeyPressMask,
			(int (*)())handle_keypress, &game);
		mlx_loop(mlx_data.mlx_ptr);
	}
	return (error_cleanup(NULL, 0, &mlx_data, &game));
}

// int i = 0;
// if (parsing_data->map)
// {
// 	while (parsing_data->map[i])
// 	{
// 		printf("%s", parsing_data->map[i]);
// 		i++;
// 	}
// 	printf("\n%s\n", parsing_data->north_texture_path);
// 	printf("%s\n", parsing_data->east_texture_path);
// 	printf("%s\n", parsing_data->south_texture_path);
// 	printf("%s\n", parsing_data->west_texture_path);
// 	printf("floor color : %d,%d,%d\n", parsing_data->floor_color[0],
// 		parsing_data->floor_color[1], parsing_data->floor_color[2]);
// 	printf("ceiling color : %d,%d,%d\n", parsing_data->ceiling_color[0],
// 		parsing_data->ceiling_color[1], parsing_data->ceiling_color[2]);
// 	printf("player direction : %c\n", parsing_data->player_direction);
// 	printf("player x : %d\n", parsing_data->player_x);
// 	printf("player y : %d\n", parsing_data->player_y);
// }