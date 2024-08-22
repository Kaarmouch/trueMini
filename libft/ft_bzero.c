/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:09:49 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/06 11:05:03 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*t;

	t = (char *)(s);
	i = 0;
	while (i < n)
	{
		t[i] = 0;
		i += 1;
	}
}
