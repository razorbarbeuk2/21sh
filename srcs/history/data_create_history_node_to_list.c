/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_history_node_to_list.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:25:12 by gbourson          #+#    #+#             */
/*   Updated: 2017/07/20 15:58:40 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void free_str_historic_node(char *str_n, char *str)
{
	if (str && str_n)
	{
		ft_strdel(&str);
		ft_strdel(&str_n);
		str = NULL;
		str_n = NULL;
	}
	return ;
}

static int add_num_historic_node(t_data *data, char *str_n, char *str, int i)
{
	if (str && str_n)
	{
		str_n[i] = ' ';
		str_n[i + 1] = '\0';
		ft_strdel(&str);
		str = NULL;
		str = ft_strjoin(str_n, data->entry->line_str);
		ft_lstadd_back(&data->historic->list_historic, ft_lstnew(str, ft_strlen(str) + 1));
		free_str_historic_node(str_n, str);
		data_uptdate_count_history_file(data);
		return (1);
	}
	return (0);
}

int add_sentence_historic_node_to_list(t_data *data)
{
	t_list *lst;
	int i;
	char *str;
	char *str_n;
	int count;

	i = 0;
	count = 0;
	lst = NULL;
	str = ft_itoa(ft_lst_count(data->historic->list_historic) + 1);
	str_n = (char *)ft_memalloc((ft_strlen(str) + 2) * sizeof(char));
	while (str[i])
	{
		str_n[i] = str[i];
		i++;
	}
	if (!add_num_historic_node(data, str_n, str, i))
		return (-1);
	return (1);
}