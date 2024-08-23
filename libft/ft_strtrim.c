/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:43:11 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/12 16:40:12 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "stdio.h"

static int	ft_id_strt(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < (int)ft_strlen(set))
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_id_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = (int)ft_strlen(s1) - 1;
	while (i < (int)ft_strlen(set))
	{
		if (s1[j] == set[i])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static char	*ft_exit(void)
{
	char	*wrd;

	wrd = malloc(sizeof(char) * 1);
	wrd[0] = '\0';
	return (wrd);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		i;
	int		end;
	char	*wrd;

	start = ft_id_strt(s1, set);
	if (start == (int)ft_strlen(s1))
		return (ft_exit());
	i = 0;
	end = ft_id_end(s1, set);
	wrd = malloc(sizeof(char) * (end - start + 2));
	if (!wrd)
		return (0);
	while (i <= end - start)
	{
		wrd[i] = s1[start + i];
		i ++;
	}
	wrd[i] = '\0';
	return (wrd);
}
