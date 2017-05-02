/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_del_caract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:23:36 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/02 18:48:15 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_del_lst(void *content, size_t content_size)
{
	if (!content)
		return ;
	else
		free(content);
	content_size = 0;
	return ;
}

int		ft_del_print_caract(t_data *data, char result)
{
	t_list	*tmp_tools;
	t_list	*tmp_swap;
	t_list	*tmp_st;

	(void)result;
	tmp_swap = NULL;
	tmp_tools = NULL;
	tmp_st = data->entry->line;
	data->entry->cut_line = NULL;
	if ((int)data->entry->len_line > 0 && data->sel->i_lst)
	{
		if (data->sel->i_lst < (int)data->entry->len_line)
		{
			tmp_tools = ft_move_at_list(data, &data->entry->line, data->sel->i_lst - 1);
			tmp_swap = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
			if (tmp_swap->next && tmp_tools)
			{
				tmp_tools->next = tmp_swap->next;
				data->entry->cut_line = tmp_swap->next;
			}
			else
				data->entry->line = tmp_swap->next;
		}
		else if (data->sel->i_lst == (int)data->entry->len_line)
		{
			tmp_tools = ft_move_at_list(data, &data->entry->line, data->sel->i_lst - 1);
			tmp_swap = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
			if (tmp_tools)
				tmp_tools->next = NULL;
			else
				data->entry->line = tmp_swap->next;
		}
		ft_lstdelone(&tmp_swap, &ft_del_lst);
		tmp_swap = NULL;
		tmp_tools = NULL;
		tmp_st = NULL;
		return (1);
	}
	return (0);
}