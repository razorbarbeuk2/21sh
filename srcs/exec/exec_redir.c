/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/19 19:00:36 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_redirect_option_DIGIT(t_data *data, t_token_node *node)
{   
    t_token_struct *node_content;
    
    (void)data;
    if (node->tright && node->tright->tright)
        node_content = ((t_token_struct *)node->tright->tright->node->content);
    if (node->tright)
        node_content = ((t_token_struct *)node->tright->node->content);
    else
        return (STDOUT_FILENO);
    return (ft_atoi(node_content->token_name_str));
}

int exec_redir_function_DUP_FROM(t_data *data, int fd, t_token_node *node)
{
    // fd = open("test", O_RDWR);
    data->fork = FORK;
    //(void)node;
    // dup2(STDIN_FILENO, fd);
    dup2(fd, STDIN_FILENO);
    // ft_putendl_fd("LOLILOL", STDOUT_FILENO);
    // write(STDIN_FILENO, "toto", 5);
    close(fd);
    exec_cmd_type(data, node->tleft, UNFORK);
    return (1);
}

int exec_redir_function_DUP_TO(t_data *data, int fd, t_token_node *node)
{
    int            out;

    data->fork = FORK;
    out = exec_redirect_option_DIGIT(data, node->tleft);
    dup2(fd, out);
    close(fd);
    exec_cmd_type(data, node->tleft, UNFORK);
    return (1);
}

int exec_redir_RIGHT(t_data *data, t_token_node *node, unsigned int fork_state)//>//>>//>&
{   
    t_token_struct *node_content;
    t_token_struct *node_content_right;
    int fd;

    fd = 0;
    (void)fork_state;
    if (node)
    {
        node_content = ((t_token_struct *)node->node->content);
        node_content_right = ((t_token_struct *)node->tright->node->content);
        if (exec_fork_step(data, FORK))
        {
            if (node_content->type == TYPE_REDIRECTION_LESSGREAT_RIGHT)
                fd = open(node_content_right->token_name_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            else if (node_content->type == TYPE_REDIRECTION_DGREAT)
                fd = open(node_content_right->token_name_str, O_WRONLY | O_CREAT | O_APPEND, 0644);
            else if (node_content->type == TYPE_REDIRECTION_GREATAND)
            {
                if (node_content_right->type == TYPE_IO_NUMBER)
                    fd = ft_atoi(node_content_right->token_name_str);
                else 
                    fd = open(node_content_right->token_name_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            }
            return (exec_redir_function_DUP_TO(data, fd, node));
        }
    }
    return (0);
}

int exec_redir_LEFT(t_data *data, t_token_node *node, unsigned int fork_state)//<//<<
{
    t_token_struct *node_content;
    t_token_struct *node_content_right;
    // int status;
    int fd;
    // int  p[2];
    // pid_t pid;

    fd = 0;
    (void)fork_state;
    if (node)
    {
        node_content = ((t_token_struct *)node->node->content);
        node_content_right = ((t_token_struct *)node->tright->node->content);
        if (exec_fork_step(data, FORK))
        {
            if (node_content->type == TYPE_REDIRECTION_LESSGREAT_LEFT)
                fd = open(node_content_right->token_name_str, O_RDWR | O_APPEND, 0644);
                // fd = open("/dev/tty", O_RDWR, 0644);
            if (node_content->type == TYPE_REDIRECTION_DLESS)
            {
                
            }
            return (exec_redir_function_DUP_FROM(data, fd, node));
        }
    }
    return (0);
}