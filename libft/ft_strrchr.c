/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:25:10 by aglampor          #+#    #+#             */
/*   Updated: 2023/10/10 17:50:46 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (t[i] != '\0')
		i++;
	while (t[i] != (unsigned char)c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return (t + i);
}
