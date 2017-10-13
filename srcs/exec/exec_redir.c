/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/13 18:21:12 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_redir_OPEN(t_data *data, char *token_name, int option)
{
    int     fd;
    char    **line;
    int     count;

    line = ft_split_in_command(data, token_name);
    count = ft_count_tab(line);
    if (ft_isdigit(line[count - 1][0]))
        fd = ft_atoi(line[count - 1]);
    else
    {
        if (option == TRUNC)
            fd = open(token_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (option == APPREND)
            fd = open(token_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
    }
    ft_free_char_array(&line);
    return (fd);
}

int exec_redir_LESSGREAT_RIGHT(t_data *data, t_token_node *node_cur, unsigned int fork_state)
{
    t_token_struct *node_content_left;
    t_token_struct *node_content_right;
    int            fd;
    char           **line;
    
    (void)fork_state;
    ft_putendl("\nREDIR");
    node_content_left = ((t_token_struct *)node_cur->tleft->node->content);
    node_content_right = ((t_token_struct *)node_cur->tright->node->content);
    if (node_content_left && node_content_right)
    {
        fd = exec_redir_OPEN(data, node_content_right->token_name, TRUNC);
        line = ft_split_in_command(data, node_content_left->token_name);
        if (exec_fork_step(data, line, FORK))
        {
            dup2(fd, STDOUT_FILENO);
            close(fd);
            exec_cmd_type(data, node_cur->tleft, UNFORK);
        }
    }
    return (0);
}

int exec_redir_LESSGREAT_LEFT(t_data *data, t_token_node *node_cur, unsigned int fork_state)
{
    (void)data;
    (void)node_cur;
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