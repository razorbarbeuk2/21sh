/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:26:09 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 16:01:20 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_strdel(char **as)
{
	if (!*as)
		return ;
	free(*as);
	*as = NULL;
}

void	ft_strdel_double(char **as)
{
	if (!as)
		return ;
	free(as);
	as = NULL;
}
