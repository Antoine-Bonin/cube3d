/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05-parse_color_cub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:52:29 by antbonin          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:22 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "libft.h"
#include "messages.h"
#include "stdlib.h"

static int	count_commas(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_not_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	get_color_in_data_loop(int *i, char **split, char *trimmed, int *color)
{
	int	value;
	int	error;

	error = 0;
	while (*i < 3 && split[*i])
	{
		trimmed = ft_strtrim(split[*i], " \t\n");
		if (!trimmed || !is_valid_number(trimmed) || is_not_number(trimmed))
		{
			free(trimmed);
			return (0);
		}
		value = ft_atoi(trimmed, &error);
		if (error == -1)
		{
			free(trimmed);
			return (0);
		}
		free(trimmed);
		color[*i] = value;
		(*i)++;
	}
	return (1);
}

int	get_color_in_data(int *color, char *line)
{
	char	**split;
	int		i;
	char	*trimmed;

	trimmed = NULL;
	if (count_commas(line) != 2)
		return (0);
	split = ft_split(line, ',');
	if (!split)
		return (0);
	i = 0;
	if (!get_color_in_data_loop(&i, split, trimmed, color))
	{
		ft_free_tab(split);
		return (0);
	}
	if (i != 3 || split[3] != NULL)
	{
		ft_free_tab(split);
		return (0);
	}
	ft_free_tab(split);
	return (1);
}
