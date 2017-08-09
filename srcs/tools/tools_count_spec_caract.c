/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_count_spec_caract.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 14:29:56 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/07 15:57:13 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			ft_count_word_spec_caract(char *line_str, char *caract)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line_str[i])
	{
		if (!data_check_spec_caract(line_str[i], caract) && data_check_spec_caract(line_str[i + 1], caract))
			count++;
		else if (data_check_spec_caract(line_str[i], caract))
			count++;
		else if ((!data_check_spec_caract(line_str[i], caract)) && line_str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

int			len_word_caract(char *line_str, char *caract)
{
	int i;
	
	i = 0;
	if (line_str[0] == caract[0])
		return (1);
	else
	{
		while (line_str[i] && (line_str[i] != caract[0]))
			i++;
		return (i);
	}
	return (0);
}