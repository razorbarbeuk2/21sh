/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create_data_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:56:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/08/24 17:08:11 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int data_check_is_token_operator(t_list **token_list, unsigned int type, char *line_str, int pos)
{
	t_token_struct *token;

	token = NULL;
	if (line_str)
	{
		token = ft_memalloc(sizeof(t_token_struct));
		token->type = type;
		token->token_name = ft_strdup(line_str);
		token->pos = pos;
		ft_lstadd_back(token_list, ft_lstnew((t_token_struct *)token, (sizeof(t_token_struct))));
		return (ft_strlen(line_str));
	}
	else
		ft_print_err("Error token create");
	return (0);
}

void data_check_is_token_cmd(t_list **token_list, char *line_str, int start, int size)
{
	char *str;

	str = NULL;
	if (line_str)
	{
		str = ft_strsub(line_str, start, size);
		str = ft_strtrim(str);
		str ? data_check_is_token_operator(token_list, TYPE_CMD, str, size) : ft_print_err("Error token cmd");
		ft_strdel(&str);
		str = NULL;
	}
	return;
}