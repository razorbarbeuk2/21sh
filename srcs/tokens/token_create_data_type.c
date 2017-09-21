/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create_data_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:56:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/21 15:22:24 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

struct s_num_priority_token
{
	unsigned int t;
	int 		 c;
};

static const struct s_num_priority_token s_num_priority_t[] = {
	{TYPE_DSEMI, 1},
	{TYPE_AND_IF, 2},
	{TYPE_OR_IF, 2},
	{TYPE_PIPE, 3},
	{TYPE_REDIRECTION_LESSGREAT_RIGHT, 4},
	{TYPE_REDIRECTION_LESSGREAT_LEFT, 4},
	{TYPE_REDIRECTION_GREATAND, 4},
	{TYPE_REDIRECTION_LESSAND, 4},
	{TYPE_REDIRECTION_DGREAT, 4},
	{TYPE_REDIRECTION_DLESS, 4},
	{TYPE_CMD, 5},
	{TYPE_FINISH, 0}
};

static int data_construct_token_priority(unsigned int type)
{
	int i;

	i = 0;
	while (s_num_priority_t[i].t != TYPE_FINISH)
	{
		if (type == s_num_priority_t[i].t)
			return (s_num_priority_t[i].c);
		i++;
	}
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