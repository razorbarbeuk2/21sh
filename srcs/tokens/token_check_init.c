/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:14:23 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/27 19:10:38 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_token_pipe(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int it;

	it = 0;
	it = (*io);
	if (str[it] == '|' && str[it + 1] != '|' && data_check_caract(str[it + 1]))
	{
		(*io) += data_check_is_token_operator(token_list, TYPE_PIPE, "|", (*io));
		return (1);
	}
	else
		(*type) = 2;
	return (0);
}


int ft_token_or_if(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int it;

	it = 0;
	it = (*io);
	if (str[it] == '|' && str[it + 1] == '|' && data_check_caract(str[it + 2]))
	{
		(*io) += data_check_is_token_operator(token_list, TYPE_OR_IF, "||", (*io));
		return (1);
	}
	else
		(*type) = 2;
	return (0);
}

int ft_token_and_if(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int it;

	it = 0;
	it = (*io);
	if (str[it] == '&' && str[it + 1] == '&' && data_check_caract(str[it + 2]))
	{
		(*io) += data_check_is_token_operator(token_list, TYPE_AND_IF, "&&", (*io));
		return (1);
	}
	else
		(*type) = 1;
	return (0);
}

int ft_token_semi(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int it;

	it = 0;
	it = (*io);
	if (str[it] == ';' && data_check_caract(str[it + 1]))
	{
		(*io) += data_check_is_token_operator(token_list, TYPE_DSEMI, ";", (*io));
		return (1);
	}
	else
		(*type) = 0;
	return (0);
}


int ft_token_str_pos(t_data *data, char *line_str, t_list **token_list)
{
	int *i;
	unsigned int type;

	(void)data;
	type = 0;
	i = ft_memalloc(2 * sizeof(int));
	while (line_str[i[0]] && (i[0] < (int)ft_strlen(line_str)))
	{
		if (line_str[i[0]] && (line_str[i[0]] == '"' || line_str[i[0]] == '\''))
			i[0] += data_check_quote_caract(&line_str[i[0]], &i[1]);
		else if (line_str[i[0]] && (line_str[i[0]] == '&' || line_str[i[0]] == ';' || line_str[i[0]] == '|' || line_str[i[0]] == '>' || line_str[i[0]] == '<'))
		{
			data_check_is_token_cmd(token_list, line_str, (i[0] - i[1]), i[1]);
			if (ft_token_semi(line_str, &i[0], &type, token_list))
				ft_putendl("SEMI");
			else if (ft_token_semi(line_str, &i[0], &type, token_list))
				ft_putendl("SEMI");
			else if (line_str[i[0]] == '|' && line_str[i[0] + 1] == '|' && data_check_caract(line_str[i[0] + 2]))
				i[0] += data_check_is_token_operator(token_list, TYPE_OR_IF, "||", i[0]);
			else if (line_str[i[0]] == '|' && line_str[i[0] + 1] != '|' && (type++))
				i[0] += data_check_is_token_operator(token_list, TYPE_PIPE, "|", i[0]);
			else if (line_str[i[0]] == '>' || line_str[i[0]] == '<')
				i[0] = ft_is_redirection(token_list, line_str, i[0], &type);
			else				
				return (ft_error_token(type));
			i[1] = 0;
		}
		i[0]++;
		i[1]++;
	}
	data_check_is_token_cmd(token_list, line_str, (i[0] - i[1]), i[1]);
	return (1);
}