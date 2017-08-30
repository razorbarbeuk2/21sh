/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:42:06 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/27 20:42:08 by RAZOR            ###   ########.fr       */
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
		(*type) = 3;
	return (0);
}