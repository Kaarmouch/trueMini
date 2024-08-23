/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <aglampor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/23 18:49:51 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
#include <readline/readline.h>
#include <stdlib.h>


#define OPTION 1
#define DIRECTORY 2
#define FD 3
#define RIN 4
#define ROUT 5
#define RRIN 44
#define RROUT 55
#define BUILTIN 6
#define CMD 7
#define PIPE 8

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
int	is_redir(char *s);
int	is_builtin(char *s);
int	is_cmd(char *s, t_env *env);
int	ft_strlen(char *s);
void	ft_lstadd_back(t_env **alst, t_env *new);
t_env	*ft_lstnew(char *key, char *value);
char    *ft_strdup(char *str);
char	**splt_white(char *s);
char    *word_dup(char *str, int start, int finish);
char    *ft_strjoin_t(char *strt, char *mid, char *end);
t_env   *ft_lstlast(t_env *lst);
void	free_env(t_env	*p);
void    build_tokens(char *line, t_token **t, t_env *env);
void    ft_delnode_key(t_env **lst, char *key );
void	init_env(t_env **env, char **ev);
void	ft_free_split(char **split);
char	**ft_split(char *s, char c);
#endif
