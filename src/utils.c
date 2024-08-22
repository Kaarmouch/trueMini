/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/22 17:16:18 by aglampor         ###   ########.fr       */
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
	if(t[i])
		return (0);
	return (1);
}

char    *ft_strdup(char *str)
{
        char    *dup;
        int     i;

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



