/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:04:35 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 16:05:51 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2 && n)
	{
		while ((s1[i] == s2[i]) && (s1[i] && s2[i]) && i < n - 1)
			i++;
		if (s1[i] == s2[i])
			return (1);
		else
			return (0);
	}
	return (0);
}
