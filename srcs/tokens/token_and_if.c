/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_and_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:43:29 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/21 12:27:55 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_token_and_if(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int it;

	it = 0;
	it = (*io);
	if (str[it] == '&')
	{
		if (str[it] == '&' && str[it + 1] == '&' && !data_check_false_caract(&str[it + 2]))
		{
			(*io) += data_check_is_token_operator(token_list, TYPE_AND_IF, "&&", (*io));
			return (1);
		}
		else
		{
			(*type) = TYPE_AND_IF;
			return (-1);
		}
	}
	return (0);
}