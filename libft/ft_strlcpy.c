/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:22:17 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/06 11:07:15 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*t;

	t = (char *)src;
	i = 0;
	if (size > 0)
	{
		while (t[i] && i < size - 1)
		{
			dst[i] = t[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (t[i])
		i++;
	return (i);
}
