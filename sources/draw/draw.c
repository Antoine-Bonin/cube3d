/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:43:33 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/13 18:11:05 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "init.h"
#include "mlx.h"
#include "stdio.h"
#include <draw.h>

static const int	deg_dir[] = {270, 90, 360, 180};

// if (y < 0 || y >= HEIGHT || x[1] < 0 || x[1] >= LENGTH)
//     return ;

// if (y_img <= 0)
//     y_img = 0;
// if (y_img > (img->img_height -1))
//     y_img = (img->img_height -1);
// if (x[0] < 0)
//     x[0] = 0;
// if (x[0] > (img->img_width -1))
//     x[0] = (img->img_width -1);

// if (!img->img.addr)
//     return ;

void	mlx_put_pixel_by_img(t_game *game, int *x, int y, t_img *img)
{
	int		y_img;
	char	*dst;
	char	*src;

	(void)img;
	y_img = (img->img_height * game->param_draw.y_in_wall)
		/ game->param_draw.size_wall;
	dst = game->mlx_data->img.addr + (y * game->mlx_data->img.line_length + x[1]
			* (game->mlx_data->img.bits_per_pixel >> 3));
	src = img->addr + (y_img * img->line_length + x[0]
			* ((img->bits_per_pixel >> 3)));
	*(unsigned int *)dst = *(unsigned int *)src;
}

void	draw(t_game *game, t_dir dda, t_compass compass, double proj_to_screen)
{
	int	size_block;
	int	pixel_min[2];
	int	pixel_max[2];
	int	i;
	int	choice_x_pixel_for_img;

	i = 0;
	size_block = size_block_in_height(proj_to_screen, dda, game);
	pixel_min[1] = ((HEIGHT + game->param_draw.orientation_vert) >> 1)
		- (size_block >> 1);
	pixel_min[0] = resize_height(pixel_min[1]);
	pixel_max[1] = ((HEIGHT + game->param_draw.orientation_vert) >> 1)
		+ (size_block >> 1);
	pixel_max[0] = resize_height(pixel_max[1]);
	choice_x_pixel_for_img = x_find_pixel_for_img(game, dda,
			game->mlx_data->textures[compass].img_width);
	game->param_draw.size_wall = size_block;
	game->param_draw.y_in_wall = -1;
	while (i < HEIGHT)
	{
		if (i >= pixel_min[0] && i < pixel_max[0])
		{
			game->param_draw.y_in_wall = i - pixel_min[1];
			mlx_put_pixel_by_img(game,
                (int[]){choice_x_pixel_for_img,game->x_pixel},
                 i, &game->mlx_data->textures[compass]);
		}
		else if (i < pixel_min[0])
			my_mlx_pixel_put(&game->mlx_data->img, game->x_pixel, i,
				game->ceiling_color.value);
		else if (i >= pixel_max[0])
			my_mlx_pixel_put(&game->mlx_data->img, game->x_pixel, i,
				game->floor_color.value);
		i++;
	}
}

void	calc_player_to_intersection_x_or_y(t_dir for_x, t_dir for_y,
		t_game *game, double proj_to_screen)
{
	for_x = calc_direction(for_x, game, 'x');
	for_y = calc_direction(for_y, game, 'y');
	check_block_by_block(for_x, for_y, game, proj_to_screen);
}

int	calc_trigo_for_draw(t_game *game)
{
	static bool init = 0;
	t_player *perso = game->player;
	if (init == 0)
	{
		init = true;
		perso->deg = deg_dir[game->player->direction];
	}
	calc_init_for_ray(perso, game);
	return (0);
}