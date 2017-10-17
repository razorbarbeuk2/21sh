/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/17 12:52:23 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_redirect_option_OPEN(t_token_struct *token_struct, int option)
{
    int     fd;
    
    fd = 0;
    if (option == _TRUNC)
        fd = open(token_struct->token_name_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (option == _APPEND)
        fd = open(token_struct->token_name_str, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (option == _READ_INSIDE)
        fd = open(token_struct->token_name_str, O_RDONLY, 0644);
    return (fd);
}

int exec_redirect_option_DIGIT(t_data *data, t_token_node *node)
{   
    int     fd;
    t_token_struct *node_content_right;
    
    (void)data;
    fd = 0;
    if (node->tright && node->tright->tright)
        node_content_right = ((t_token_struct *)node->tright->tright->node->content);
    else if (node->tright)
        node_content_right = ((t_token_struct *)node->tright->node->content);
    else
        return (STDOUT_FILENO);
    return (ft_atoi(node_content_right->token_name_str));
}

int exec_redir_function_DUP_FROM(t_data *data, unsigned int OPTION, t_token_node *node)
{
    t_token_struct *node_content_right;
    int            fd;

    node_content_right = ((t_token_struct *)node->tright->node->content);
    if (node)
    {
        data->fork = FORK;
        if ((fd = exec_redirect_option_OPEN(node_content_right, OPTION)) == -1)
            return (-1);
        dup2(fd, STDIN_FILENO);
        close(fd);
        exec_cmd_type(data, node->tleft, UNFORK);
        return (1);
    }
    return (0);
}

int exec_redir_function_DUP_TO(t_data *data, unsigned int OPTION, t_token_node *node)
{
    t_token_struct *node_content_right;
    int            fd;
    int            out;

    node_content_right = ((t_token_struct *)node->tright->node->content);
    if (node)
    {
        data->fork = FORK;
        if ((fd = exec_redirect_option_OPEN(node_content_right, OPTION)) == -1)
            return (-1);
        out = exec_redirect_option_DIGIT(data, node->tleft);
        dup2(fd, out);
        close(fd);
        exec_cmd_type(data, node->tleft, UNFORK);
        return (1);
    }
    return (0);
}

int exec_redir_LESSGREAT_RIGHT(t_data *data, t_token_node *node, unsigned int fork_state)//>
{   
    (void)fork_state;
    if (node)
    {
        if (exec_fork_step(data, FORK))
            return (exec_redir_function_DUP_TO(data, _TRUNC, node));
    }
    return (0);
}

int exec_redir_DGREAT(t_data *data, t_token_node *node, unsigned int fork_state)//>>
{
    (void)fork_state;
    if (node)
    {
        if (exec_fork_step(data, FORK))
            return (exec_redir_function_DUP_TO(data, _APPEND, node));
    }
    return (0);
}

int exec_redir_LESSGREAT_LEFT(t_data *data, t_token_node *node, unsigned int fork_state)//<
{
    (void)fork_state;
    if (node)
    {
        if (exec_fork_step(data, FORK))
            return (exec_redir_function_DUP_FROM(data, _READ_INSIDE, node));
    }
    return (0);
}

int exec_redir_GREATAND(t_data *data, t_token_node *node, unsigned int fork_state)//>&
{
    (void)fork_state;
    if (exec_fork_step(data, FORK))
        return (exec_redir_function_DUP_TO(data, _TRUNC, node));
    return (0);
}

int exec_redir_LESSAND(t_data *data, t_token_node *node, unsigned int fork_state)//<&
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_LESSAND");
    return (0);
}



int exec_redir_DLESS(t_data *data, t_token_node *node, unsigned int fork_state)//<<
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_DLESS");
    return (0);
}