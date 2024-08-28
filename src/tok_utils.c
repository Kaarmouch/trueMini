/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:48:54 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/28 14:53:42 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void    free_tokens(t_token  *p)
{
        t_token   *tmp;

        while (p)
        {
                tmp = p->next;
		ft_free_split(p->value);
                free(p);
                p = tmp;
        }
}

int	is_redir(char *str)
{
	if (!ft_cmp(">", str) || !ft_cmp("<", str) || !ft_cmp("|", str))
		return (1);
	else if (!ft_cmp(">>", str) || !ft_cmp("<<", str))
		return (2);
	return (0);
}


int	end_tok(char *s)
{
	int	i;

	if ((i = is_redir(s)))
		return (i);
	i = 0;
	while (s[i] && !(is_redir(&s[i + 1])))
		i++;
	return (i);
}

int	end_cmd(char *s)
{
	int	quote;
	int	i;

	i = 0;
	if ((quote = is_quote(s[i])))
		i++;
	while (s[i])
	{
		if (quote && s[i] == quote)
			return (i+1);
		if (!quote && ((is_quote(s[i])) || is_white(s[i])))
			return (i);
		i++;
	}
	return (i);
}


void	ft_addb_tok(t_token **p, t_token *new)
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

int	type_tok(char *s, t_env *env)
{
	int	val;

	printf("%d\n", s[0]);
	if ((val = open(s, O_RDONLY, 0776)) != -1)
	{
		close(val);
		return (FD);
	}
	else if (s[0] == 45)
		return (OPTION);
	else if (s[0] == '/')
		return (DIRECTORY);
	else if ((val = is_redir(s)) != 0)
		return (val);
	else if (is_builtin(s))
		return (BUILTIN);
	else if (is_cmd(s, env))
		return (CMD);
	return (0);
}

