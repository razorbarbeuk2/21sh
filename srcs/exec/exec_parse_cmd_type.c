/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_cmd_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:16:11 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 17:58:53 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

typedef int (*function_token)(t_data *data, t_token_node *node, unsigned int fork_state);

struct s_exec_token
{
	unsigned int t;
	function_token f;
};

static const struct s_exec_token s_exec_t[] = {
	{TYPE_DSEMI, exec_DSEMI},
	{TYPE_AND_IF, exec_AND_IF},
	{TYPE_OR_IF, exec_OR_IF},
	{TYPE_PIPE, exec_PIPE},
	{TYPE_REDIRECTION_LESSGREAT_RIGHT, exec_redir_LESSGREAT_RIGHT},
	{TYPE_REDIRECTION_LESSGREAT_LEFT, exec_redir_LESSGREAT_LEFT},
	{TYPE_REDIRECTION_GREATAND, exec_redir_GREATAND},
	{TYPE_REDIRECTION_LESSAND, exec_redir_LESSAND},
	{TYPE_REDIRECTION_DGREAT, exec_redir_DGREAT},
	{TYPE_REDIRECTION_DLESS, exec_redir_DLESS},
	{TYPE_CMD, exec_execute},
	{TYPE_FINISH, NULL}};

int exec_cmd_type(t_data *data, t_token_node *node_cur, unsigned int fork_state)
{
	int i;
	t_token_struct *node_content;

	i = 0;
	node_content = NULL;
	while (s_exec_t[i].t != TYPE_FINISH)
	{
		node_content = ((t_token_struct *)node_cur->node->content);
		if (s_exec_t[i].t == node_content->type)
			s_exec_t[i].f(data, node_cur, fork_state);
		i++;
	}
	return (-1);
}