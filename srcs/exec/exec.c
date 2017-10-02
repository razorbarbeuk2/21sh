/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:38:17 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/02 10:40:00 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int       exec_exit(int fork_state)
{
    if (fork_state)
        exit(EXIT_SUCCESS);
    return (1);
}

int        exec_fork_step(t_data *data, unsigned int fork_state)
{   
    int status;

    status = 0;
    if (fork_state)
    {
        if ((data->pid = fork()) == -1)
            return (ft_print_error("FORK ERROR"));
        if (!data->pid)
            return (1);
        else
		    waitpid(-1, &status, 0);
    }
    return (0);
}

int        exec(t_data *data, t_token_node *cur, unsigned int fork_state)
{
    t_token_struct  *cur_t;
    char            **line;
    
    cur_t = NULL;
    line = NULL;
    cur_t = ((t_token_struct *)cur->node->content);
    line = ft_strsplit(cur_t->token_name, ' ');
    exec_parse_line_builtins(data, line, fork_state);
    return (1);
}