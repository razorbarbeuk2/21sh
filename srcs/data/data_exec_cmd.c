/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/18 18:24:52 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// static t_parse	*data_parsing_init(void)
// {
// 	static	t_lex	p[] = {
// 		{"|", data_parse_pipe},
// 		{"<", data_ope_left},
// 		{">", data_ope_right},
// 		{"<<", data_ope_double_left},
// 		{">>", data_ope_double_right},
// 		{"&&", data_ope_and},
// 		{";", data_ope_semicolon},
// 		{NULL, NULL}
// 	};
// 	return ((void *)p);
// }

// int				data_parsing_drive(t_data *data)
// {
// 	int		i;
// 	t_lex	*parse;

// 	i = 0;
// 	parse = NULL;
// 	parse = data_parsing_init();
// 	while (parse[i].c)
// 	{
// 		if (parse[i])
// 			return (parse[i].f(data));
// 		i++;
// 	}
// 	return (0);
// }

int 		data_check_special_caract_inside(char str)
{
	if (str == "<")
		return (1);
	if (str == ">")
		return (1);
	if (str == "|")
		return (1);
	if (str == ";")
		return (1);
}

int			ft_striter_data_c(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s)
			return(f(s++));
	}
	return (0);
}

int 		data_check_special_caract(t_data *data, char *str)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "|"))
		return (1);
	if (ft_strcmp(str, "&&"))
		return (1);
	ft_striter_data_c(str, &data_check_special_caract_inside);
	return (0);
}

t_cmd		*data_create_list_struct_cmd(t_data *data, char **line_str)
{
	t_cmd	*cmd_node;
	char 	**tmp;
	int 	i;

	cmd_node = NULL;
	tmp = NULL;
	i = 0;
	if (!(cmd_node = (t_cmd *)malloc(sizeof(t_cmd))))
		return ;
	cmd_node->_select_cmd = 0;
	while (line_str[i])
	{
		if (data_check_special_caract_global(data, line_str[i]))
		{
			tmp = data_split_to_tab(line_str[i]);
			data_create_list_struct_cmd(data, tmp);
		}
		if (!data_check_special_caract_global(data, line_str[i]) && !(cmd_node->_select_cmd))
		{
			cmd_node->cmd = ft_strdup(line_str[i]);
			cmd_node->_select_cmd = 1;
		}
		if (data_check_special_caract_opt(data, &line_str[i]) && cmd_node->_select_cmd)
			cmd_node->cmd = ft_strdup(line_str[i]);
		if (line_str[i])
			cmd_node->file = ft_strdup(line_str[i]);
		i++;
	}
	return ((void *)cmd_node);
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
	data_create_list_struct_cmd(data, data->entry->line_str);
	return ;
}