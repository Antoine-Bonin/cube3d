/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/19 10:39:34 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"

#define ESC_KEY 65307

int	close_window(t_game *game)
{
	free_mlx(game->mlx_data);
	free_game(game);
	exit(1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_window(game);
	return (0);
}
