/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:21:31 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 10:32:20 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MALLOC_H
# define FREE_MALLOC_H

# include "structures.h"

int		error_cleanup(t_parsing_data *data, int error);
void	ft_free_tab(char **map);
int		malloc_error_parsing(t_parsing_data *data);
int		msg_error_and_free(char *str, int error, void *to_free);

#endif