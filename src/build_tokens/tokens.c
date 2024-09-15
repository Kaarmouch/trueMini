/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:16:34 by aglampor          #+#    #+#             */
/*   Updated: 2024/09/03 16:54:43 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	bt_u(char *l, t_bag **bag)
{
	int		j;
	char	*l_child;
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (-1);
	j = end_tok(l);
	l_child = word_dup(l, 0, j);
	new->value = split_input(l_child);
	new->type = type_tok(new->value[0], (*bag)->env);
	new->next = 0;
	new->fdin = 0;
	new->fdout = 0;
	ft_addb_tok(&((*bag)->tokens), new);
	return (j);
}
static void	clean_tok(t_bag **bag)
{
	t_token	*tok;

	printf("Cleaning !!\n");
	remove_redir(&(*bag)->tokens);
	tok = (*bag)->tokens;
	while (tok)
	{
		remove_quote(&(tok));
		tok = tok->next;
	}
}

void	printtok(t_token **t)
{
	t_token	*tmp;
	int	i;

	tmp = *t;
	while (tmp)
	{
		printf("\n   NV TOKEN\n");
		i = 0;
		while (tmp->value[i])
		{
			printf("value %s\n", tmp->value[i]);
			i++;
		}
		printf("type %d\n",tmp->type);
		tmp = tmp->next;
	}
}

void	build_tokens(char *line, t_bag **bag)
{
	int	i;

	i = 0;
	if (!ft_verif_line(line))
		return ;
	while (line[i] && i < ft_strlen(line))
	{
		while (is_white(line[i]))
			i++;
		if (line[i])
			i += bt_u(&line[i], bag);
	}
	clean_tok(bag);
	printtok(&(*bag)->tokens);
}
