/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:29:01 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/13 15:45:56 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, long unsigned int n)
{
	char				*t;
	long unsigned int	i;

	t = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)t[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
