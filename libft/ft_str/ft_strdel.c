/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:26:09 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/23 16:04:36 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_strdel(char **as)
{
	if (!*as && as)
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
