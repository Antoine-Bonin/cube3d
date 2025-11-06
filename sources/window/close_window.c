/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:00 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/06 17:58:27 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdlib.h"
#include "window.h"

#define ESC_KEY 65307

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC_KEY)
		exit(0);
	return (0);
}
