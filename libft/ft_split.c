/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:53:26 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/13 15:27:28 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_countwrd(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
		{
			count++;
			i++;
		}
		else if (s[i] != c && s[i - 1] == c)
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_split_splited(char const *s, char c, char **ttab)
{
	int		i;
	int		j;
	int		len_w;

	i = 0;
	j = 0;
	while (s[i])
	{
		len_w = 0;
		while (s[i + len_w] && s[i + len_w] != c)
			len_w++;
		if (len_w > 0)
		{
			ttab[j] = malloc(sizeof(char) * (len_w + 1));
			if (!ttab[j])
				return (0);
			ttab[j] = ft_strncpy(ttab[j], &s[i], len_w);
			i += len_w - 1;
			j++;
		}
		i++;
	}
	ttab[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ttab;
	int		is;

	ttab = malloc(sizeof(char *) *(ft_countwrd(s, c) + 1));
	if (!ttab)
		return (0);
	is = ft_split_splited(s, c, ttab);
	if (is)
		return (ttab);
	return (0);
}
