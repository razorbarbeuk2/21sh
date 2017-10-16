/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/16 15:36:25 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int reset_exec_cmd_character(t_data *data)
{
	term_init(data->term);
	if (!get_reset_prompt(data))
		return (ft_print_error("Prompt error"));
	return (1);
}

int 		exec_cmd_character(t_data *data)
{
	t_token_node *node_tree;
	char 			*str;

	N;
	str = NULL;
	node_tree = NULL;
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data, data->entry->line);
	term_reset(data->term);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			return (ft_print_error("historic error"));
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str) != -1)
		{
			ft_print_token(&data->token_list);
			node_tree = construct_ast_tree(data->token_list, NULL, 1, node_tree);
			if (node_tree)
				exec_cmd_type(data, node_tree, FORK);
			if (data->fork == FORK)
				exit(EXIT_SUCCESS);
		}
		return (reset_exec_cmd_character(data));
	}
	return (reset_exec_cmd_character(data));
}
