/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:47:14 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/27 18:34:46 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_verif_line(char *line)
{
	int	i;
	int	sb;
	int	db;

	i = 0;
	sb = 0;
	db = 0;
	if (is_empty_line(line) == 1)
		return (0);
	while (line[i])
	{
		if (line[i] == 34)
			db++;
		if (line[i] == 39)
			sb++;
		i++;
	}
	if (sb % 2 == 1 || db % 2 == 1)
	{
		write(1, "bash : not interpreted unclosed quotes\n", 39);
		return (1);
	}
	return (0);
}

int	is_cmd(char *s, t_env *env)
{
	t_env	*path;
	int		i;
	char	**paths;
	char	*test_path;

	path = env;
	i = 0;
	while (ft_cmp("PATH", path->key) != 1)
		path = path->next;
	paths = ft_split(path->value, ':');
	while (paths[i])
	{
		test_path = ft_strjoin_t(paths[i], "/", s);
		if (access(test_path, F_OK | X_OK) == 0)
		{
			free(paths);
			free(test_path);
			return (1);
		}
		free(test_path);
		i++;
	}
	free(paths);
	return (0);
}

int	is_builtin(char *s)
{
	if (!ft_cmp("echo", s) || !ft_cmp("cd", s) || !ft_cmp("pwd", s))
		return (1);
	if (!ft_cmp("export", s) || !ft_cmp("unset", s) || !ft_cmp("env", s))
		return (1);
	return (0);
}

int	t_redir(char *s)
{
	if (!ft_cmp("<", s))
		return (RIN);
	if (!ft_cmp("<<", s))
		return (RRIN);
	if (!ft_cmp(">", s))
		return (ROUT);
	if (!ft_cmp(">>", s))
		return (RROUT);
	if (!ft_cmp("|", s))
		return (PIPE);
	return (0);
}
