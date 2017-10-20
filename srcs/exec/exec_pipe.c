/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:38 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/20 14:43:07 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_PIPE(t_data *data, t_token_node *node, unsigned int fork_state)
{
    int p[2];
    pid_t pid;

    (void)fork_state;
    if (exec_fork_step(data, FORK))
    {
        data->fork = FORK;
        pipe(p);
        if ((pid = fork()) == -1)
            return (-1);
        if (pid)
        {           
            close(p[1]);
            dup2(p[0], STDIN_FILENO);
            close(p[0]);
            exec_cmd_type(data, node->tright, UNFORK);
        }
        else
        {
            close(p[0]);
            dup2(p[1], STDOUT_FILENO);
            close(p[1]);
            exec_cmd_type(data, node->tleft, UNFORK);
        }
    }
    return (1);
}