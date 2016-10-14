/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:17:41 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 16:05:57 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	if (!(s = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (s)
	{
		i = 0;
		while (i != size + 1)
		{
			s[i] = '\0';
			i++;
		}
	}
	return (s);
}
