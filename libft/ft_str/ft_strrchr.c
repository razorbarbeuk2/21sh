/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:08:46 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 16:06:07 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	i = ft_strlen(s);
	while (s[i] != c && i != 0)
		i--;
	if (s[i] == c)
		return ((char *)s + i);
	else
		return (0);
}
