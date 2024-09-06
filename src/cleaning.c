#include "minishell.h"

static int	redir_type(char	*str)
{
	if (!c_find(str ,">"))
	{
		if (ft_cmp(str,">") && !(c_find(&str[1], '>')))
			return (RROUT)
		return (ROUT);
	}
	if (!ft_cmp("<", str))
	{
		if (ft_cmp(str, "<") && !c_find(&str[i] ,'<'))
			return (RRIN)
		return (RRIN);
	}
	return (0);
}

static char	*one_wrd_redir(char *token)
{
	int	i;

	i = 0;
	while (token[i] == '>')
	{
		i++;
		if (token[i] && token[i] != '>')
			return (ft_strdup(&(token[i])))
	}
	while (token[i] == '<')
        {
                i++;
                if (token[i] && token[i] != '<')
                        return (ft_strdup(&(token[i])))
        }
	return (NULL);
}

void	refresh_tok(t_token **t, int fd, int type_redir)
{
	if (type_redir == RIN || type_redir == RRIN)
		(*t)->fdin = fd;
	else if (type_redir == RIN || type_redir == RRIN)
                (*t)->fdin = fd;
}

//repalce selon la redir
void	remove_redir(t_token **ts)
{
	char	*fic_name;
	t_token		*tmp;
	int	last_fd;
	int	redir;
	int	i;

	j = 0;
	tmp = *ts;
	while (*ts)
	{
		i = 0;
		while ((*ts)->value[i])
		{
			if ((redir = fic_redir((*ts)->value[i])))
			{
				fic_name = one_wrd_redir((*ts)->value[i]);
				if(!fic_name && (*ts)->value[i + 1])
					fic_name = ft_strdup((*ts)->value[i + 1]);
				last_fd = open_file(fic_name, redir);
				refresh_tok(&(*ts), last_fd, redir);
			}
			i++;
		}
		(*ts) = (*ts)->next;
	}
	*ts = tmp;
}
