/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:50 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/07 16:22:07 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*t_1;
	char		*t_2;

	i = 0;
	if (!dest && !src)
		return (0);
	t_1 = (char *)src;
	t_2 = (char *)dest;
	while (i < n)
	{
		t_2[i] = t_1[i];
		i++;
	}
	return (dest);
}
