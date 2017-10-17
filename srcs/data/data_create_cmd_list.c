/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/17 18:53:39 by gbourson         ###   ########.fr       */
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
		else if ((token_struct->type != TYPE_CMD) && (token_struct_next->type != TYPE_CMD))
			return (ft_print_parse_near_token(token_struct->token_name_str));
		// if ((token_struct->type != TYPE_CMD && token_struct->type != TYPE_IO_NUMBER) && (token_struct_next->type != TYPE_CMD))
		// 	return (ft_print_parse_error(token_struct->token_name_str));
		
		token_list = token_list->next;
	}
	return (1);
}

int data_check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int ft_token_io_number(t_data *data, t_list *token_lst)
{
	t_list				*tmp;
	t_token_struct		*token;
	t_token_struct		*token_next;
	int size;
	char *str;
	
	str = NULL;
	while (token_lst)
	{
		token = (t_token_struct *)token_lst->content;
		if (token_lst->next)
			token_next = (t_token_struct *)token_lst->next->content;
		if ((token->type == TYPE_CMD) && (token_next->type != TYPE_CMD))
		{
			size = ft_count_tab(token->token_name_tab);
			if (data_check_digit(token->token_name_tab[size - 1]) > 0)
			{
				tmp = token_lst->next;
				token_lst->next = NULL;
				data_check_is_token(data, token->token_name_tab[size - 1], _IONUMBER);
				ft_strdel(&token->token_name_tab[size - 1]);
				token_lst = token_lst->next;
				token_lst->next = tmp;
			}
		}
		token_lst = token_lst->next;
	}
	return (0);
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