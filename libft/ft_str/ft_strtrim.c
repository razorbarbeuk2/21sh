/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:55:01 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 14:51:56 by gbourson         ###   ########.fr       */
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
	end = 0;
	if (s)
	{
		end = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
			return (NULL);
		st = i;
		i = end;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
			i--;
		len = i - st + 1;
		return (ft_strsub(s, st, (size_t)len));
	}
	return(NULL);
}
