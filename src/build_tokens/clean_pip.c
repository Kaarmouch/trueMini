/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_pip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:20:48 by acoste            #+#    #+#             */
/*   Updated: 2024/08/28 14:43:40 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	pipok(t_bag **bag)
{
	int		flag;
	int		i;
	char	*n_line;
	t_token	*t;

	i = 0;
	t = (*bag)->tokens;
	while (t)
	{
		if ((i % 2) && t->type == PIPE )
			flag = 0;
		else
			flag = 1;
		t = t->next;
		i++;
	}
	if (!flag)
	{
		n_line = readline("> ");
		build_tokens(n_line, bag);
		free(n_line);
		pipok(bag);
	}
}

void	cleanpip(t_token **t)
{
	t_token	*to;
	t_token	*tmp;

	to = (*t);
	while (to)
	{
		tmp = to->next;
		if (tmp &&tmp->type == PIPE)
		{
			to->next = tmp->next;
			free(tmp);
		}
		to = to->next;
	}
}
