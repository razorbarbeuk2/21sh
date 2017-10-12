/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lst_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:06:28 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/12 17:09:18 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char 		*convert_data_lst_tab(t_data *data, t_list *line)
{
	char 	*str;
	int 	i;

	i = 0;
	if (line)
	{
		str = (char *)ft_memalloc((data->entry->len_line + 1)*sizeof(char));
		while(line)
		{
			str[i] = ((char *)line->content)[0];
			line = line->next;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}