/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:43:32 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/14 18:27:39 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

int	msg_error(char *str, int error)
{
	ft_printf_fd(2, str);
	return (error);
}

int	msg_error_and_free(char *str, int error, void *to_free)
{
	ft_printf_fd(2, str);
	free(to_free);
	return (error);
}
