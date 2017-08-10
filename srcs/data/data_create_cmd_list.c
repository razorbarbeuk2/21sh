/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/10 17:11:16 by gbourson         ###   ########.fr       */
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

int 	ft_print_token(t_list **token_lst)
{
	t_list *lst;
	t_token_struct *token;

	lst = (*token_lst);
	token = NULL;
	while (lst)
	{
		token = NULL;
		token = (t_token_struct *)lst->content;
		if(token)
		{
			ft_putendl("START PRINT---------------");
			ft_putendl(token->token_name);
			ft_putendl("END PRINT---------------");
		}
		lst = lst->next;
	}
	return (0);
}


void 	ft_token_str_pos(t_data *data, char *line_str, t_list **token_list)
{
 	t_token_struct *token;
	t_token_struct *cmd_token;
	char *cmd;
	int i;
	int prev;
	int len;

	i = 0;
	prev = 0;
	cmd = NULL;
	cmd_token = NULL;
	token = NULL;
	(void)data;
	write(1, "\n", 1);
	len = ft_strlen(line_str);
	while (line_str[i] && i < len)
	{
		if(line_str[i] == '"' || line_str[i] == '\'')
			i = ft_is_caract_quote(&line_str[i]);
		if(line_str[i] == '&' || line_str[i] == ';' || line_str[i] == '|' || line_str[i] == '>' || line_str[i] == '<')
		{
			ft_putendl("TOKEN");
			token = ft_memalloc(sizeof(t_token_struct));
			cmd = ft_strsub(line_str, prev, (i - prev));
			if(cmd)
			{
				ft_putstr("CMD :");
				cmd_token = ft_memalloc(sizeof(t_token_struct));
				cmd_token->type = TYPE_CMD;
				cmd_token->token_name = ft_strtrim(cmd);
				cmd_token->pos = 0;
				ft_lstadd_back(token_list, ft_lstnew((t_token_struct *)cmd_token, (sizeof(t_token_struct))));
			}
			prev = i + 1;
			if(line_str[i] == ';')
			{
				token->type = TYPE_SEMICOLUMN;
				token->token_name = ft_strdup(";");
				token->pos = i;
			}		
			else if(line_str[i] == '&' && line_str[i + 1] == '&')
			{
				token->type = TYPE_AND;
				token->token_name = ft_strdup("&&");
				token->pos = i;
			}
			else if(line_str[i] == '|' && line_str[i + 1] == '|')
			{
				token->type = TYPE_OR;
				token->token_name = ft_strdup("||");
				token->pos = i;
			}	
			else if(line_str[i] == '|' && line_str[i + 1] != '|')
			{
				token->type = TYPE_PIPE;
				token->token_name = ft_strdup("|");
				token->pos = i;
			}	
			else if(line_str[i] == '>' || line_str[i] == '<')
			{
				token->type = TYPE_REDIRECTION;
				token->token_name = ft_strdup(">");
				token->pos = i;
			}
			ft_lstadd_back(token_list, ft_lstnew((t_token_struct *)token, (sizeof(t_token_struct))));
			ft_putendl("END");
			ft_strdel(&cmd);
			token = NULL;
		}
		i++;
	}
	ft_print_token(token_list);
	return ;
}

int 	ft_count_token(t_data *data, char *line_str)
{
	int i;
	int count_token;

	(void)data;
	i = 0;
	count_token = 0;
	while (line_str[i])
	{
		if (line_str[i] == '"' || line_str[i] == '\'')
			i += ft_is_caract_quote(&line_str[i]);
		if(line_str[i] == '&' || line_str[i] == ';' || line_str[i] == '|' || line_str[i] == '>' || line_str[i] == '<')
			count_token++;
		i++;
	}
	return (count_token);
}


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