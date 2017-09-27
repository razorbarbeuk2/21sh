/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:38:17 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/27 19:57:37 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int exec_state_exit(int state)
{
    if (state)
        exit(EXIT_SUCCESS);
    return (1);
}

int        fork_step(t_data *data, unsigned int fork_state)
{
    int             status;
    
    if (fork_state)
    {
        if ((data->pid = fork()) == -1)
            return (-1);
        if (!data->pid)
            return (1);
        else
		    waitpid(-1, &status, 0);
        return (0);
    }
    else
        return (1);
}

int        exec(t_data *data, t_token_node *cur, unsigned int fork_state)
{
    t_token_struct  *cur_t;
    char            **line;
    int             state;
    
    cur_t = NULL;
    line = NULL;
    state = 0;
    if (fork_step(data, fork_state))
    {
        cur_t = ((t_token_struct *)cur->node->content);
        line = ft_strsplit(cur_t->token_name, ' ');
        state = parse_line_builtins(data, &data->env, line);
        if (state)
            return (exec_state_exit(state));
        else
            return (1);
    }
    else
        return (1);
}