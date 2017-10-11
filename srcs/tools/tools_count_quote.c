/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_count_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:05:10 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/11 17:07:34 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_count_quote(t_list *line)
{
	int count_quote;
	char c;

	count_quote = 0;
	while (line)
	{
		c = ((char *)line->content)[0];
		if (check_quote_and_double_quote_result(c) > 0)
			count_quote++;
		line = line->next;
	}
	return (count_quote);
}

int ft_count_type_quote(int *tab_quotes, int type)
{
	int count_type;
	int i;

	i = 0;
	count_type = 0;
	while (tab_quotes[i])
	{
		if (tab_quotes[i] == type)
			count_type++;
		i++;
	}
	return (count_type);
}