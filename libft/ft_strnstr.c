/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:03:00 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/12 16:32:31 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!l[i])
		return ((char *)b);
	while (b[i] && i < len)
	{
		j = 0;
		while (l[j] && (l[j] == b[j + i]) && (i + j) < len)
			j++;
		if (l[j] == '\0')
			return ((char *)&b[i]);
		i++;
	}
	return (0);
}
