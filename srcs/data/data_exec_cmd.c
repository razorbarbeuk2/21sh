/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/20 11:33:50 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

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

void exec_cmd_character(t_data *data)
{	
	t_token_node *node_tree;

	write(1, "\n", 1);
	node_tree = NULL;
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			print_error("historic error\n");
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str))
		{
			node_tree = check_construct_token_tree(data->token_list, NULL, 1, node_tree);
			print(node_tree);
		}
		else
		{
			if (!get_reset_prompt(data))
				print_error("Prompt error\n");
		}
	}
	if (!get_reset_prompt(data))
		print_error("Prompt error\n");
	return;
}