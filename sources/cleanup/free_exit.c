/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:39:40 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:22 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "stdlib.h"

int	cleanup(t_parsing_data *parsing_data, int error, t_game *game)
{
	if (parsing_data)
		free_parsing(parsing_data);
	if (game)
		free_game(game);
	return (error);
}
