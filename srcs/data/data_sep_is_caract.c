/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sep_is_caract.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:47:24 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/18 14:41:02 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int data_check_quote_caract(char *str, int *d)
{
	int i;

	i = 1;
	while (str[i])
	{
		if(data_check_quote(str[i]))
			break ;
		i++;
	}
	(*d) += i;
	return (i);
}

unsigned char data_check_quote_type(char c)
{
	if (c == '"')
		return (QUOTE_DOUBLE);
	if (c == '\'')
		return (QUOTE_SIMPLE);
	return (0);
}

int data_check_quote(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

int data_check_false_caract(char *c)
{
	if ((*c) == '&' || (*c) == '>' || (*c) == '<' || (*c) == '|' || (*c) == ';')
		return (1);
	return (0);
}

int data_check_caract(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		return (1);
	return (0);
}