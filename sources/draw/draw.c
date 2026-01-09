/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:43:33 by pde-petr          #+#    #+#             */
/*   Updated: 2026/01/09 20:43:03 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FOV_DEG 90
#define Ray 30
#define SIZE_BLOCK 1
#include <draw.h>
#include "stdio.h"
#include "init.h"
#include "float.h"

static const int deg_dir[] = {270, 90, 360, 180};
double  deg_to_rad(double  deg)
{
    return deg * M_PI / 180;
}

bool check_if_after_limit(int point, int size_max)
{
    if (point >= 0 || point <= size_max)
        return true;
    return false;
}

double  delta_dist(double  ray_dir)
{
    if (fabs(ray_dir) < 1e-5)
        return (DBL_MAX);
    return fabs(1.00 / ray_dir);
}

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    // t_argb test;
    // test.argb = (t_rgb){0, 255, 255, 0};
    // test.value = 0x00000;

    // t_argb *dst;

    // *(data->addr + (y * data->width + x)) = test;

    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel >> 3));
    *(unsigned int *)dst = color;
}

t_dir calc_side_dist(t_dir value, int pos, double  pos_in_double)
{

    if (value.ray.raydir > 0 && value.ray.raydir != DBL_MAX)
    {

        value.positif = true;
        
        value.side_dist = ((1 + pos) - pos_in_double) * value.ray.delta_dist;
    }
    else if (value.ray.raydir != DBL_MAX)
    {
        value.positif = false;
        value.side_dist = (pos_in_double - pos) * value.ray.delta_dist;
    }
    else
        value.side_dist = DBL_MAX;
    return value;
}

t_dir calc_direction(t_dir value, t_game *game, char x_or_y)
{
    value.x_or_y = x_or_y;
    value.steps = 1;
    if (x_or_y == 'x')
    {

        value = calc_side_dist(value, game->player->pos_x_int, game->player->pos_x);
        if (value.positif == 1)
            value.texture_use = NORTH;
        else
            value.texture_use = SOUTH;
    }
    else
    {
        value = calc_side_dist(value, game->player->pos_y_int, game->player->pos_y);
        if (value.positif == 1)
            value.texture_use = EAST;
        else
            value.texture_use = WEST;
    }
    if (value.positif != 1)
        value.steps = -1;
    return value;
}

bool block_is_solid(t_tile block)
{
    if (block.is_solid == true)
        return true;
    return false;
}

int size_block_in_height(double  proj_to_screen, t_dir dda, t_game *game)
{
    // return (dda.side_dist/proj_to_screen *dda.side_dist); $$Distance_{Perpendiculaire} = Distance_{Brute} \times \cos(\text{AngleRayon} - \text{AngleJoueur})$$ distance brut *
    double  side_dist_recalc;

    side_dist_recalc = dda.side_dist * cos(game->rad_for_col - deg_to_rad(game->player->deg));
    if (side_dist_recalc == 0)
        side_dist_recalc = DBL_MIN;
    return (proj_to_screen / side_dist_recalc);
}

int resize_height(int value)
{
    if (value < 0)
        value = 0;
    if (value > HEIGHT)
        value = HEIGHT - 1;
    return value;
}

// int calc_oppose_for_pytha(double pos_first, double pos_last)
// {
//     if (pos_last > pos_first)
//         return pos_last - pos_first;
//     else
//         return pos_first - pos_last;
// }

int x_find_pixel_for_img(t_game *game, t_dir dda_point, int length)
{
    // double oppose;
    // double adj;
    // double x_find;
    // if (dda_point.x_or_y == 'x')
    //     oppose = calc_oppose_for_pytha(game->player->pos_x, game->player->pos_x_int);
    // else
    //     oppose = calc_oppose_for_pytha(game->player->pos_y, game->player->pos_y_int);
    // adj = sqrt(dda_point.side_dist) - sqrt(oppose);
    // if (dda_point.for_inverse_point->side_dist != DBL_MAX)
    // {
    //     x_find = adj - dda_point.for_inverse_point->offset_player_grid;
    // }
    // else
    // {
    //     if (dda_point.x_or_y == 'x')
    //         x_find = game->player->pos_y;
    //     else
    //         x_find = game->player->pos_x;
    // }
    // return (x_find - (int)x_find) * 100;
    double x_find;

    if (dda_point.x_or_y == 'x')
        x_find = game->player->pos_y + (dda_point.side_dist * dda_point.for_inverse_point->ray.raydir);
    else
        x_find = game->player->pos_x + (dda_point.side_dist * dda_point.for_inverse_point->ray.raydir);

    x_find = x_find - (int)x_find;

    if ((dda_point.x_or_y == 'x' && dda_point.ray.raydir > 0) ||
        (dda_point.x_or_y == 'y' && dda_point.ray.raydir < 0))
    {
        x_find = 1.0 - x_find;
    }

    return x_find * length;
}

void mlx_put_pixel_by_img(t_game *game, int *x, int y, t_img *img)
{
    int y_img;
    char *dst;
    char *src;
    (void)img;

    // if (y < 0 || y >= HEIGHT || x[1] < 0 || x[1] >= LENGTH)
    //     return;

    y_img = (img->img_height * game->param_draw.y_in_wall) / game->param_draw.size_wall;
    
    // if (y_img <= 0)
    //     y_img = 0;
    // if (y_img > (img->img_height -1))
    //     y_img = (img->img_height -1);
    // if (x[0] < 0)
    //     x[0] = 0;
    // if (x[0] > (img->img_width -1))
    //     x[0] = (img->img_width -1);

    // printf("ddd %d\n", x[0]);
    dst = game->mlx_data->img.addr + (y * game->mlx_data->img.line_length + x[1] * (game->mlx_data->img.bits_per_pixel >> 3));
    src = img->addr + (y_img * img->line_length + x[0] * ((img->bits_per_pixel >> 3)));
    // if (!img->img.addr)
    //     return;
    *(unsigned int *)dst = *(unsigned int *)src;
}

void draw(t_game *game, t_dir dda, t_compass compass, double  proj_to_screen)
{
    int size_block;
    int pixel_min[2];
    int pixel_max[2];
    int i;
    i = 0;
    int choice_x_pixel_for_img;

    size_block = size_block_in_height(proj_to_screen, dda, game);
    pixel_min[1] = ((HEIGHT+game->param_draw.orientation_vert) >> 1) - (size_block >> 1);
    pixel_min[0] = resize_height(pixel_min[1]);
    
    pixel_max[1] = ((HEIGHT+game->param_draw.orientation_vert) >> 1) + (size_block >> 1);
    pixel_max[0] = resize_height(pixel_max[1]);
    choice_x_pixel_for_img = x_find_pixel_for_img(game, dda, game->mlx_data->textures[compass].img_width);
    game->param_draw.size_wall = size_block;
    
    
    game->param_draw.y_in_wall = -1;
    while (i < HEIGHT)
    {
        if (i >= pixel_min[0] && i < pixel_max[0])
        {
            game->param_draw.y_in_wall  = i - pixel_min[1];
            // printf("compass value = %d\n", compass);
            mlx_put_pixel_by_img(game, (int []){choice_x_pixel_for_img,game->x_pixel}, i, &game->mlx_data->textures[compass]);
            // my_mlx_pixel_put(&game->mlx_data->img, game->x_pixel, i, 0x0000FF);
        }
        else if (i < pixel_min[0])
            my_mlx_pixel_put(&game->mlx_data->img, game->x_pixel, i, game->ceiling_color.value);
        else if (i >= pixel_max[0])
            my_mlx_pixel_put(&game->mlx_data->img, game->x_pixel, i, game->floor_color.value);
        i++;
    }
}

void check_block_by_block(t_dir for_x, t_dir for_y, t_game *game, double  proj_to_screen)
{
    t_dir *choice;
    while (1)
    {
        if (for_x.side_dist <= for_y.side_dist)
        {
            choice = &for_x;
            game->player->pos_x_int += for_x.steps;
        }

        else
        {
            choice = &for_y;
            game->player->pos_y_int += for_y.steps;
        }

        if (block_is_solid(game->map[game->player->pos_y_int][game->player->pos_x_int]) == true)
            break;
        choice->side_dist += choice->ray.delta_dist;
    }
    for_x.for_inverse_point = &for_y;
    for_y.for_inverse_point = &for_x;
    draw(game, *choice, choice->texture_use, proj_to_screen);
}

void calc_player_to_intersection_x_or_y(t_dir for_x, t_dir for_y, t_game *game, double  proj_to_screen)
{
    for_x = calc_direction(for_x, game, 'x');
    for_y = calc_direction(for_y, game, 'y');

    check_block_by_block(for_x, for_y, game, proj_to_screen);
}

void calc_derivative_and_delta_dist(double  rad, double  proj_to_screen, t_game *game)
{
    // double  raydirY;
    // double  raydirX;
    // double  delta_dist_x;
    // double  delta_dist_y;
    t_dir for_x;
    t_dir for_y;

    for_x.ray.raydir = cos(rad);
    for_y.ray.raydir = sin(rad);

    for_x.ray.delta_dist = delta_dist(for_x.ray.raydir);
    for_y.ray.delta_dist = delta_dist(for_y.ray.raydir);

    return calc_player_to_intersection_x_or_y(for_x, for_y, game, proj_to_screen);
}

void calc_init_for_ray(t_player *player, t_game *game)
{
    // mettre les points s
    // printf("%f de a et %f de b \n", perso->fov.vec_a.a, perso->fov.vec_b.a);
    // printf("%f de a et %f de b \n", perso->fov.vec_a.b, perso->fov.vec_b.b);
    static bool init = false;
    static double  proj_to_screen;
    double  rad_player;
    int position_x_to_center;

    // etape 2
    if (!init)
    {
        proj_to_screen = (double)(LENGTH >> 1) / tan(deg_to_rad(FOV_DEG >> 1));
        init = true;
    }
    game->x_pixel = 0;
    rad_player = deg_to_rad(player->deg);
    while (game->x_pixel < LENGTH)
    {
        // etape 3 calculer la dérivé
        position_x_to_center = game->x_pixel - (LENGTH >> 1);
        player->pos_x_int = (int)player->pos_x;
        player->pos_y_int = (int)player->pos_y;
        game->rad_for_col = rad_player + atan(position_x_to_center / proj_to_screen);
        calc_derivative_and_delta_dist(game->rad_for_col, proj_to_screen, game);
        game->x_pixel++;
    }
}

int calc_trigo_for_draw(t_game *game)
{
    static bool init = 0;
    t_player *perso = game->player;
    if (init == 0)
    {
        init = true;
        perso->deg = deg_dir[game->player->direction];
    }
    // printf("%f value player x && %f value player y\n", perso->dir_x, perso->dir_y);
    // printf("\n%f value deg_to_rad = %f\n", cos(deg_to_rad(perso->fov.deg+30)), sin(deg_to_rad(perso->fov.deg+30)));
    // printf("\n%f value deg_to_rad = %f\n", cos(deg_to_rad(perso->fov.deg-30)), sin(deg_to_rad(perso->fov.deg-30)));
    // la jai le vecteur des points du perso aux points des extremites de a et b
    calc_init_for_ray(perso, game);
    return 0;
}