/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/16 16:17:21 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_parse	*data_parsing_init(void)
{
	static	t_lex	p[] = {
		{"|", data_parse_pipe},
		{"<", data_ope_left},
		{">", data_ope_right},
		{"<<", data_ope_double_left},
		{">>", data_ope_double_right},
		{"&&", data_ope_and},
		{";", data_ope_semicolon},
		{NULL, NULL}
	};
	return ((void *)f);
}

int				data_parsing_drive(t_data *data)
{
	int		i;
	t_lex	*parse;

	i = 0;
	parse = NULL;
	parse = data_parsing_init();
	while (parse[i].c)
	{
		if (parse[i])
			return (parse[i].f(data));
		i++;
	}
	return (0);
}

void		exec_cmd_character(t_data *data)
{
	char 	*str;
	int		i;

	i = 0;
	str = NULL;
	str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		ft_free_char(data->entry->line_str);
		data->entry->line_str = NULL;	
	}
	data->entry->line_str = data_clean_to_tab(data, str);
	while (data->entry->line_str[i])
	{
		if (data_parsing_init(data))
		{
			/* code */
		}
		else
			parse_line_builtins()
	}
	
	//get_exe_path();
	return ;
}