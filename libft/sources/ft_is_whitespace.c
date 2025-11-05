/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:28:31 by antbonin          #+#    #+#             */
/*   Updated: 2025/11/05 14:35:30 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	is_whitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_whitespace_str(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i])
	{
		if ((str[i] < 9 || str[i] > 13) && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}
