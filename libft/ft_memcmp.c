/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:59:48 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/07 17:34:06 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					diff;
	int					i;
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	i = 0;
	diff = 0;
	while ((size_t)i < n)
	{
		if (t1[i] == t2[i])
		{
			i++;
		}
		else
		{
			diff = t1[i] - t2[i];
			return (diff);
		}
	}
	return (diff);
}
