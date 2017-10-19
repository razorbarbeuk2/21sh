/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lst_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:06:28 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/19 14:52:32 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int convert_data_lst_tab(t_data *data)
{
	t_list	*line;
	int 	i;

	i = 0;
	line = data->entry->line;
	if (line)
	{
		data->entry->line_str = (char *)ft_memalloc((data->entry->len_line + 1)*sizeof(char));
		while(line)
		{
			data->entry->line_str[i] = ((char *)line->content)[0];
			line = line->next;
			i++;
		}
		data->entry->line_str[i] = '\0';
		return (1);
	}
	return (0);
}