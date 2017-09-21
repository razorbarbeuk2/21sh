/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:38:17 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/21 17:59:43 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec(t_data *data, t_token_node *cur)
{
    t_token_struct *cur_t;

    cur_t = NULL;
    cur_t = ((t_token_struct *)cur->node->content);
    ft_putendl(cur_t->token_name);
    return (parse_line_builtins(data, &data->env, &cur_t->token_name));
}