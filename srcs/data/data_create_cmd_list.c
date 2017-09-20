/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/20 19:29:54 by gbourson         ###   ########.fr       */
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
	{NULL, TYPE_FINISH}
};

int ft_error_token(unsigned int type)
{
	int i;

	i = 0;
	while (s_error_t[i].c)
	{
		if (type == s_error_t[i].t)
			return (print_parse_error(s_error_t[i].c));
		i++;
	}
	return (0);
}

int data_check_str_list_struct_cmd_loop(t_data *data, char *line_str)
{
	unsigned int type;

	type = 0;
	if(ft_token_str_pos(data, line_str, &data->token_list, &type) == -1)
		return (ft_error_token(type));
	// termine cette fonction pour execution.
	return (1);
}