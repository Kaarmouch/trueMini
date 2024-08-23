/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:15:07 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/13 17:57:20 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_lenint(int nb)
{
	int	len;

	len = 0;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		len++;
	}
	if (nb < 10 && nb > -10)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void	ft_putnbr(int nb, char *nbstr, int len)
{
	int	end;

	end = 0;
	nbstr[len] = '\0';
	len--;
	if (nb < 0)
	{
		nb = -nb;
		nbstr[0] = '-';
		end = 1;
	}
	while (len >= end)
	{
		if (nb >= 0 && nb < 10)
		{
			nbstr[len] = nb + '0';
			len--;
		}
		else
		{
			nbstr[len] = (nb % 10) + '0' ;
			nb = nb / 10;
			len--;
		}
	}
}

static char	*ft_go(void)
{
	char	*go;

	go = malloc(sizeof(char) * 12);
	if (!go)
		return (0);
	ft_strlcpy(go, "-2147483648", 12);
	return (go);
}

char	*ft_itoa(int n)
{
	int		nblen;
	char	*nbr;

	nblen = 0;
	if (n == -2147483648)
	{
		return (ft_go());
	}
	if (n < 0)
	{
		nblen = 1;
	}
	nblen += ft_lenint((unsigned int)n);
	nbr = malloc(sizeof(char) * nblen + 1);
	if (!nbr)
		return (0);
	ft_putnbr(n, nbr, nblen);
	return (nbr);
}
