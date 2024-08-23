/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:21:27 by acoste            #+#    #+#             */
/*   Updated: 2024/08/23 21:21:57 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signal)
{
	(void)signal;
	if (waitpid(-1, NULL, WNOHANG) == -1)
	{
		write(1, "^C", 2);
		print_line();
	}
}

void	sigquit_handler(int signal)
{
	(void)signal;
}

void	redirect_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}