/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:14:23 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/16 20:20:45 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_print_token_test(t_list *token_list)
{
	t_token_struct *token;

	token_list = NULL;
	while (token_list)
	{
		DEBUG;
		token = (t_token_struct *)token_list->content;
		ft_putendl(token->token_name_str);
		token_list = token_list->next;
	}
	return ;
}

int ft_token_err(char *line_str, unsigned int *type)
{
	int len;

	len = (int)ft_strlen(line_str);
	if (data_check_false_caract(&line_str[len - 1]) == 1)
	{
		*type = TYPE_NEAR_RETURN;
		return (-1);
	}
	return (1);
}

int data_check_token(char *str)
{
	int i;

	i = 0;
	while (str[i] && data_check_false_caract(&str[i]))
		i++;
	return (i);
}

int data_check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int ft_token_str_pos(t_data *data, char *line_str, t_list **token_list, unsigned int *type)
{
	int *i;
	int size;
	
	(void)data;
	i = ft_memalloc(3 * sizeof(int));
	size = 0;
	if (ft_token_err(line_str, type) == -1)
		return (-1);
	while (line_str[i[0]])
	{
		if (line_str[i[0]] && (line_str[i[0]] == '"' || line_str[i[0]] == '\''))
			i[0] += data_check_quote_caract(&line_str[i[0]], &i[1]);
		else if (data_check_false_caract(&line_str[i[0]]) || ft_isdigit(line_str[i[0]]))
		{
			size = 0;
			data_check_is_token_cmd(token_list, line_str, i[0] - i[1], i[1]);
			if ((size = data_check_digit(&line_str[i[0]])) || (size = data_check_token(&line_str[i[0]])))
				data_check_is_token_cmd(token_list, line_str, i[0] - size, size);
			i[1] = 0;
		}
		else
		{
			i[0]++;
			i[1]++;
		}
	}
	//data_check_is_token_cmd(token_list, line_str, (i[0] - i[1]), i[1]);
	ft_print_token_test(data->token_list);
	ft_memdel((void **)&i);
	return (1);
}