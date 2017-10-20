/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_io_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:14:48 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/20 17:45:01 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

struct s_exec_token_io_number
{
	unsigned int t;
};

static const struct s_exec_token_io_number s_token_io_number_t[] = {
	{TYPE_REDIRECTION_LESSGREAT_RIGHT},
	{TYPE_REDIRECTION_LESSGREAT_LEFT},
	{TYPE_REDIRECTION_GREATAND},
	{TYPE_REDIRECTION_LESSAND},
	{TYPE_REDIRECTION_DGREAT},
	{TYPE_REDIRECTION_DLESS},
	{TYPE_FINISH}
};

int data_check_token_io_number_function(t_token_struct *token_content)
{
	int i;

	i = 0;
	while (s_token_io_number_t[i].t != TYPE_FINISH)
	{
		if (s_token_io_number_t[i].t == token_content->type)
			return (1);
		i++;
	}
	return (0);
}


int data_check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

static t_list *ft_token_io_number_struct_right(t_data *data, t_list *token_lst)
{
	t_list				*tmp;
	t_token_struct		*token;
	t_token_struct		*token_next;
	char 				*str;

	str = NULL;
	if (token_lst && token_lst->next)
	{
		token = (t_token_struct *)token_lst->content;
		token_next = (t_token_struct *)token_lst->next->content;
		if (token_lst->next && data_check_digit(token_next->token_name_tab[0]) > 0)
		{
			if (token_lst->next->next)
				tmp = token_lst->next->next;
			token_lst->next = NULL;
			data_check_is_token(data, token_next->token_name_tab[0], _IONUMBER);
			ft_free_char_array(&token_next->token_name_tab);
			if (token_lst->next->next)
				token_lst->next->next = tmp;
		}
	}
	return (token_lst);
}

static t_list *ft_token_io_number_struct_left(t_data *data, t_list *token_lst)
{
	t_list				*tmp;
	t_token_struct		*token;
	t_token_struct		*token_next;
	int 				size;
	char 				*str;

	str = NULL;
	token = (t_token_struct *)token_lst->content;
	if (token_lst->next)
		token_next = (t_token_struct *)token_lst->next->content;
	size = ft_count_tab(token->token_name_tab);
	if (data_check_digit(token->token_name_tab[size - 1]) > 0)
	{
		tmp = token_lst->next;
		token_lst->next = NULL;
		data_check_is_token(data, token->token_name_tab[size - 1], _IONUMBER);
		ft_strdel(&token->token_name_tab[size - 1]);
		token_lst = token_lst->next;
		token_lst->next = tmp;
	}
	return (token_lst);
}

int ft_token_io_number(t_data *data, t_list *token_lst)
{
	t_token_struct		*token;
	t_token_struct		*token_next;
	
	while (token_lst)
	{
		token = (t_token_struct *)token_lst->content;
		if (token_lst->next)
		{
			token_next = (t_token_struct *)token_lst->next->content;
			if ((token->type == TYPE_CMD) && data_check_token_io_number_function(token_next))
			{
				token_lst = ft_token_io_number_struct_left(data, token_lst);
				token_lst = token_lst->next;
				token_lst = ft_token_io_number_struct_right(data, token_lst);
			}
		}
		token_lst = token_lst->next;
	}
	return (0);
}