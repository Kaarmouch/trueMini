/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:22:37 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/31 20:37:06 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_type(char	*str)
{
	if (!find_c(str ,'>'))
	{
		if (str[1] && !(find_c(&str[1], '>')))
			return (RROUT);
		return (ROUT);
	}
	if (!find_c(str, '<'))
	{
		if (str[1] && !find_c(&str[1] ,'<'))
			return (RRIN);
		return (RRIN);
	}
	return (0);
}
static int	open_file(t_token *t, char *fic_name, int redir)
{
	int	fd;

	if (redir == RRIN || redir == RROUT)
		fd = open(fic_name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd = open(fic_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf(" la redir %d, value %d \n",redir, fd);
	return (fd);
}


static char	*one_wrd_redir(char *cmd)
{
	if (cmd[0] == '>')
	{
		if (cmd[1] && cmd[1] != '>')
			return (ft_strdup(&(cmd[1])));
		else if (cmd[1] == '>' && cmd[2])
			return (ft_strdup(&(cmd[2])));
	}
	if (cmd[0] == '<')
        {
                if (cmd[1] && cmd[1] != '<')
                        return (ft_strdup(&(cmd[1])));
		else if (cmd[1] == '<' && cmd[2])
			return (ft_strdup(&(cmd[2])));
        }
	return (NULL);
}

static void	refresh_tok(t_token **t, int idx, char *fic, int type_redir)
{
	int	fd;

	fd = open_file(fic, redir)
	if (type_redir == RIN || type_redir == RRIN)
	{
		if ((*t)->fdin)
			close(fd);
		(*t)->fdin = fd;
	}
	else if (type_redir == ROUT || type_redir == RROUT)
	{
		if ((*t)->fdin)
			close(fd);
                (*t)->fdout = fd;
	}
}
static char	**clean_redir(t_token **token)
{
	int	i;
	char	**stash;
	char	**tmp;
	int	nb_r;

	i = 0;
	nb_r = 0;
	tmp = (*token)->value;
	//count nb need alloc (len - nb redir find);
	while (tmp[i])
	{
		if (redir_type(tmp))
		{
			nb_r++;
			if (!one_wrd_redir(tmp))
			{
				nb_r++;
				i++;
			}
		i++;
	}
	if (!nb_r);
		return;
	stach = malloc(sizeof(char *) * (i + 2 - nb_r))
	while (*tmp)
	{
		if (redir_type(*tmp))
		{
			if (!one_wrd_redir(*tmp))
			{
				*tmp++;
			}
			*tmp++;
		}
		else
		{
			stash[j] = word_dup(*tmp, 0, ft_strlen(*tmp));
			*tmp++;
			j++;
		}
	}
	stash[j] = 0;
	free_split((*token)->value);
	return (stash)	
	}
	//duplicate wordbyword si non redir
	
}



//repalce selon la redir
void	remove_redir(t_token **ts)
{
	int	i;
	char	*fic_name;
	int	flag;
	int	redir;
	t_token		*tmp;

	tmp = *ts;
	while (*ts)
	{
		i = 0;
		flag = 0;
		while ((*ts)->value[i])
		{
			if ((redir = redir_type((*ts)->value[i])))
			{
				fic_name = one_wrd_redir((*ts)->value[i]);
				if(!fic_name && (*ts)->value[i + 1])
				{	
					i += 1;
					fic_name = ft_strdup((*ts)->value[i]);
				refresh_tok(&(*ts), i, fic_name, redir);
			}
			i++;
		(*ts)->value = clean_redir(&(*ts));
		}
		(*ts) = (*ts)->next;
	}
	*ts = tmp;
}
