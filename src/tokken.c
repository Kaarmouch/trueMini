/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokken.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:16:34 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/22 19:59:36 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_addb_tok(t_token **p, t_token *new)
{
	t_token	*temp;

	if (!*p)
		*p = new;
	else
	{
		temp = *p;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

static int	end_tok(char *s)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (s[i] == 39 || s[i] == 34)
	{
		flag = (int)s[i];
		i++;
	}
	while (s[i])
	{
		if (flag == 0 && (is_white(s[i]) || s[i] == 39 || s[i] == 34))
		       return (i);
		if (flag && s[i] == flag)
			return (i + 1);
		i++;
	}
	return (i);
}

static int	bt_u(char *l, t_token **t)
{
        int     i;
        int     j;;
        t_token *new;

        i = 0;
        new = (t_token *)malloc(sizeof(t_token));
        if (!new)
                return (-1);
        j = end_tok(l);
        new->value = word_dup(l, 0, j);
        //new->type = test_tok(new->value);
	new->next = 0;
	ft_addb_tok(t, new);
	return (j);
}

void	printtok(t_token **t)
{
	t_token *temp;
	temp = *t;
	while (temp)
	{
		printf("val %s\n",temp->value);
		temp = temp->next;
	}
}

void    build_tokens(char *line, t_token **t)
{
        int     i;

        i = 0;
        while (line[i] && i < ft_strlen(line))
        {
                while (is_white(line[i]))
                        i++;
		if (line[i])
			i += bt_u(&line[i], t);
        }
	printtok(t);
}
