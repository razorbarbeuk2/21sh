/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_check_quote_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:12:28 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/12 17:37:48 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int check_quote_and_double_quote_result(char s)
{
	if (s == '\'')
		return (QUOTE_SIMPLE);
	if (s == '"')
		return (QUOTE_DOUBLE);
	return (0);
}

static void quote_prompt_and_INACTIVE(t_data *data)
{
	data->quotes = free_data_quotes(data->quotes);
	data->set_quotes = INACTIVE;
	return;
}

static void quote_prompt_and_ACTIVE(t_data *data)
{
	data->set_quotes = ACTIVE;
	data->quotes = init_data_quotes();
	get_quote_prompt(data);
	listen_cursor(data, data->line);
	return;
}

static int *parse_quote_and_double_quote_in_tab(t_list *line)
{
	int     nbr_quote;
	int     set_quote;
	int     *tab_quote;
	int     i;
	char    c;

	i = 0;
	set_quote = 0;
	nbr_quote = ft_count_quote(line);
	tab_quote = ft_memalloc((nbr_quote + 1) * sizeof(int));
	while (line)
	{
		c = ((char *)line->content)[0];
		if ((set_quote = check_quote_and_double_quote_result(c)) > 0)
		{
			tab_quote[i] = set_quote;
			i++;
		}
		line = line->next;
	}
	tab_quote[i] = 0;
	return (tab_quote);
}

int parse_quote_and_double_quote(t_data *data)
{
	int     type_quote;
	int     count_type_quote;
	int     *tab_quote_;
	int     i;

	i = 0;
	type_quote = 0;
	count_type_quote = 0;
	tab_quote_ = NULL;
	tab_quote_ = parse_quote_and_double_quote_in_tab(data->entry->line);
	while (tab_quote_[i])
	{
		if (tab_quote_[i] != type_quote)
		{
			type_quote = tab_quote_[i];
			count_type_quote = ft_count_type_quote(tab_quote_, type_quote);
			if ((count_type_quote%2) == 0)
			{
				quote_prompt_and_INACTIVE(data);
				ft_memdel((void **)&tab_quote_);
                return (1);
			}
            else
				quote_prompt_and_ACTIVE(data);
			count_type_quote = 0;
		}
		i++;
	}
	ft_memdel((void **)&tab_quote_);
	return (0);
}
