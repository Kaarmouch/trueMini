/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:21:36 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/28 11:33:18 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*test_path(char **l_path, char *cmd)
{
	int	i;
	char	*test_path;

	i = 0;
	while (l_path[i])
	{
		test_path = ft_strjoin_t(l_path[i], "/", cmd);
		if (access(test_path, F_OK | X_OK) == 0)
		{
			ft_free_split(l_path);
			free(cmd);
			return (test_path);
		}
		free(test_path);
		i++;
	}
	free(cmd);
	ft_free_split(l_path);
	return (0);
}

char	*tru_path(char *ex_cmd, t_env *mev)
{
	char	**list_path;
	char	*path;

	while (mev && ft_cmp("PATH", mev->key))
		mev = mev->next;
	if (!mev)
		return (0);
	list_path = ft_split(mev->value, ':');
	path = test_path(list_path, ex_cmd);
	return (path);
}


char	**get_ex_env(t_env *ev)
{
	t_env	*tmp;
	char	**ex_ev;
	int		i;

	tmp = ev;
	ex_ev = malloc(sizeof(char*) * (ft_lstlast(tmp))->index + 2);
	if (!ex_ev)
		return (NULL);
	i = 0;
	while (tmp)
	{
		ex_ev[i] = ft_strjoin_t(tmp->key, "=", tmp->value);
		i++;
		tmp = tmp->next;
	}
	ex_ev[i] = 0;
	return (ex_ev);
}

void	redir (t_token *t, t_env **env)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		cmd_exe(t, env);
	}
}

int	tokens_exe(t_token *t, t_env **menv)
{
	if (t->next)
	{
		redir(t, menv);
		while (((t->next)->next)->next)
		{
			t = (t->next)->next;
			redir(t, menv);
		}
		if (t->value[0][0] != '|')
			cmd_exe(t, menv);
		else
			printf("Unknowed cmd !\n");
	}
	else
		cmd_exe(t, menv);
	return (0);
}

//s_exe va exe le token et redir si need avec un fic
int	cmd_exe(t_token *t, t_env **menv)
{
	if (t->fdin)
		dup2(t->fdin, 0);
	if (t->fdout)
		dup2(t->fdout, 1);	
	if (t->type == BUILTIN)
		return (exe_builtin(t, menv));
	else
		return (exe_shell(t, *menv));
	return (0);
}

int	exe_shell(t_token *t, t_env *menv)
{
	char	**exe_env;
	char	*t_path;

	exe_env = get_ex_env(menv);
	if (!find_c(t->value[0], '/'))
		t_path = t->value[0];
	else
		t_path = tru_path(t->value[0], menv);
	execve(t_path, t->value, exe_env);
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
