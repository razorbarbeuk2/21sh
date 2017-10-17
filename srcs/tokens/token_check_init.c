/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:14:23 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/17 17:57:43 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int data_check_token(char *str)
{
	int i;

	i = 0;
	while (str[i] && data_check_false_caract(&str[i]))
		i++;
	return (i);
}

int ft_token_str(t_data *data, char *line_str)
{
	int index;
	int size;
	
	size = 0;
	index = 0;
	while (line_str[index])
	{
		if (line_str[index] && (line_str[index] == '"' || line_str[index] == '\''))
			index += data_check_quote_caract(&line_str[index], &size);
		else if (data_check_false_caract(&line_str[index]))
		{
			data_check_is_token_cmd(data, line_str, index - size, size, _CMD);
			if ((size = data_check_token(&line_str[index])))
			{
				index += size;
				data_check_is_token_cmd(data, line_str, index - size, size, _TOKEN);
				if (!line_str[index])
					return (-1);
			}
			size = 0;
		}
		index++;
		size++;
	}
	data_check_is_token_cmd(data, line_str, index - size, size, _CMD);
	//ft_print_token_test(data->token_list);
	return (1);
}