/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:39:58 by gbourson          #+#    #+#             */
/*   Updated: 2017/07/06 17:20:56 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!(new = (void *)malloc((size))))
		ft_print_err("ERROR MALLOC");
	ft_bzero(new, size);
	return (new);
}
