/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/21 18:48:51 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

typedef int (*function_token)(t_data *data, t_token_node *tleft, t_token_node *tright);

struct s_exec_token
{
	unsigned int 	t;
	function_token 	f;
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
	{TYPE_CMD, exec_CMD},
	{TYPE_FINISH, NULL}
};

static void 	reset_exec_cmd_character(t_data *data)
{
	if (!get_reset_prompt(data))
		print_error("Prompt error\n");
	return ;
}	

void	print(t_token_node *st_node)
{
	if (!st_node)
		return ;
	ft_putendl(((t_token_struct *)st_node->node->content)->token_name);
	if (st_node->tleft)
	ft_putstr("On va a gauche\n");
	print(st_node->tleft);
	if (st_node->tright)
	ft_putstr("On va a droite\n");
	print(st_node->tright);
}

static int exec_cmd_type(t_data *data, t_token_node *node_cur)
{
	int i;
	t_token_struct *node_content;

	i = 0;
	node_content = NULL;
	while (s_exec_t[i].t != TYPE_FINISH)
	{
		node_content = ((t_token_struct *)node_cur->node->content);
		if(s_exec_t[i].t == node_content->type)
			s_exec_t[i].f(data, node_cur->tleft, node_cur->tright);
		i++;
	}
	return (-1);
}

static void read_ast(t_data *data, t_token_node *node_cur)
{
	if (!node_cur)
		return ;
	if (node_cur->tleft)
		exec_cmd_type(data, node_cur->tleft);
	if (node_cur->tright)
		exec_cmd_type(data, node_cur->tright);
}

void exec_cmd_character(t_data *data)
{	
	t_token_node *node_tree;

	write(1, "\n", 1);
	node_tree = NULL;
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data);
	get_exe_path(data, &data->entry->line_str);
	print_error("NEXT\n");
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			print_error("historic error\n");
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str) != -1)
		{
			node_tree = construct_ast_tree(data->token_list, NULL, 1, node_tree);
			//print(node_tree);
			(node_tree && node_tree->tleft) ? read_ast(data, node_tree) : exec(data, node_tree);
		}
		return (reset_exec_cmd_character(data));
	}
	return (reset_exec_cmd_character(data));
}