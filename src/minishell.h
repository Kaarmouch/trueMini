/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <aglampor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/22 18:14:07 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>

#include <readline/readline.h>
#include <stdlib.h>

typedef struct	s_token
{
	char	*value;
	int		type;
	struct	s_token	*next;
}		t_token;

typedef struct	s_environement
{
	char	*key;
	char	*value;
	struct	s_environement *next;
}		t_env;

int     ft_cmp(char *o, char *t);
int     is_white(char c);
void	ft_lstadd_back(t_env **alst, t_env *new);
t_env	*ft_lstnew(char *key, char *value);
char    *ft_strdup(char *str);
char	**splt_white(char *s);
char    *word_dup(char *str, int start, int finish);
t_env   *ft_lstlast(t_env *lst);
void	free_env(t_env	*p);
void    build_tokens(char *line, t_token **t);
void    ft_delnode_key(t_env **lst, char *key );
void	init_env(t_env **env, char **ev);
void	ft_free_split(char **split);
char	**ft_split(char *s, char c);
int	ft_strlen(char *s);
#endif
