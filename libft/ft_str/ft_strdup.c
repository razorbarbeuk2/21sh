/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:56:16 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 16:01:30 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*str;

	n = 0;
	str = NULL;
	if ((str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))) == NULL)
		return (NULL);
	if (s1)
	{
		while (n < ft_strlen(s1))
		{
			str[n] = s1[n];
			n++;
		}
		str[n] = '\0';
	}
	s1 = NULL;
	return (str);
}
