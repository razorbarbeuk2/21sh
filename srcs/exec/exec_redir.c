/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 19:22:18 by gbourson         ###   ########.fr       */
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

int exec_redirect_option_DIGIT(t_data *data, t_token_struct *token_struct)
{   
    int     fd;
    int     count;

    (void)data;
    fd = 0;
    count = 0;
    if (token_struct)
    {
        count = ft_count_tab(token_struct->token_name_tab);
        if (ft_isdigit(token_struct->token_name_tab[count - 1][0]))
        {
            fd = ft_atoi(token_struct->token_name_tab[count - 1]);
            ft_strdel(&token_struct->token_name_tab[count - 1]);
            token_struct->token_name_tab[count - 1] = NULL;
        }
        return (fd);
    }
    return (STDOUT_FILENO);
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
    if (node)
    {
        if (exec_fork_step(data, FORK))
        {
            data->fork = FORK;
            fd = exec_redirect_option_OPEN(node_content_right, _TRUNC);
            out = exec_redirect_option_DIGIT(data, node_content_left);
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
            out = exec_redirect_option_DIGIT(data, node_content_left);
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