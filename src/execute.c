/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:21:36 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/28 11:33:18 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int      cmd_exe(t_token *t, t_env **menv)
{
	int	out;

        if (t->fdin)
                dup2(t->fdin, 0);
        if (t->fdout)
                dup2(t->fdout, 1);
        if (t->type == BUILTIN)
                out = exe_builtin(t, menv);
        else
                out = exe_shell(t, *menv);
	if (t->fdin)
		close(t->fdin);
        if (t->fdout)
                close(t->fdout);
        return (out);
}

int	tokens_exe(t_token *t, t_env **env)
{
	pid_t	pid;
	int		**pipefd;
	int		nb_tok;
	int		i;

	nb_tok = nb_token(t);
	i = 0;
	if(!t->next && t->type == BUILTIN)
			return (exe_builtin(t, env));
	pipefd = build_pipe(nb_tok);
	while (t)
	{
		pid = fork();
		if (pid == -1)
			return (1);
		if (!pid)
		{
			handle_pip(pipefd, i);
			free_pipes(pipefd);;
			cmd_exe(t, env);
			exit(1);
		}
		t = t->next;
		i++;
	}
	daddy_rout(pipefd, nb_tok, pid);
	return (0);
}

int	exe_shell(t_token *t, t_env *menv)
{
	char	**exe_env;
	char	*t_path;

	exe_env = get_ex_env(menv);
	if (!find_c(t->value[0], '/'))
	{
		if (!(access(t->value[0], F_OK | X_OK)))
			t_path = t->value[0];
		else
		{
			ft_free_split(exe_env);
			return (1);
		}
	}
	else
		t_path = tru_path(t->value[0], menv);
	if (t_path)
		execve(t_path, t->value, exe_env);
	ft_free_split(exe_env);
	return (0);
}

int	exe_builtin(t_token *ts, t_env **e)
{
	if (!ft_cmp("export", ts->value[0]))
		return (ft_export(ts, e));
	else if (!ft_cmp("env", ts->value[0]))
		return (ft_env(ts, *e));
	else if (!ft_cmp("unset", ts->value[0]))
		return (ft_unset(ts->value, e));
	return (printf("CODE the nxt BUILTIN"));
}
