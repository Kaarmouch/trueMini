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
static int	token_ctrl(char *line, t_bag **bag)
{
		build_tokens(line, bag);
		pipok(bag);
		clean_tok(bag);
		printtok(&(*bag)->tokens);
		return (0);
}

static int	minishell(t_bag **bag)
{
	char	*line;

	while (1)
	{
		line = readline("MY_minishell : ");
		if (!line)
		{
			clear_history();
			return (write(1, "exit\n", 5));
		}
		if (!is_empty_line(line))
			add_history(line);
		(*bag)->tokens = NULL;
		token_ctrl(line, bag);
		free(line);
		if ((*bag)->tokens)
			tokens_exe((*bag)->tokens, &(*bag)->env);
		free_tokens((*bag)->tokens);
	}
	clear_history();
	return (0);
}

int	main(int ac, char **av, char **ev)
{
	t_bag	*bag;

	(void)av;
	(void)ac;
	bag = malloc(sizeof(t_bag));
	if (!bag)
		return (1);
	bag->env = NULL;
	init_env(&(bag->env), ev);
	rl_catch_signals = 0;
	redirect_signals();
	minishell(&bag);
	free_env((bag->env));
	free(bag);
	return (0);
}
