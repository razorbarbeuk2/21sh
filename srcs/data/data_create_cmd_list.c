/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/08 23:04:06 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_is_caract_quote(char *str)
{
	int i;

	i = 0;
	if (str[i] == '"' || str[i] == '\'')
	{
		i++;
		while (str[i] == '"' || str[i] == '\'')
			i++;
		return (i);
	}
	return (0);
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

void data_check_str_is_token_cmd(t_data *data, t_list **token_list, char *line_str, int i)
{
	char *str;

	str = NULL;
	(void)data;
	
	if (line_str)
	{
		str = ft_strsub(line_str, 0, i);
		ft_lstadd_back(token_list, ft_lstnew_node_type((char *)str, ft_strlen(str) * sizeof(char), TYPE_CMD));
	}
	return;
}

int 	ft_check_spec_caract(t_data *data, char *line_str)
{
	int pos;

	pos = 0;
	if ((pos = ft_is_pipe(&line_str[i], &caract)))
	{}
	else if ((pos = ft_is_semicolumns(&line_str[i], &caract)))
	{}
	else if ((pos = ft_is_redirection_right(line_str[i], &caract, input)) || (pos = ft_is_redirection_left(line_str[i], &caract, input)))
	{}
	
}

t_list *data_check_str_list_struct_cmd_loop(t_data *data, char *line_str)
{
	t_list *token_list;
	char *caract;
	char *input;
	char *str;
	int i;
	int TYPE;
	int pos;

	i = 0;
	TYPE = 0;
	str = NULL;
	caract = NULL;
	input = line_str;
	token_list = NULL;
	token_list = ft_memalloc(sizeof(t_list));
	while (line_str[i])
	{
		pos = 0;
		while (data_check_caract(line_str[i]))
			i++;
		TYPE = ft_check_spec_caract(t_data *data, &line_str[i]);
		// if ((pos = ft_is_pipe(&line_str[i], &caract)))
		// {
		// 	data_check_str_is_token_cmd(data, &token_list, input, i);
		// 	ft_lstadd_back(&token_list, ft_lstnew_node_type((char *)caract, ft_strlen(caract) * sizeof(char), TYPE_PIPE));
		// 	i = i + pos;
		// }
		// else if ((pos = ft_is_semicolumns(&line_str[i], &caract)))
		// {
		// 	data_check_str_is_token_cmd(data, &token_list, input, i);
		// 	ft_lstadd_back(&token_list, ft_lstnew_node_type((char *)caract, ft_strlen(caract) * sizeof(char), TYPE_SEMICOLUMN));
		// 	i = i + pos;
		// }
		// else if ((pos = ft_is_redirection_right(line_str[i], &caract, input)) || (pos = ft_is_redirection_left(line_str[i], &caract, input)))
		// {
		// 	data_check_str_is_token_cmd(data, &token_list, input, i);
		// 	ft_lstadd_back(&token_list, ft_lstnew_node_type((char *)caract, ft_strlen(caract) * sizeof(char), TYPE_REDIRECTION));
		// 	i = i + pos;
		// }
		else
			i++;
	}
	ft_print_list_token(token_list);
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