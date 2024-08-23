/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/23 19:43:25 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	redirect_signals(void)
{
	signal(SIGINT, )
}
*/
static void	minishell(t_env *env)
{
	char	*line;
	t_token	*toks;
	int		run;

	(void)env;
	run = 1;
	while (run)
	{
		toks = NULL;
		line = readline("MY_minishell : ");
		if (line || !is_empty_line(line))
			add_history(line);
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
	//redirect_signals(); // TODO alexis
	minishell(env);
	free_env(env);
	return (0);
}
