/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_buildin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:59:06 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/26 16:55:10 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int     ft_export(t_token *t, t_env **myEnv)
{
        int     err;

        if (t->value[1])
                err = export_args(t, myEnv, 1);
        else
                err = export_no_arg(*(myEnv));
        return (err);
}

