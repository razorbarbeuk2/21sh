/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/15 18:21:21 by gbourson         ###   ########.fr       */
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

int exec_redir_LESSGREAT_RIGHT(t_data *data, t_token_node *node, unsigned int fork_state)//>
{
    t_token_struct *node_content_left;
    t_token_struct *node_content_right;
    int            fd;
    int            out;
    
    (void)fork_state;
    node_content_left = ((t_token_struct *)node->tleft->node->content);
    node_content_right = ((t_token_struct *)node->tright->node->content);
    ft_putendl("TEST ---------------------------");
    ft_putendl(node_content_left->token_name_str);
    ft_putendl(node_content_right->token_name_str);
    ft_putendl("--------------------------------");
    if (node)
    {
        if (exec_fork_step(data, FORK))
        {
            data->fork = FORK;
            fd = exec_redirect_option_OPEN(node_content_right, _TRUNC);
            out = exec_redirect_option_DIGIT(data, node->tleft);
            dup2(fd, out);
            close(fd);
            exec_cmd_type(data, node->tleft, UNFORK);
        }
    }
    return (0);
}

int exec_redir_LESSGREAT_LEFT(t_data *data, t_token_node *node_cur, unsigned int fork_state)//<
{
    (void)data;
    (void)node_cur;
    (void)fork_state;
    ft_putendl("exec_redir_LESSGREAT_LEFT");
    return (0);
}

int exec_redir_GREATAND(t_data *data, t_token_node *node, unsigned int fork_state)//>&
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_GREATAND");
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

int exec_redir_DGREAT(t_data *data, t_token_node *node, unsigned int fork_state)//>>
{
    t_token_struct *node_content_left;
    t_token_struct *node_content_right;
    int            fd;
    int            out;
    
    (void)fork_state;
    node_content_left = ((t_token_struct *)node->tleft->node->content);
    node_content_right = ((t_token_struct *)node->tright->node->content);
    if (node)
    {
        if (exec_fork_step(data, FORK))
        {
            data->fork = FORK;
            fd = exec_redirect_option_OPEN(node_content_right, _APPEND);
            out = exec_redirect_option_DIGIT(data, node->tleft);
            dup2(fd, out);
            close(fd);
            exec_cmd_type(data, node->tleft, UNFORK);
        }
    }
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