/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/15 17:37:27 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_parse	*data_parsing_init(void)
{
	static	t_parse	p[] = {
		{"|", },
		{"<", },
		{">", },
		{"<<", },
		{">>", },
		{"&&", },
		{";", },
		{NULL, NULL}
	};
	return ((void *)f);
}

int				data_parsing_drive(t_data *data)
{
	int		i;
	t_parse	*parse;

	i = 0;
	parse = NULL;
	parse = data_parsing_init();
	while (parse[i].name)
	{
		if (ft_strcmp(*line, buil[i].name) == 0)
		{
			if (!opt)
				return (1);
			else
				return (buil[i].f(env_lst, line));
		}
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
	
	
	//get_exe_path();
	return ;
}