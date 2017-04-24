/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_del_caract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:23:36 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/23 22:41:08 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_del_lst(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

int		ft_del_print_caract(t_data *data, char result)
{
	t_list	*tmp_lst;
	t_list	*tmp_st;
	t_list	*tmp_swap;

	tmp_st = NULL;
	tmp_swap = NULL;
	tmp_lst = data->entry->line;
	data->entry->cut_line = NULL;
	tmp_st = tmp_lst;
	if (result)
	{
		if ((data->sel->i_lst) < (int)data->entry->len_line)
		{
			tmp_lst = ft_move_at_list(data, &tmp_lst, data->sel->i_lst - 1);
			tmp_swap = tmp_lst->next->next;
			ft_lstdelone(&tmp_lst->next, &ft_del_lst);
			tmp_lst->next = tmp_swap;
			data->entry->cut_line = tmp_swap;
			tmp_lst = tmp_st;
		}
		else
			ft_strdel((char **)&tmp_lst->content);
		data->entry->line = tmp_lst;
		data->entry->len_line--;
	}
	return (1);
}