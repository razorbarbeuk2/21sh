/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:38:17 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/21 23:45:11 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec(t_data *data, t_token_node *cur)
{
    t_token_struct  *cur_t;
    char            **line;

    cur_t = NULL;
    line = NULL;
    cur_t = ((t_token_struct *)cur->node->content);
    line = ft_strsplit(cur_t->token_name, ' ');
    return (parse_line_builtins(data, &data->env, line));
}