/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/23 21:23:35 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*print_line(void)
{
	char	*line;

	line = readline("MY_minishell : ");
	if (is_empty_line(line) == 0)
		add_history(line);
	if (*line == 4)
	{
		write(1, "exit", 4);
		return(0);
	}
	return (line);
}
static void	minishell(t_env *env)
{
	char	*line;
	t_token	*toks;
	int		run;

	run = 1;
	while (run)
	{
		line = print_line();
		toks = NULL;
		build_tokens(line, &toks, env);
	}
	clear_history();
}

int	main(int ac, char **av, char **ev)
{
	t_env		*env;

	(void)ac;
	(void)av;
	env = NULL;
	init_env(&env, ev);
//	redirect_signals();
	minishell(env);
	free_env(env);
	return (0);
}
