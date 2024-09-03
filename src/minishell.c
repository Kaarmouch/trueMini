/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/09/03 17:46:23 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	minishell(t_bag **bag)
{
	char	*line;

	while (1)
	{
		line = readline("MY_minishell : ");
		if (!line || !ft_cmp("exit", line))
		{
			write(1, "exit\n", 5);
			clear_history();
			break ;
		}
		if (is_empty_line(line) == 0)
			add_history(line);
		(*bag)->tokens = NULL;	//fonction reset_token(bag->tokens) qui free (et pointe vers null)
		build_tokens(line, bag);
	/*	if (!is_pipe(toks))
			s_exe(toks, env);
		else
			write(1, "JE GG PA I A D PIPE\n", 20);*/
		free_tokens((*bag)->tokens);

	}
	clear_history();
	return (0);
}

int	s_exe(t_token *ts, t_env **e)
{
	if (!ts)
		return (0);
	if (ts->type == BUILTIN || ts->type == CMD)
		return (ex_cmd(ts, e));
	else
		write(1, "Reflexion++\n", 12);
	return (0);
}

int	main(int ac, char **av, char **ev)
{
	t_bag	*bag;

	(void)av;
	if (!(bag = malloc(sizeof(t_bag))))
		return (100);
	bag->env = NULL;
	init_env(&(bag->env), ev);
	rl_catch_signals = 0;
	redirect_signals();
	minishell(&bag);
	free(bag);
	return (ac);
}
