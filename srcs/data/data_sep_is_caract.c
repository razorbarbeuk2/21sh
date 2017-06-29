/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sep_is_caract.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:47:24 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/29 11:00:16 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int 		ft_is_caract_(char *str, char *c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			(*c) = '|';
			return (1);
		}
		if (str[i] == ';')
		{
			(*c) = '|';
			return (1);
		}
		i++;
	}
	return (0);
}

int 		data_check_caract(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

int 		data_check_spec_caract(char c, char *caract)
{
	if (c == caract[0])
		return (1);
	return (0);
}