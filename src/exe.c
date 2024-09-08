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

#include "minishell.h"

int	ex_cmd(t_token	*ts, t_env **e)
{
	if (ts->type == CMD)
		printf("HAVE to code CMD\n");
	else if (!ft_cmp("export", ts->value[0]))
		return (ft_export(ts, e));
	else if (!ft_cmp("env", ts->value[0]))
		return (ft_env(ts, *e));
	else if (!ft_cmp("unset", ts->value[0]))
		return (ft_unset(ts->value, e));
	return (printf("CODE the nxt BUILTIN"));
}
