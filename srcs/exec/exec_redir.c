/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/09 20:47:07 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_redir_LESSGREAT_RIGHT(t_data *data, t_token_node *node_cur, unsigned int fork_state)
{
    t_token_struct *node_content_left;
    t_token_struct *node_content_right;
    char           *str;
    int             fd;
    int             fd_files;
    
    (void)data;
    (void)fork_state;
    fd = 1;
    fd_files = 0;
    node_content_left = ((t_token_struct *)node_cur->tleft->node->content);
    node_content_right = ((t_token_struct *)node_cur->tright->node->content);
    if (node_content_left && node_content_right)
    {
        if ((str = ft_strrchr(node_content_left->token_name, ' ')) != NULL)
        {
            if (ft_isdigit(*(str + 1)))
                fd = ft_atoi(str + 1);
        }
        fd_files = open(node_content_right->token_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (exec_fork_step(data, FORK))
        {
            dup2(fd_files, STDOUT_FILENO);
            close(fd_files);
            exec_cmd_type(data, node_cur->tleft, 0);
        }
    }
    //ft_putendl(node_content_left->token_name);
    // exec_cmd_type(data, node->tleft, fork_state);
    // exec_cmd_type(data, node->tright, fork_state);
    //ft_putendl("exec_redir_LESSGREAT_RIGHT");
    return (0);
}

int exec_redir_LESSGREAT_LEFT(t_data *data, t_token_node *node, unsigned int fork_state)
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_LESSGREAT_LEFT");
    return (0);
}

int exec_redir_GREATAND(t_data *data, t_token_node *node, unsigned int fork_state)
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_GREATAND");
    return (0);
}

int exec_redir_LESSAND(t_data *data, t_token_node *node, unsigned int fork_state)
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_LESSAND");
    return (0);
}

int exec_redir_DGREAT(t_data *data, t_token_node *node, unsigned int fork_state)
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_DGREAT");
    return (0);
}

int exec_redir_DLESS(t_data *data, t_token_node *node, unsigned int fork_state)
{
    (void)data;
    (void)node;
    (void)fork_state;
    ft_putendl("exec_redir_DLESS");
    return (0);
}