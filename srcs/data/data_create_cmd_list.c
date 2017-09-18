/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/18 18:41:15 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_error_token(unsigned int type)
{
	if(type == TYPE_DSEMI)
		return (print_parse_error(";"));
	else if (type == TYPE_AND_IF)
		return (print_parse_error("&&"));
	else if (type == TYPE_OR_IF)
		return (print_parse_error("||"));
	else if (type == TYPE_PIPE)
		return (print_parse_error("|"));
	else if (type == TYPE_ERROR_PARSE)
		return (print_parse_error("WTF"));
	
	return (0);
}

int ft_token_check_cmd(t_data *data, t_list *token_list)
{
	t_list			*lst;
	t_token_struct	*token;
	t_token_struct	*token_n;

	(void)data;
	token = NULL;
	token_n = NULL;
	lst = token_list;
	while (lst && lst->next)
	{
		token = (t_token_struct *)lst->content;
		token_n = (t_token_struct *)lst->next->content;
		if(token->type == TYPE_DSEMI && token_n->type != TYPE_CMD)
			return (ft_error_token(TYPE_DSEMI));
		else if(token->type == TYPE_AND_IF && token_n->type != TYPE_CMD)
			return (ft_error_token(TYPE_AND_IF));
		else if(token->type == TYPE_OR_IF && token_n->type != TYPE_CMD)
			return (ft_error_token(TYPE_OR_IF));
		else if(token->type == TYPE_PIPE && token_n->type != TYPE_CMD)
			return (ft_error_token(TYPE_PIPE));
		lst = lst->next;
		token = NULL;
		token_n = NULL;
	}
	return (1);
}

int data_check_str_list_struct_cmd_loop(t_data *data, char *line_str)
{
	ft_token_str_pos(data, line_str, &data->token_list);
	// termine cette fonction pour execution.
	return (ft_token_check_cmd(data, data->token_list));
}