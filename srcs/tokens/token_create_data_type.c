/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create_data_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:56:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/18 15:41:14 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int data_construct_token_priority(unsigned int tok)
{
	if (tok == TYPE_DSEMI)
		return (1);
	else if (tok == TYPE_AND_IF || tok == TYPE_OR_IF)
		return (2);
	else if (tok == TYPE_PIPE)
		return (3);
	else if (tok == TYPE_REDIRECTION_LESSGREAT || tok == TYPE_REDIRECTION_GREATAND || \
		tok == TYPE_REDIRECTION_LESSAND || tok == TYPE_REDIRECTION_DGREAT || tok == TYPE_REDIRECTION_DLESS)
		return (4);
	else if (tok == TYPE_CMD)
		return (5);
	else
		return (0);
}

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
		token->value = data_construct_token_priority(type);
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