/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/24 18:13:58 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		print_list_cmd(t_data *data, t_list *lst)
{
	t_cmd *cmd_lst;

	cmd_lst = NULL;
	while (lst)
	{
		cmd_lst = (t_cmd *)lst->content;
		ft_putstr_fd("CMD :", data->sel->tty);
		if (!cmd_lst)
			ft_putstr_fd("FUCK", data->sel->tty);
		ft_putstr_fd(cmd_lst->cmd, data->sel->tty);
		write(1, " ", 1);
		lst = lst->next;
		cmd_lst = NULL;
	}
}

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

// int 		data_check_special_caract_inside(char str)
// {
// 	if (str == "<")
// 		return (1);
// 	if (str == ">")
// 		return (1);
// 	if (str == "|")
// 		return (1);
// 	if (str == ";")
// 	return (1);
// }

// int			ft_striter_data_c(char *s, void (*f)(char *))
// {
// 	if (s && f)
// 	{
// 		while (*s)
// 			return(f(s++));
// 	}
// 	return (0);
// }

// int 		data_check_special_caract(t_data *data, char *str)
// {
// 	int i;

// 	i = 0;
// 	if (ft_strcmp(str, "|"))
// 		return (1);
// 	if (ft_strcmp(str, "&&"))
// 		return (1);
// 	ft_striter_data_c(str, &data_check_special_caract_inside);
// 	return (0);
// }

void 		ft_init_t_cmd(t_cmd	**cmd_node)
{
	t_cmd	*cmd_tmp;

	cmd_tmp = NULL;
	cmd_tmp = (*cmd_node);
	cmd_tmp->cmd = NULL;
	cmd_tmp->opt = NULL;
	cmd_tmp->file = NULL;
	cmd_tmp->_select_cmd = 0;
}

int 		data_check_special_caract_global(t_data *data, char *line_str, char **caract)
{
	int i;

	i = 0;
	(void)data;
	while (line_str[i])
	{
		if (line_str[i + 1])
		{

			if (line_str[i] == '<' && line_str[i + 1] != '<' && line_str[i + 1])
			{
				(*caract) = ft_strdup("<");
				return (1);
			}
			else if (line_str[i] == '>' && line_str[i + 1] != '>' && line_str[i + 1])
			{
				(*caract) = ft_strdup(">");
				return (1);
			}
			else if (line_str[i] == '|' && line_str[i + 1] != '|' && line_str[i + 1])
			{
				(*caract) = ft_strdup("|");
				return (1);
			}
			else if (line_str[i] == ';' && line_str[i + 1] != '|' && line_str[i + 1])
			{
				(*caract) = ft_strdup(";");
				return (1);
			}
		}
		else
			break ;
		i++;
	}
	return (0);
}

t_cmd		*data_create_list_struct_cmd(t_data *data, char *line_str)
{
	t_cmd	*cmd_node;

	cmd_node = NULL;
	(void)data;
	if (!(cmd_node = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	ft_init_t_cmd(&cmd_node);
	if (!cmd_node->_select_cmd)
	{
		cmd_node->cmd = ft_strdup(line_str);
		cmd_node->_select_cmd = 1;
	}
	return (cmd_node);
}

t_cmd		*data_check_str_list_struct_cmd(t_data *data, char *line_str)
{
	t_cmd	*cmd_node;
	char 	*caract;
	char 	**tmp;
	int 	i;

	tmp = NULL;
	i = 0;
	caract = NULL;
	cmd_node = NULL;
	ft_putstr_fd("\n", data->sel->tty);
	ft_putstr_fd(line_str, data->sel->tty);
	ft_putstr_fd("\nif\n", data->sel->tty);
	if (!data_check_special_caract_global(data, line_str, &caract) && line_str)
	{
		// ft_putstr_fd(line_str, data->sel->tty);
		ft_putstr_fd("P\n", data->sel->tty);
		// ft_putstr_fd("\n", data->sel->tty);
		return (data_create_list_struct_cmd(data, line_str));
		// if (data_check_special_caract_opt(data, &line_str) && cmd_node->_select_cmd)
		// 	cmd_node->cmd = ft_strdup(line_str);
		// if (line_str)
			// 	cmd_node->file = ft_strdup(line_str);
	}
	else if (data_check_special_caract_global(data, line_str, &caract) && line_str)
	{
		ft_putstr_fd("K\n", data->sel->tty);
		//ft_putstr_fd(caract, data->sel->tty);
		tmp = data_split_to_tab(line_str, caract);
		// while(tmp[i])
		// {
		// 	ft_putstr_fd("-", data->sel->tty);
		// 	ft_putstr_fd(tmp[i], data->sel->tty);
		// 	ft_putstr_fd("\n", data->sel->tty);
		// 	i++;
		// }
		// ft_putnbr_fd(i, data->sel->tty);
		i = 0;
		while (tmp[i])
		{
			
			if (tmp[i])
				// ft_putstr_fd(tmp[i], data->sel->tty);
				// ft_putstr_fd("|", data->sel->tty);
				// ft_putstr_fd(tmp[i + 2], data->sel->tty);
				// ft_putstr_fd("\n", data->sel->tty);
				data_check_str_list_struct_cmd(data, tmp[i]);
			i++;
		}
	}
	return (NULL);
}

void		exec_cmd_character(t_data *data)
{
	t_cmd	*cmd_node;
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
		cmd_node = NULL;
		cmd_node = data_check_str_list_struct_cmd(data, data->entry->line_str[i]);
		// if (cmd_node)
		// {
		// 	ft_putstr_fd("cmd :", data->sel->tty);
		// 	ft_putstr_fd(cmd_node->cmd, data->sel->tty);
		// }
		// else
		// 	ft_putstr_fd("KL", data->sel->tty);
		ft_lstadd_back(&data->cmd, ft_lstnew(cmd_node, sizeof(t_cmd)));
		i++;
	}
	print_list_cmd(data, data->cmd);
	return ;
}