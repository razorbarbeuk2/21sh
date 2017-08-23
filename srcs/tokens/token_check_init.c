/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:14:23 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/23 18:08:30 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_token_str_pos(t_data *data, char *line_str, t_list **token_list)
{
	int *i;

	(void)data;
	write(1, "\n", 1);
	i = ft_memalloc(2 * sizeof(int));
	while (line_str[i[0]] && (i[0] < (int)ft_strlen(line_str)))
	{
		if (line_str[i[0]] && (line_str[i[0]] == '"' || line_str[i[0]] == '\''))
			i[0] += data_check_quote_caract(&line_str[i[0]], &i[1]);
		else if (line_str[i[0]] && (line_str[i[0]] == '&' || line_str[i[0]] == ';' || line_str[i[0]] == '|' || line_str[i[0]] == '>' || line_str[i[0]] == '<'))
		{
			data_check_is_token_cmd(token_list, line_str, (i[0] - i[1]), i[1]);
			if (line_str[i[0]] == ';' && data_check_caract(line_str[i[0] + 1]))
					i[0] += data_check_is_token_operator(token_list, TYPE_DSEMI, ";", i[0]);
			else if (line_str[i[0]] == '&' && line_str[i[0] + 1] == '&' && data_check_caract(line_str[i[0] + 2]))
				i[0] += data_check_is_token_operator(token_list, TYPE_AND_IF, "&&", i[0]);
			else if (line_str[i[0]] == '|' && line_str[i[0] + 1] == '|' && data_check_caract(line_str[i[0] + 2]))
				i[0] += data_check_is_token_operator(token_list, TYPE_OR_IF, "||", i[0]);
			else if (line_str[i[0]] == '|' && line_str[i[0] + 1] != '|')
				i[0] += data_check_is_token_operator(token_list, TYPE_PIPE, "|", i[0]);
			else if (line_str[i[0]] == '>' || line_str[i[0]] == '<')
				i[0] = ft_is_redirection(token_list, line_str, i[0]);
			else
				ft_error_token(TYPE_ERROR_PARSE);
			i[1] = 0;
		}
		i[0]++;
		i[1]++;
	}
	data_check_is_token_cmd(token_list, line_str, (i[0] - i[1]), i[1]);
	return;
}