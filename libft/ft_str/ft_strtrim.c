/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:55:01 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 16:06:28 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s)
{
	int	i;
	int	st;
	int	end;
	int	len;

	i = 0;
	st = 0;
	len = 0;
	end = ft_strlen(s);
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
		st = i;
		i = end;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
			i--;
		len = i - st + 1;
	}
	return (ft_strsub(s, st, (size_t)len));
}
