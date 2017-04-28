/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_del_caract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:23:36 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/28 17:06:45 by gbourson         ###   ########.fr       */
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

	tmp_swap = NULL;
	tmp_tools = NULL;
	(void)result;
	tmp_st = data->entry->line;
	data->entry->cut_line = NULL;
	if ((int)data->entry->len_line > 0 && data->sel->i_lst > 0)
	{
		if (data->sel->i_lst == (int)data->entry->len_line)
		{
			if ((int)data->entry->len_line > 1)
			{
				tmp_swap = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst - 1));
				tmp_swap->next = NULL;
			}
			tmp_swap = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
			ft_lstdelone(&tmp_swap, &ft_del_lst);
			return (1);
		}
		else if (data->sel->i_lst < (int)data->entry->len_line && data->sel->i_lst > 1)
		{
			tmp_tools = ft_move_at_list(data, &data->entry->line, data->sel->i_lst - 1);
			tmp_swap = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
			if (tmp_swap->next)
			{
				tmp_tools->next = tmp_swap->next;
				data->entry->cut_line = tmp_swap->next;
			}
			ft_lstdelone(&tmp_swap, &ft_del_lst);
			return (1);
		}
		
	}
	else
	{
		data->entry->line = NULL;
		data->entry->len_line = 0;
	}
	return (0);
}