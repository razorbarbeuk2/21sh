/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create_data_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:56:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/17 18:48:59 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

struct s_num_priority_token
{
	char 		 *s;
	unsigned int t;
	int 		 c;
};

static const struct s_num_priority_token s_num_priority_t[] = {
	{";", TYPE_DSEMI, 1},
	{"&&", TYPE_AND_IF, 2},
	{"||", TYPE_OR_IF, 2},
	{"|", TYPE_PIPE, 3},
	{">", TYPE_REDIRECTION_LESSGREAT_RIGHT, 4},//>
	{"<", TYPE_REDIRECTION_LESSGREAT_LEFT, 4},//<
	{">&", TYPE_REDIRECTION_GREATAND, 4},//>&
	{"<&", TYPE_REDIRECTION_LESSAND, 4},//<&
	{">>", TYPE_REDIRECTION_DGREAT, 4},//>>
	{"<<", TYPE_REDIRECTION_DLESS, 4},//<<
	{NULL, TYPE_FINISH, 0}
};

static void data_construct_token_error(t_token_struct *token)
{
	token->type = TYPE_ERROR_PARSE;
	token->value = 0;
	token->error = token->token_name_str[ft_strlen(token->token_name_str) - 1];
	return ;
}

static int data_construct_token_priority(t_token_struct *token)
{
	int i;

	i = 0;
	while (s_num_priority_t[i].s)
	{
		if (ft_strcmp(s_num_priority_t[i].s, token->token_name_str) == 0)
		{
			token->type = s_num_priority_t[i].t;
			token->value = s_num_priority_t[i].c;
			break ;
		}
		i++;
	}
	if (token->value == 0)
		data_construct_token_error(token);
	return (0);
}

void data_check_is_token_type(t_token_struct *token, unsigned int flag)
{
	if (flag == _CMD)
	{
		token->type = TYPE_CMD;
		token->value = 5;
	}
	else if (flag == _IONUMBER)
	{
		token->type = TYPE_IO_NUMBER;
		token->value = 6;
	}
	else 
		data_construct_token_priority(token);
	return ;
}

int data_check_is_token(t_data *data, char *str, unsigned int flag)
{
	t_token_struct *token;

	token = NULL;
	if (str)
	{
		token = ft_memalloc(sizeof(t_token_struct));
		token->token_name_str = ft_strdup(str);
		token->token_name_tab = ft_split_in_command(str);
		token->len = ft_strlen(str);
		data_check_is_token_type(token, flag);
		ft_lstadd_back(&data->token_list, ft_lstnew((t_token_struct *)token, (sizeof(t_token_struct))));
		ft_memdel((void **)&token);
		return (1);
	}
	return(ft_print_error("Error token create\n"));
}

void data_check_is_token_cmd(t_data *data, char *line_str, int start, int size, unsigned int flag)
{
	char *str;
	char *tmp_str;

	str = NULL;
	if (line_str)
	{
		tmp_str = ft_strsub(line_str, start, size);
		str = ft_strtrim(tmp_str);
		data_check_is_token(data, str, flag);
		ft_strdel(&tmp_str);
		ft_strdel(&str);
	}
	return ;
}