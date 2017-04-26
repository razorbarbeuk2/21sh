/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_del_caract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:23:36 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/26 17:35:31 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_del_lst(void *content, size_t content_size)
{
	if (content)
	{
		free(content);
		content_size = 0;
	}
	return ;
	
}

int		ft_del_print_caract(t_data *data, char result)
{
	t_list	*tmp_tools;
	t_list	*tmp_swap;
	t_list	*tmp_st;

	tmp_st = data->entry->line;
	tmp_swap = NULL;
	tmp_tools = NULL;
	if (result && data->entry->line)
	{
		if ((int)data->entry->len_line && data->sel->i_lst == 0)
		{
			tmp_swap = data->entry->line;
			data->entry->line = tmp_swap->next;
			data->entry->cut_line = data->entry->line;
			ft_lstdelone(&tmp_swap, &ft_del_lst);
		}
		if (data->sel->i_lst <= (int)data->entry->len_line && data->sel->i_lst > 1)
		{
			tmp_tools = ft_move_at_list(data, &data->entry->line, data->sel->i_lst - 1);
			tmp_swap = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
			if (tmp_swap->next)
			{
				tmp_tools->next = ft_move_at_list(data, &data->entry->line, data->sel->i_lst)->next;
				data->entry->cut_line = tmp_swap->next;
			}
			else
				tmp_tools->next = NULL;
			ft_lstdelone(&tmp_swap, &ft_del_lst);
		}
		data->entry->len_line--;
	}
	else
	{
		data->entry->line = NULL;
		data->entry->len_line = 0;
	}
	return (1);
}