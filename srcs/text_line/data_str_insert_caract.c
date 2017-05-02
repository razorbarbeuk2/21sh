/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_insert_caract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:47:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/02 18:35:55 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_add_at(t_list **lst, char result)
{
	ft_lstadd_back(lst, ft_lstnew(&result, sizeof(char)));
}

int		ft_add_print_caract(t_data *data, char result)
{
	t_list	*tmp_lst;
	t_list	*tmp_st;
	t_list	*tmp_swap;

	tmp_st = NULL;
	tmp_swap = NULL;
	tmp_lst = NULL;
	tmp_lst = data->entry->line;
	data->entry->cut_line = NULL;
	tmp_st = tmp_lst;
	if (result)
	{
		if (!data->sel->i_lst)
		{
			ft_add_at(&tmp_swap, result);
			tmp_swap->next = data->entry->line;
			tmp_lst = tmp_swap;
		}
		else if ((data->sel->i_lst < (int)data->entry->len_line) && data->sel->i_lst > 0)
		{

			tmp_lst = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
			tmp_swap = tmp_lst->next;
			tmp_lst->next = NULL;
			ft_add_at(&tmp_lst, result);
			tmp_lst->next->next = tmp_swap;
			data->entry->cut_line = tmp_swap;
			tmp_lst = tmp_st;
		}
		else
			ft_add_at(&tmp_lst, result);
		data->entry->line = tmp_lst;
		data->entry->len_line++;
		tmp_swap = NULL;
		tmp_lst = NULL;
		tmp_st = NULL;
	}
	return (1);
}
