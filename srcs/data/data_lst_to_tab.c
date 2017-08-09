/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lst_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:06:28 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/03 18:16:31 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char 		*convert_data_lst_tab(t_data *data)
{
	char 	*str;
	t_list	*lst;
	int 	i;

	i = 0;
	lst = NULL;
	lst = data->entry->line;
	if (data->entry->len_line)
	{
		str = (char *)ft_memalloc((data->entry->len_line + 1)*sizeof(char));
		while(lst)
		{
			str[i] = ((char *)lst->content)[0];
			lst = lst->next;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}