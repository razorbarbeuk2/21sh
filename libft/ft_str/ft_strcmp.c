/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:13:15 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 12:22:44 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// int		ft_strcmp(const char *s1, const char *s2)
// {
// 	int i;

// 	i = 0;
// 	while (s1[i] && s2[i] && (s1[i] == s2[i]))
// 		i++;
// 	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
// }


int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}