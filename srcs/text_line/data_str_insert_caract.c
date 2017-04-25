/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_insert_caract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:47:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/25 14:59:23 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_add_at(t_list **lst, char result)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(&result);
	tmp[1] = '\0';
	ft_lstadd_back(lst, ft_lstnew(tmp, sizeof(char *)));
	ft_strdel(&tmp);
}

int		ft_add_print_caract(t_data *data, char result)
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
		if ((int)data->entry->len_line > 0 && data->sel->i_lst == 0)
		{
			tmp_lst = NULL;
			ft_add_at(&tmp_lst, result);
			tmp_lst->next = data->entry->line;
			data->entry->line = tmp_lst;
			data->entry->cut_line = tmp_lst->next;
			data->entry->len_line++;
			return (1);
		}
		if (data->sel->i_lst < (int)data->entry->len_line && data->sel->i_lst > 0)
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
	}
	return (1);
}
