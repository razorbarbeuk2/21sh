/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/16 16:07:12 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

struct s_error_token
{
	char 		 *c;
	unsigned int t;
};

static const struct s_error_token s_error_t[] = {
	{";", TYPE_DSEMI},
	{"&&", TYPE_AND_IF},
	{"||", TYPE_OR_IF},
	{"|", TYPE_PIPE},
	{">", TYPE_REDIRECTION_LESSGREAT_RIGHT},
	{"<", TYPE_REDIRECTION_LESSGREAT_LEFT},
	{">&", TYPE_REDIRECTION_GREATAND},
	{"<&", TYPE_REDIRECTION_LESSAND},
	{">>", TYPE_REDIRECTION_DGREAT},
	{"<<", TYPE_REDIRECTION_DLESS},
	{"\\n", TYPE_NEAR_RETURN},
	{NULL, TYPE_FINISH}
};

int ft_error_token(unsigned int type)
{
	int i;

	i = 0;
	while (s_error_t[i].c)
	{
		if (type == s_error_t[i].t)
			return (ft_print_parse_error(s_error_t[i].c));
		i++;
	}
	return (0);
}

static int parse_token_list(t_list *token_list)
{
	t_token_struct *token_struct;
	t_token_struct *token_struct_next;

	while (token_list)
	{
		token_struct = (t_token_struct *)token_list->content;
		token_struct_next = (t_token_struct *)token_list->next->content;
		if ((token_struct->type != TYPE_CMD && token_struct->type != TYPE_IO_NUMBER) && (token_struct_next->type != TYPE_CMD))
			return (-1);
		token_list = token_list->next;
	}
	return (1);
}

int data_check_str_list_struct_cmd_loop(t_data *data, char *line_str)
{
	unsigned int type;

	type = 0;
	if(ft_token_str_pos(data, line_str, &data->token_list, &type) == -1)
		return (ft_error_token(type));
	if (parse_token_list(data->token_list) == -1)
		return (-1);
	return (1);
}