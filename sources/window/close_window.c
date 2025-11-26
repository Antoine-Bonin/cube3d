/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/26 16:11:48 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_malloc.h"
#include "mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "window.h"

#define ESC_KEY 65307

int	close_window(t_mlx_data *data)
{
	
	data->exit = 1;
	mlx_loop_end(data->mlx_ptr);
	return 0;
}

int	handle_keypress(int keycode, t_mlx_data *data)
{
	if (keycode == ESC_KEY)
		return close_window(data);
	return (0);
}
