/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:56:16 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/30 18:56:20 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*str;

	n = 0;
	str = NULL;
	if (s1)
	{
		if ((str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))) == NULL)
			return (NULL);
		while (n < ft_strlen(s1))
		{
			str[n] = s1[n];
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	return (NULL);
}
