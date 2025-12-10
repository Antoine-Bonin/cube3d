/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:43:33 by pde-petr          #+#    #+#             */
/*   Updated: 2025/12/09 13:39:21 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FOV_DEG 60
#define Ray 30
#define SIZE_BLOCK 1
#include <draw.h>
#include "stdio.h"
#include "init.h"
#include "float.h"

static const int deg_dir[] = {90, 270, 360, 180};

double deg_to_rad(double deg)
{
    return (deg * (2 * M_PI)) / 360;
}

static void calc_rayon(double deg, t_vec *result)
{
    result->pos_x = (cos(deg_to_rad(deg)));
    result->pos_y = (sin(deg_to_rad(deg)));
}
static double calc_straight_equ_a(double dest_x, double begin_x, double dest_y, double begin_y)
{
    double delta_x = dest_x - begin_x;

    // eviter si x dep == x arrive sinon ca va tout casssey
    if (fabs(delta_x) < 0.00001)
        return (999999.0);

    return ((dest_y - begin_y) / delta_x);
}
static double calc_straight_equ_b(double a, double pos_x, double pos_y)
{
    return (-a * pos_x + pos_y);
}

static double compare_vec(t_vec *vec_a, t_vec *vec_b)
{
    int result;
    result = 0;
    if (!vec_a || !vec_b)
        return 0;
    if (vec_a->pos_x == vec_b->pos_x)
        result += 1;
    if (vec_a->pos_y == vec_b->pos_y)
        result += 1;
    if (result == 2)
        return 1;
    return 0;
}

int check_in_my_map(t_vec point, t_game game)
{
    if (game.map_width < point.pos_x)
        return 0;
    if (game.map_height < point.pos_y)
        return 0;
    return 1;
}

double delta_dist(ray_dir)
{
    if (fabs(ray_dir) < 1e-5)
        return (DBL_MAX);
    return fabs(1.00 / ray_dir);
}

static int raycasting(t_player *player, double deg_a, double deg_b, t_game *game)
{
    // mettre les points s
    // printf("%f de a et %f de b \n", perso->fov.vec_a.a, perso->fov.vec_b.a);
    // printf("%f de a et %f de b \n", perso->fov.vec_a.b, perso->fov.vec_b.b);
    double steps;
    steps = FOV_DEG / LENGTH;
    double a;
    double b;
    t_vec trace;
    int mapX = (int)player->pos_x;
    int mapY = (int)player->pos_y;
    t_vec trace;
    t_vec temp_x;
    t_vec temp_y;
    int steps_x;
    int steps_y;
    double sideDistX;
    double sideDistY;
    double hypothenuse;
    int pixels_to_draw;
    int mapX;
    int mapY;
    int side;
    double total_dist;
    total_dist = 0.00;

    while (deg_b <= deg_a)
    {

        // recommencer
        // dabord faire le cos et le sin de langle ce qui me permet de trouver le point
        stepHeight = 
        double rayDirX = (cos(deg_to_rad(deg_b)));
        double rayDirY = (sin(deg_to_rad(deg_b)));
        double deltaDistX = delta_dist(rayDirX);
        double deltaDistY = delta_dist(rayDirY);
        mapX = (int)player->pos_x;
        mapY = (int)player->pos_y;
        if (rayDirX >= 0 && deltaDistX != DBL_MAX)
        {

            steps_x = 1;
            sideDistX = (mapX + 1.0 - player->pos_x) * deltaDistX;
        }
        else if (deltaDistX > 0)
        {

            steps_x = -1;
            sideDistX = (player->pos_x - mapX) * deltaDistX;
        }
        if (rayDirY >= 0 && deltaDistY != DBL_MAX)
        {

            steps_y = 1;
            sideDistY = (mapY + 1.0 - player->pos_y) * deltaDistY;
        }
        else if (deltaDistY != DBL_MAX)
        {
            steps_y = -1;
            sideDistY = (player->pos_y - mapY) * deltaDistY;
        }
        while (1)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += steps_x;
                side = 0;
                if (total_dist == 0.00)
                    total_dist += fabs(sideDistX);
                total_dist += fabs(deltaDistY);
            }
            else
            {
                sideDistY += deltaDistY;
                total_dist += fabs(deltaDistY);
                if (total_dist == 0.00)
                    total_dist += fabs(sideDistY);
                mapY += steps_y;
                side = 1;
                total_dist += fabs(deltaDistY);
            }
                if (total_dist > Ray || check_in_my_map((t_vec){mapX, mapY}, *game) == 1 || game->map[mapY][mapX].is_solid == 1) 
                    break;
            
        }

        // hypothenuse = hypo(rayDirX, rayDirY);
        // steps_x = deltaX / hypothenuse;
        // steps_y = deltaY / hypothenuse;
        // pixels_to_draw = (int)hypo;

        // calc_pos_to_circle(player->pos_x, player->pos_y, deg_b, &player->ray_limit);
        // a = calc_straight_equ_a(player->pos_x, player->ray_limit.pos_x, player->pos_y, player->ray_limit.pos_y);
        // b = calc_straight_equ_b(player->ray_limit.a, player->ray_limit.pos_x, player->ray_limit.pos_y);
        // t_vec trace;
        // t_vec temp_x;
        // t_vec temp_y;
        // double distX;
        // double distY;
        // trace.pos_x = player->pos_x;
        // trace.pos_y = player->pos_y;
        // double dist_parc;
        // dist_parc = 0;
        // char type = 0;
        // int steps_x;
        // int steps_y;

        // if (trace.pos_x + player->ray_limit.pos_x > trace.pos_x)
        // {
        //     temp_x.pos_x = round(trace.pos_x);
        //     steps_x = 1;
        // }
        // else
        // {
        //     temp_x.pos_x = floor(trace.pos_x);
        //     steps_x = -1;
        // }
        // if (trace.pos_y + player->ray_limit.pos_y > trace.pos_y)
        // {
        //     temp_y.pos_y = round(trace.pos_y);
        //     steps_y = 1;
        // }
        // else
        // {
        //     temp_y.pos_y = floor(trace.pos_y);
        //     steps_y = -1;
        // }
        // temp_x.pos_y = a * temp_x.pos_x + b;
        // temp_y.pos_x = (-b + temp_y.pos_y) / a;
        // distX = hypot(temp_x.pos_x - trace.pos_x, temp_x.pos_y - trace.pos_y);
        // distY = hypot(temp_y.pos_x - trace.pos_x, temp_y.pos_y - trace.pos_y);
        // while (dist_parc <= Ray)
        // {

        //     // connaitre la direction de x et de y

        //     // connaitre les y et x respectif grace a leq dun inconnude

        //     if (distX > distY)
        //     {
        //         if (check_in_my_map(temp_y, *game))
        //         {
        //             if (draw(distY, temp_y, game, a, b) == 1)
        //                 break;
        //             else
        //             {
        //                 trace = temp_y;
        //                 temp_y.pos_y += steps_y;
        //                 temp_y.pos_x = (-b + temp_y.pos_y) / a;
        //                 dist_parc += distY;
        //                 distY = sqrt(temp_y.pos_x - trace.pos_x + temp_y.pos_y - trace.pos_y);
        //             }
        //         }
        //         else
        //             break;
        //     }
        //     else
        //     {
        //         if (check_in_my_map(temp_x, *game))
        //         {
        //             if (draw(distY, temp_x, game, a, b) == 1)
        //                 break;
        //             else
        //             {
        //                 trace = temp_x;
        //                 temp_x.pos_x += steps_x;
        //                 temp_x.pos_y = a * temp_x.pos_x + b;
        //                 dist_parc += distX;
        //                 distX = sqrt(temp_x.pos_x - trace.pos_x + temp_x.pos_y - trace.pos_y);
        //             }
        //         }
        //         else
        //             break;
        //     }
        // }
        deg_b += steps;
    }
}

int calc_trigo_for_draw(t_game *game)
{
    static bool init = 0;
    t_player *perso = game->player;
    if (init == 0)
    {
        init++;
        perso->deg = deg_dir[game->player->direction];
    }
    // printf("%f value player x && %f value player y\n", perso->dir_x, perso->dir_y);
    // printf("\n%f value deg_to_rad = %f\n", cos(deg_to_rad(perso->fov.deg+30)), sin(deg_to_rad(perso->fov.deg+30)));
    // printf("\n%f value deg_to_rad = %f\n", cos(deg_to_rad(perso->fov.deg-30)), sin(deg_to_rad(perso->fov.deg-30)));
    // la jai le vecteur des points du perso aux points des extremites de a et b
    long deg_a = perso->deg + 30;
    long deg_b = perso->deg - 30;

    return 0;
}