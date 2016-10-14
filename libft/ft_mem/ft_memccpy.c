/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:44:16 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 15:59:06 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*p;
	const char		*o;
	char			l;

	i = 0;
	p = (char *)dst;
	o = (const char *)src;
	l = (char)c;
	while (n--)
	{
		p[i] = o[i];
		if (o[i] == l)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
