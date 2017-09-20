/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_semicol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:44:10 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/20 19:09:06 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_token_semi(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int it;

	it = 0;
	it = (*io);
	if (str[it] == ';')
	{
		if (str[it] == ';' && data_check_caract(str[it + 1]))
		{
			(*io) += data_check_is_token_operator(token_list, TYPE_DSEMI, ";", (*io));
			return (1);
		}
		else
		{
			(*type) = TYPE_DSEMI;
			return (-1);
		}
	}
	return (0);
}