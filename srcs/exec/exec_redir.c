/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/20 16:07:32 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_redirect_option_DIGIT(t_data *data, t_token_node *node)
{
    t_token_struct *node_content;

    (void)data;
    if (node->tright && node->tright->tright)
    {
        ft_putendl("TETE DE MORT CONNARD");
        node_content = ((t_token_struct *)node->tright->tright->node->content);
    }
    if (node->tright)
        node_content = ((t_token_struct *)node->tright->node->content);
    else
        return (STDOUT_FILENO);
    return (ft_atoi(node_content->token_name_str));
}

int exec_redir_function_DUP_FROM(t_data *data, int fd, t_token_node *node)
{
    data->fork = FORK;
    dup2(fd, STDIN_FILENO);
    close(fd);
    exec_cmd_type(data, node->tleft, UNFORK);
    return (1);
}

int exec_redir_function_DUP_TO(t_data *data, int fd, t_token_node *node)
{
    int out;

    data->fork = FORK;
    out = exec_redirect_option_DIGIT(data, node->tleft);
    dup2(fd, out);
    close(fd);
    exec_cmd_type(data, node->tleft, UNFORK);
    return (1);
}

int exec_redir_RIGHT(t_data *data, t_token_node *node, unsigned int fork_state) //>//>>//>&
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
                    return (ft_print_ambiguous_redirect(node_content_right->token_name_tab[0]));
                    // fd = open(node_content_right->token_name_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            }
            return (exec_redir_function_DUP_TO(data, fd, node));
        }
    }
    return (0);
}

int exec_redir_LEFT(t_data *data, t_token_node *node, unsigned int fork_state) //<//<<
{
    t_token_struct *node_content;
    t_token_struct *node_content_right;
    char *line;
    int fd;
    int p[2];

    fd = 0;
    line = NULL;
    (void)fork_state;
    if (node)
    {
        node_content = ((t_token_struct *)node->node->content);
        node_content_right = ((t_token_struct *)node->tright->node->content);
        if (exec_fork_step(data, FORK))
        {
            if (node_content->type == TYPE_REDIRECTION_LESSGREAT_LEFT)
                fd = open(node_content_right->token_name_str, O_RDONLY, 0644);
            if (node_content->type == TYPE_REDIRECTION_DLESS)
            {
                pipe(p);
                get_heredoc_prompt(data);
                while (get_next_line(STDIN_FILENO, &line))
                {
                    if (ft_strcmp(node_content_right->token_name_str, line) == 0)
                        break;
                    ft_putendl_fd(line, p[1]);
                    ft_strdel(&line);
                    get_heredoc_prompt(data);
                }
                fd = p[0];
                close(p[1]);
            }
            return (exec_redir_function_DUP_FROM(data, fd, node));
        }
    }
    return (0);
}