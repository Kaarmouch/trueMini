/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/22 20:04:49 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>

//token
typedef struct	s_token
{
	char	*value;
	int		type;
	struct	s_token	*next;
}		t_token;

//env
typedef struct	s_environement
{
	char	*key;
	char	*value;
	struct	s_environement *next;
}		t_env;

//build_ft
void	ft_lstadd_back(t_env **alst, t_env *new);
t_env	*ft_lstnew(char *key, char *value);
t_env	*ft_lstlast(t_env *lst);
void	ft_delnode_key(t_env **lst, char *key );



//env
void	free_env(t_env	*p);
void	init_env(t_env **env, char **ev);


//exit
void	m_exit(int code, char *val);

//ft_split
char	**ft_split(char *s, char c);
void	ft_free_split(char **split);
int		ft_strlen(char *s);

//tokken
void	printtok(t_token **t);
void	build_tokens(char *line, t_token **t);

//minishell

//split_ws
char	**splt_white(char *s);
int		is_white(char c);
char	*word_dup(char *str, int start, int finish);

//utils
int		ft_cmp(char *o, char *t);
char	*ft_strdup(char *str);


//utils2


#endif
