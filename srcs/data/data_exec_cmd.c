/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/27 18:30:38 by gbourson         ###   ########.fr       */
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

static void reset_exec_cmd_character(t_data *data)
{
	if (!get_reset_prompt(data))
		print_error("Prompt error\n");
	return;
}

void print(t_token_node *st_node)
{
	if (!st_node)
		return;
	ft_putendl(((t_token_struct *)st_node->node->content)->token_name);
	if (st_node->tleft)
		ft_putstr("On va a gauche\n");
	print(st_node->tleft);
	if (st_node->tright)
		ft_putstr("On va a droite\n");
	print(st_node->tright);
}

void ft_print_token_t(unsigned int t)
{
	if (t == TYPE_DSEMI)
		ft_putendl("START TYPE DSEMI---------------");
	else if (t == TYPE_AND_IF)
		ft_putendl("START TYPE_AND_IF---------------");
	else if (t == TYPE_OR_IF)
		ft_putendl("START TYPE_OR_IF---------------");
	else if (t == TYPE_PIPE)
		ft_putendl("START TYPE_PIPE---------------");
	else if (t == TYPE_REDIRECTION_LESSGREAT_RIGHT)
		ft_putendl("START TYPE_REDIRECTION_LESSGREAT_R---------------");
	else if (t == TYPE_REDIRECTION_LESSGREAT_LEFT)
		ft_putendl("START TYPE_REDIRECTION_LESSGREAT_L---------------");
	else if (t == TYPE_REDIRECTION_GREATAND)
		ft_putendl("START TYPE_REDIRECTION_GREATAND---------------");
	else if (t == TYPE_REDIRECTION_LESSAND)
		ft_putendl("START TYPE_REDIRECTION_LESSAND---------------");
	else if (t == TYPE_REDIRECTION_DGREAT)
		ft_putendl("START TYPE_REDIRECTION_DGREAT---------------");
	else if (t == TYPE_REDIRECTION_DLESS)
		ft_putendl("START TYPE_REDIRECTION_DLESS---------------");
	else if (t == TYPE_CMD)
		ft_putendl("START TYPE_CMD---------------");
}

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

static void read_ast(t_data *data, t_token_node *node_cur, unsigned int fork_state)
{
	if (!node_cur)
		return;
	if (node_cur)
		exec_cmd_type(data, node_cur, fork_state);
}

void exec_cmd_character(t_data *data)
{
	t_token_node *node_tree;

	write(1, "\n", 1);
	node_tree = NULL;
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data);
	//ft_term_reset(data->term);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			print_error("historic error\n");
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str) != -1)
		{
			node_tree = construct_ast_tree(data->token_list, NULL, 1, node_tree);
			//print(node_tree);
			read_ast(data, node_tree, FORK);
		}
		return (reset_exec_cmd_character(data));
	}
	return (reset_exec_cmd_character(data));
}