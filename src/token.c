/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:16:34 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/31 17:34:42 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free(l_child);
	new->type = type_tok(new->value[0], (*bag)->env);
	new->next = 0;
	new->fdin = 0;
	new->fdout = 0;
	ft_addb_tok(&((*bag)->tokens), new);
	return (j);
}
static void	clean_tok(t_bag **bag)
{
	//remouve quote first ?
	//get_localv(bag); //change tout les $xx pour 0 si non existant ou par value
	remove_redir(&(*bag)->tokens);
}

void	printtok(t_token **t)
{
	t_token	*temp;
	int	i;

	temp = *t;
	while (temp)
	{
		printf("\nNV TOKEN\n");
		i = 0;
		while (temp->value[i])
		{
			printf("value %s\n", temp->value[i]);
			i++;
		}
		printf("type %d\nfdin %i\nfdout %i\n", temp->type, temp->fdin, temp->fdout);
		temp = temp->next;
	}
}

void	build_tokens(char *line, t_bag **bag)
{
	int	i;

	i = 0;
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
