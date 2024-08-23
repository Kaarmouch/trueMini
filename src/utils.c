/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:27 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/23 17:52:40 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_cmp(char *o, char *t)
{
	int	i;

	i = 0;
	while (o[i])
	{
		if (o[i] != t[i])
			return (0);
		i++;
	}
	if(t[i])
		return (0);
	return (1);
}

char    *ft_strdup(char *str)
{
        char    *dup;
        int     i;

        i = 0;
        dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
        if (!(dup))
                return (NULL);
        while (str[i])
        {
                dup[i] = str[i];
                i++;
        }
        dup[i] = '\0';
        return (dup);
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
	if (ft_cmp("echo", s) || ft_cmp("cd", s) || ft_cmp("pwd", s))
		return (1);
	if (ft_cmp("export", s) || ft_cmp("unset", s) || ft_cmp("env", s))
		return (1);
	if (ft_cmp("exit", s))
		return (1);
	return (0);
}

int	is_redir(char *s)
{
	if (ft_cmp("<", s))
		return (RIN);
	if (ft_cmp("<<", s))
		return (RRIN);
	if (ft_cmp(">", s))
		return (ROUT);
	if (ft_cmp(">>", s))
		return (RROUT);
	if (ft_cmp("|", s))
		return (PIPE);
	return (0);
}
