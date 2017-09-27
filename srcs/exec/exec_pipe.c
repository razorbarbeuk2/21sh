/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:38 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/27 15:59:03 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_PIPE(t_data *data, t_token_node *node, unsigned int fork_state)
{
    (void)data;
    (void)node;
    (void)fork_state;
    // if fork (je rapelle la fct forké)
    //exec_cmd_type(data, node->tright, 1);
    //   exec_cmd_type(data, node->tleft, 0);
    ft_putendl("exec_pipe");
    return (0);
}