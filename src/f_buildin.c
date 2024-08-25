/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_buildin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:59:06 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/25 20:30:50 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int     export(t_token *t, t_env **myEnv)
{
        int     nxt_pipe;
        int     err;

        nxt_pipe = find_pipe(t);
        if (nxt_pipe)
                err = add_myenv(t, myEnv);
        else
                err = build_export(*(myEnv));
        return (err);
}

