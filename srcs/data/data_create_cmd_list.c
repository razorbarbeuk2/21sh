/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/20 00:37:41 by RAZOR            ###   ########.fr       */
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

int ft_print_token(t_list **token_lst)
{
	t_list *lst;
	t_token_struct *token;

	lst = NULL;
	lst = (*token_lst);
	token = NULL;
	ft_putendl("START COUNT---------------");
	ft_putnbr(ft_lst_count(lst));
	ft_putendl("\nEND COUNT---------------");
	while (lst)
	{
		token = (t_token_struct *)lst->content;
		if (token)
		{
			ft_putendl("START PRINT---------------");
			ft_putendl(((t_token_struct *)lst->content)->token_name);
			ft_putendl("END PRINT---------------");
		}
		else
			ft_putendl("FUCK TOKEN---------------");
		lst = lst->next;
		token = NULL;
	}
	return (0);
}

void data_check_is_token_operator(t_list **token_list, unsigned int type, char *line_str, int pos)
{
	t_token_struct *token;

	token = NULL;
	if (line_str)
	{
		token = ft_memalloc(sizeof(t_token_struct));
		token->type = type;
		token->token_name = ft_strdup(line_str);
		token->pos = pos;
		ft_lstadd_back(token_list, ft_lstnew((t_token_struct *)token, (sizeof(t_token_struct))));
	}
	else
		ft_print_err("Error token create");
	return;
}

void data_check_is_token_cmd(t_list **token_list, char *line_str, int start, int size)
{
	char *str;

	str = NULL;
	if (line_str)
	{
		ft_putendl("LINE");
		ft_putendl(line_str);
		ft_putendl("TEST");
		ft_putnbr(start);
		ft_putendl("\nSIZE");
		ft_putnbr(size);
		ft_putendl("\nEND TEST");
		str = ft_strsub(line_str, start, size);
		ft_putendl(str);
		// ft_putendl("TEST");
		// ft_putendl(str);
		// ft_putendl("END TEST");
		str = ft_strtrim(str);
		
		str ? data_check_is_token_operator(token_list, TYPE_CMD, str, size) : ft_print_err("Error token cmd");
		ft_strdel(&str);
		str = NULL;
	}
	return;
}

// char *ft_is_redirection_sentence(char *line_str, int i)
// {
// 	int size;
// 	int st;

// 	size = 0;
// 	while (line_str[i] && line_str[i - 1] != ' ')
// 		i--;
// 	st = i;
// 	while (line_str[i] && line_str[i + 1] == ' ')
// 	{
// 		i++;
// 		size++;
// 	}
// 	return (ft_strsub(line_str, st, size));
// }

int ft_is_redirection(t_list **token_list, char *line_str, int i)
{
	int size;
	unsigned int type;

	size = i;
	while (ft_isdigit(line_str[i]))
		i++;
	if (line_str[i] == '>' && line_str[i] != '>')
		type = TYPE_REDIRECTION_LESSGREAT;
	else if (line_str[i] == '<' && line_str[i] != '<')
		type = TYPE_REDIRECTION_LESSGREAT;
	else if (line_str[i] == '>' && line_str[i + 1] == '&')
	{
		type = TYPE_REDIRECTION_GREATAND;
		i += 2;
	}
	else if (line_str[i] == '<' && line_str[i + 1] == '&')
	{
		type = TYPE_REDIRECTION_LESSAND;
		i += 2;
	}
	else if (line_str[i] == '>' && line_str[i + 1] == '>')
	{
		type = TYPE_REDIRECTION_DGREAT;
		i += 2;
	}
	else if (line_str[i] == '<' && line_str[i + 1] == '<')
	{
		type = TYPE_REDIRECTION_DLESS;
		i += 2;
	}
	while (ft_isdigit(line_str[i]) || line_str[i] == '-')
		i++;
	data_check_is_token_operator(token_list, type, ft_strsub(line_str, size, i - size), i);
	return (i);
}

void ft_token_str_pos(t_data *data, char *line_str, t_list **token_list)
{
	int i;
	int offset;
	int set_offset;
	int prev;

	i = 0;
	offset = 0;
	set_offset = 0;
	prev = 0;
	(void)data;
	write(1, "\n", 1);
	while (line_str[i] && i < (int)ft_strlen(line_str))
	{
		if (line_str[i] && (line_str[i] == '"' || line_str[i] == '\''))
		{
			i += ft_is_caract_quote(&line_str[i]);
			offset = i;
		}
		else if (line_str[i] && (line_str[i] == '&' || line_str[i] == ';' || line_str[i] == '|' || line_str[i] == '>' || line_str[i] == '<'))
		{
			data_check_is_token_cmd(token_list, line_str, (i - offset), offset);
			if (line_str[i] == ';')
			{
				data_check_is_token_operator(token_list, TYPE_DSEMI, ";", i);
				i++;
			}
			else if (line_str[i] == '&' && line_str[i + 1] == '&')
			{
				data_check_is_token_operator(token_list, TYPE_AND_IF, "&&", i);
				i += 2;
			}
			else if (line_str[i] == '|' && line_str[i + 1] == '|')
			{
				data_check_is_token_operator(token_list, TYPE_OR_IF, "||", i);
				i += 2;
			}
			else if (line_str[i] == '|' && line_str[i + 1] != '|')
			{
				data_check_is_token_operator(token_list, TYPE_PIPE, "|", i);
				i++;
			}
			else if (line_str[i] == '>' || line_str[i] == '<')
				i = ft_is_redirection(token_list, line_str, i);
			offset = 0;
		}
		i++;
		offset++;
	}
	ft_putendl("START OFFSET---------------");
	ft_putnbr(offset);
	ft_putendl("\nEND OFFSET---------------");
	data_check_is_token_cmd(token_list, line_str, (i - offset), offset);
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

// void ft_print_list_token(t_list *token_list)
// {
// 	t_list *lst;

// 	lst = NULL;
// 	lst = token_list;
// 	write(1, "\n", 1);
// 	while (lst)
// 	{
// 		ft_putendl("i");
// 		if ((char *)lst->content)
// 			ft_putendl((char *)lst->content);
// 		else
// 			ft_putendl("NO TOKEN-------------");
// 		lst = lst->next;
// 	}
// }