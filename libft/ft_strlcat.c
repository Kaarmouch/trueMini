/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:00:08 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/12 17:35:07 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*t;

	t = (char *)src;
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (size <= i)
		return (size + ft_strlen(src));
	while (t[j] && (j + i < size - 1))
	{
		dst[i + j] = t[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
