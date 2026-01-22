/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:07:06 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:07:22 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structures.h"

/* ************************************************************************** */
/*                         INITIALIZE STRUCT                                  */
/* ************************************************************************** */

void	init_parsing_data(t_parsing_data *parsing_data);
void	init_mlx(t_mlx_data *mlx_data);
void	init_game(t_game *game, t_mlx_data *data);

/* ************************************************************************** */
/*                            MLX LOOP HOOK                                   */
/* ************************************************************************** */

int		environment(t_game *game);
void	mlx_all_hook(t_game *game, t_mlx_data mlx_data);

#endif