/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:38:17 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 19:26:58 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

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
        return (0);
    }
    return (-1);
}

int			exec_parse_builtins(t_data *data, char **line, unsigned int fork_state)
{
	int result;

    result = 0;
	if ((result = exec_builtins_parsing(data, line)))
		return (result);
	else
	{
        if (exec_get_path(data, &line[0]))
        {
            if (exec_fork_step(data, fork_state))
                 exec_get_access(data, line);
        }
    }
    return (0);
}

int        exec_execute(t_data *data, t_token_node *cur, unsigned int fork_state)
{
    t_token_struct  *cur_token;
    
    cur_token = ((t_token_struct *)cur->node->content);
    //print_tab(data, cur_token->token_name_tab);
    exec_parse_builtins(data, cur_token->token_name_tab, fork_state);
    return (1);
}