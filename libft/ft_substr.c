/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:34:01 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/08 10:23:59 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;
	int		n_str;

	n_str = 0;
	if (!s)
		return (0);
	while (start + n_str < ft_strlen(s) && (size_t)n_str < len)
	{
		n_str++;
	}
	str = malloc(sizeof(char) * n_str + 1);
	if (!str)
		return (0);
	i = 0;
	while ((size_t)i < ((size_t)n_str) && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
