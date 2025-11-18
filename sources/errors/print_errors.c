/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:43:32 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/11 16:03:33 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "messages.h"
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
