/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:38:17 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/13 17:40:25 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int        exec_fork_step(t_data *data, char **line, unsigned int fork_state)
{   
    int status;

    (void)line;
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

int			exec_parse_builtins(t_data *data, char **line, int fork_state)
{
	int result;

    result = 0;
	if ((result = exec_builtins_parsing(data, line)))
		return (result);
	else
	{
        exec_get_path(data, &line[0]);
        if (exec_fork_step(data, line, fork_state))
             exec_get_access(data, line);
    }
    return (0);
}

int        exec_execute(t_data *data, t_token_node *cur, unsigned int fork_state)
{
    t_token_struct  *cur_token;
    char            **line;
    
    cur_token = ((t_token_struct *)cur->node->content);
    line = ft_split_in_command(data, cur_token->token_name);
    exec_parse_builtins(data, line, fork_state);
    ft_free_char_array(&line);
    return (1);
}