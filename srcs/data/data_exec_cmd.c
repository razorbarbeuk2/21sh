/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/11 19:35:22 by gbourson         ###   ########.fr       */
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
	{TYPE_CMD, exec},
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

static int reset_exec_cmd_character(t_data *data)
{
	term_init(data->term);
	if (!get_reset_prompt(data))
		return (ft_print_error("Prompt error"));
	return (1);
}

int exec_cmd_character(t_data *data)
{
	t_token_node *node_tree;

	N;
	node_tree = NULL;
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data);
	//ft_putendl(data->entry->line_str);
	term_reset(data->term);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			return (ft_print_error("historic error"));
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str) != -1)
		{
			node_tree = construct_ast_tree(data->token_list, NULL, 1, node_tree);
			if (node_tree)
				exec_cmd_type(data, node_tree, FORK);
		}
		return (reset_exec_cmd_character(data));
	}
	return (reset_exec_cmd_character(data));
}

// static void read_ast(t_data *data, t_token_node *node_cur)
// {
// 	if (!node_cur)
// 		return;
// 	if (node_cur)
// 		exec_cmd_type(data, node_cur, FORK);
// }
