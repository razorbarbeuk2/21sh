/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:48:50 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/15 15:58:03 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			len_word(char *str)
{
	int 	i;

	i = 0;
	while (!data_check_caract(str[i]) && str[i])
		i++;
	return (i);
}

int 		ft_count_word_caract(char *str)
{
	int 	i;
	int 	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((!data_check_caract(str[i]) && data_check_caract(str[i + 1])) || (!data_check_caract(str[i]) && str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char 		*trim_str(char *str)
{
	int i;

	i = 0;
	while (data_check_caract(str[i]) && str[i])
		i++;
	return (&str[i]);
}

char	*ft_strcpy_data(char *dst, const char *str)
{
	int i;

	i = 0;
	while (!data_check_caract(str[i]) && str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}