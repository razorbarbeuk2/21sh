/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/19 17:25:51 by gbourson         ###   ########.fr       */
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

int 		exec_cmd_heredoc(t_data *data)
{
	t_token_node 	*node;
	t_token_struct 	*node_content_right;
	char *line;
	int  p[2];
	
	line = NULL;
	pipe(p);
	// dup2(STDIN_FILENO, p[1]);
	close(p[0]);
	dup2(STDOUT_FILENO, p[0]);
	node = data->node_tree_data;
	node_content_right = ((t_token_struct *)node->tright->node->content);
	while (get_next_line(STDIN_FILENO, &line))
	{
		get_heredoc_prompt(data);
		if (line && ft_strcmp(line, node_content_right->token_name_str) == 0)
			break ;
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (p[0]);
}

int 		exec_cmd_character(t_data *data)
{
	ft_putchar('\n');
	parse_quote_and_double_quote(data);
	term_reset(data->term);
	if (convert_data_lst_tab(data))
	{
		if (!add_sentence_historic_node_to_list(data))
			return (ft_print_error("historic error"));
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str) != -1)
		{
			if ((data->node_tree_data = construct_ast_tree(data->token_list, NULL, 1, data->node_tree_data)))
				exec_cmd_type(data, data->node_tree_data, FORK);
			if (data->fork == FORK)
				exit(EXIT_SUCCESS);
		}
	}
	return (reset_exec_cmd_character(data));
}
