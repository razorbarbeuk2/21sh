/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/13 22:54:56 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_is_caract_quote(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] != '"' || str[i] != '\''))
		i++;
	return (i);
}

int ft_is_redirection_left(char c, char **caract, char *c_str)
{
	int i;

	i = 0;
	if (c == '<')
	{
		while (c_str[i] && !data_check_caract(c_str[i]))
		{
			if (ft_isdigit(c_str[i]) || c_str[i] == '<' || c_str[i] == '-')
				i++;
			else
				print_error("Error token");
		}
		(*caract) = ft_memalloc(i * sizeof(char));
		ft_strncpy((*caract), c_str, i);
		return (ft_strlen(*caract));
	}
	return (0);
}

int ft_is_redirection_right(char c, char **caract, char *c_str)
{
	int i;

	i = 0;
	if (c == '>')
	{
		while (c_str[i] && !data_check_caract(c_str[i]))
		{
			if (ft_isdigit(c_str[i]) || c_str[i] == '>' || c_str[i] == '-')
				i++;
			else
				print_error("Error token");
		}
		(*caract) = ft_memalloc(i * sizeof(char));
		ft_strncpy((*caract), c_str, i);
		return (ft_strlen(*caract));
	}
	return (0);
}

int ft_is_semicolumns(char *c, char **caract)
{
	if (c[0] == ';')
	{
		(*caract) = ft_strdup(";");
		return (1);
	}
	return (0);
}

int ft_is_pipe(char *c, char **caract)
{
	if (c[0] == '|')
	{
		(*caract) = ft_strdup("|");
		return (1);
	}
	if (c[0] == '|' && c[1] == '|')
	{
		(*caract) = ft_strdup("||");
		return (2);
	}
	return (0);
}

void ft_print_list_token(t_list *token_list)
{
	t_list *lst;

	lst = NULL;
	lst = token_list;
	write(1, "\n", 1);
	while (lst)
	{
		ft_putendl("i");
		if ((char *)lst->content)
			ft_putendl((char *)lst->content);
		else
			ft_putendl("NO TOKEN-------------");
		lst = lst->next;
	}
}

int ft_print_token(t_list **token_lst)
{
	t_list *lst;
	t_token_struct *token;

	lst = (*token_lst);
	token = NULL;
	while (lst)
	{
		token = NULL;
		token = (t_token_struct *)lst->content;
		if (token)
		{
			ft_putendl("START PRINT---------------");
			ft_putendl(token->token_name);
			ft_putendl("END PRINT---------------");
		}
		lst = lst->next;
	}
	return (0);
}

void data_check_is_token_operator(t_data *data, t_list **token_list, unsigned int type, char *str, int pos)
{
	t_token_struct *token;

	(void)data;
	token = NULL;
	if (str)
	{
		token = ft_memalloc(sizeof(t_token_struct));
		token->type = type;
		token->token_name = ft_strdup(str);
		token->pos = pos;
		ft_lstadd_back(token_list, ft_lstnew((t_token_struct *)token, (sizeof(t_token_struct))));
	}
	else
		ft_print_err("Error token operator");
	return;
}

void data_check_is_token_cmd(t_data *data, t_list **token_list, char *line_str, int start, int size)
{
	t_token_struct *cmd_token;
	char *str;

	(void)data;
	str = NULL;
	cmd_token = NULL;
	if (line_str)
	{
		str = ft_strsub(line_str, start, size);
		if (str)
			data_check_is_token_operator(data, token_list, TYPE_CMD, ft_strtrim(str), 0);
		else
			ft_print_err("Error token cmd");
	}
	ft_strdel(&str);
	str = NULL;
	return;
}

void ft_token_str_pos(t_data *data, char *line_str, t_list **token_list)
{
	int i;
	int prev;

	i = 0;
	prev = 0;
	(void)data;
	write(1, "\n", 1);
	while (line_str[i] && i < (int)ft_strlen(line_str))
	{
		if (line_str[i] == '"' || line_str[i] == '\'')
			i += ft_is_caract_quote(&line_str[i]);
		if (line_str[i] == '&' || line_str[i] == ';' || line_str[i] == '|' || line_str[i] == '>' || line_str[i] == '<')
		{
			data_check_is_token_cmd(data, token_list, line_str, prev, (i - prev));
			if (line_str[i] == ';')
				data_check_is_token_operator(data, token_list, TYPE_SEMICOLUMN, ";", i);
			else if (line_str[i] == '&' && line_str[i + 1] == '&')
			{
				data_check_is_token_operator(data, token_list, TYPE_AND, "&&", i);
				i += 2;
			}
			else if (line_str[i] == '|' && line_str[i + 1] == '|')
			{
				data_check_is_token_operator(data, token_list, TYPE_OR, "||", i);
				i += 2;
			}
			else if (line_str[i] == '|' && line_str[i + 1] != '|')
				data_check_is_token_operator(data, token_list, TYPE_PIPE, "|", i);
			else if (line_str[i] == '>' && line_str[i] != '>')
				data_check_is_token_operator(data, token_list, TYPE_REDIRECTION, ">", i);
			else if (line_str[i] == '>' && line_str[i + 1] == '>')
			{
				data_check_is_token_operator(data, token_list, TYPE_REDIRECTION, ">>", i);
				i += 2;
			}
			else if (line_str[i] == '<' && line_str[i] != '<')
				data_check_is_token_operator(data, token_list, TYPE_REDIRECTION, "<", i);
			else if (line_str[i] == '<' && line_str[i + 1] == '<')
			{
				data_check_is_token_operator(data, token_list, TYPE_REDIRECTION, "<<", i);
				i += 2;
			}
			prev = (i + 1);
		}
		i++;
	}
	data_check_is_token_cmd(data, token_list, line_str, prev, (i - prev));
	ft_print_token(token_list);
	return;
}

// int ft_count_token(t_data *data, char *line_str)
// {
// 	int i;
// 	int count_token;

// 	(void)data;
// 	i = 0;
// 	count_token = 0;
// 	while (line_str[i])
// 	{
// 		if (line_str[i] == '"' || line_str[i] == '\'')
// 			i += ft_is_caract_quote(&line_str[i]);
// 		if (line_str[i] == '&' || line_str[i] == ';' || line_str[i] == '|' || line_str[i] == '>' || line_str[i] == '<')
// 			count_token++;
// 		i++;
// 	}
// 	return (count_token);
// }

t_list *data_check_str_list_struct_cmd_loop(t_data *data, char *line_str)
{
	t_list *token_list;
	int count_token;
	int i;

	i = 0;
	count_token = 0;
	token_list = NULL;
	token_list = ft_memalloc(sizeof(t_list));
	ft_token_str_pos(data, line_str, &token_list);

	//ft_print_list_token(token_list);
	return (NULL);
}

// static t_list		*data_check_str_list_struct_node(t_data *data, void *node, int type)
// {
// 	t_list *lst;

// 	lst = NULL;
// 	(void)data;
// 	if (type == TYPE_CMD)
// 		lst = ft_lstnew_node_type(((t_cmd *)node), sizeof(t_cmd), type);
// 	if (type == TYPE_PIPE || type == TYPE_SEMICOLUMN || type == TYPE_AND || type == TYPE_OR)
// 		lst = ft_lstnew_node_type(((t_sep *)node), sizeof(t_sep), type);
// 	return
// }