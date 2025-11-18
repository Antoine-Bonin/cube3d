/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:21:31 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/18 13:22:33 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MALLOC_H
# define FREE_MALLOC_H

# include "structures.h"

int		error_cleanup(t_parsing_data *parsing_data, int error,
			t_mlx_data *mlx_data);
void	ft_free_tab(char **map);
int		malloc_error_in_parsing_exit(t_parsing_data *parsing_data);
int		msg_error_and_free(char *str, int error, void *to_free);
void	free_mlx(t_mlx_data *mlx_data);
void	free_and_set_null(void *ptr);
void	free_data_mlx_parsing(t_game *game);
void	free_parsing(t_parsing_data *parsing_data);

#endif