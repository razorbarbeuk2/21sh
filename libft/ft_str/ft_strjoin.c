/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:59:03 by gbourson          #+#    #+#             */
/*   Updated: 2017/07/07 00:41:33 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		r;
	char	*str;

	r = 0;
	r = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc((r + 1) * sizeof(char))))
		return (NULL);
	if (s1 && s2)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
