/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/23 17:41:30 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		build_tokens(line, &toks);
	}
}

int	main(int ac, char **av, char **ev)
{
	t_env		*env;

	(void)ac;
	(void)av;
	env = NULL;
	init_env(&env, ev);
	minishell(env);
	free_env(env);
	return (0);
}
