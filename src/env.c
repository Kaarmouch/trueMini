/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <aglampor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/07 19:45:57 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env	*p)
{
	t_env	*tmp;
	
	while (p)
	{
		tmp = p->next;
		free(p->key);
		free(p->value);
		free(p);
		p = tmp;
	}
}

void	init_env(t_env **env, char **ev)
{
	char	**cpy_env;
	char	**tmp;

	cpy_env = ev;
	while (*cpy_env)
	{
		tmp = ft_split(*cpy_env, '=');
		ft_lstadd_back(env, ft_lstnew(tmp[0], tmp[1]));
		ft_free_split(tmp);
		cpy_env++;
	}
}
