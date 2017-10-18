/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/18 17:15:33 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int parse_token_list(t_list *token_list)
{
	t_token_struct *token_struct;
	t_token_struct *token_struct_next;

	while (token_list)
	{
		token_struct = (t_token_struct *)token_list->content;
		if (token_list->next)
			token_struct_next = (t_token_struct *)token_list->next->content;
		if (token_struct->type == TYPE_ERROR_PARSE)
			return (ft_print_parse_error(&token_struct->error));
		else if (token_struct->type != TYPE_CMD && !token_list->next)
			return (ft_print_parse_error("\\n"));
		else if ((token_struct->type != TYPE_CMD && token_struct->type != TYPE_IO_NUMBER) && (token_struct_next->type != TYPE_CMD))
			return (ft_print_parse_near_token(token_struct->token_name_str));
		token_list = token_list->next;
	}
	return (1);
}

int data_check_str_list_struct_cmd_loop(t_data *data, char *line_str)
{
	unsigned int type;

	type = 0;
	ft_token_str(data, line_str);
	if (parse_token_list(data->token_list) == -1)
		return (-1);
	ft_token_io_number(data, data->token_list);
	return (1);
}