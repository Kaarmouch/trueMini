/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/25 19:50:13 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_pipe(t_token *t)
{
	int	i;
	t_token	*temp;

	i = 0;
	temp = t;
	while (temp && temp->type != PIPE)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_cmp(char *o, char *t)
{
	int	i;

	i = 0;
	while (o[i])
	{
		if (o[i] != t[i])
			return (o[i] - t[i]);
		i++;
	}
	return (o[i] - t[i]);
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
