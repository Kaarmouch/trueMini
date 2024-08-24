/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:28:06 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/24 21:45:56 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"
int	find_pipe(t_token *t)
{
	int	i;
	t_token	*temp;

	i = 0
	temp = t;
	while (temp && temp->type != PIPE)
	{
		temp = temp->next;
		i++;
	}
	return (0);
}

int	add_myenv(t_token *toks, t_env **myenv) 
{
	printf("have to do\n");
}

int	print_export(t_env *e)
{
	t_env	*p1;
	int	cmp;

	p1 = e;
	while (p1)
	{
		p2 = p1->next;
		while (p2)
		{
			if (ft_cmp(p1, p1->next) > 0)
			{
				p1 = p2;
				break;
			}
			p2 = p2->next;
		}
		w_export(p1);
		p1 = p1->next;
	}
	return (0);
}
				
int	w_export(t_env *myenv)
{
	write(1, "declare -x ", 11);
	write(1 ,myenv->key, ft_strlen(myenv->key));
	if (myenv_value != NULL)
		write(1 ,myenv->value, ft_strlen(myenv->value));
	write(1, '\n', 1);
	return (0)
}


int	export(t_token *t, t_env **myEnv)
{
	int	nxt_pipe;
	int	err;

	nxt_pipe = find_pipe(t)
	if (nxt_pipe)
		err = add_myenv(t, myEnv);
	else
		err = print_export(*(myEnv));
	return (err);
}

