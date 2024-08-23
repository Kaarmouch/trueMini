/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/23 17:44:59 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cmp(char *o, char *t)
{
	int	i;

	i = 0;
	while (o[i])
	{
		if (o[i] != t[i])
			return (0);
		i++;
	}
	if (t[i])
		return (0);
	return (1);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(dup))
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (line[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_verif_line(char *line)
{
	int	i;
	int	sb;
	int	db;

	i = 0;
	sb = 0;
	db = 0;
	if (is_empty_line(line) == 1)
		return (1);
	while (line[i])
	{
		if (line[i] == 34)
			db++;
		if (line[i] == 39)
			sb++;
		i++;
	}
	if (sb % 2 == 1 || db % 2 == 1)
	{
		write(1, "bash : not interpreted unclosed quotes\n", 39);
		return (1);
	}
	return (0);
}
