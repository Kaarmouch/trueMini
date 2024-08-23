/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:54:09 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/05 18:54:14 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			n;

	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	n = 0;
	if (!ptr1 && !ptr2)
		return (0);
	if ((size_t)ptr2 > (size_t)ptr1)
	{
		while (len-- > 0)
			ptr2[len] = ptr1[len];
	}
	else
	{
		while (n < len)
		{
			ptr2[n] = ptr1[n];
			n++;
		}
	}
	return (ptr2);
}
