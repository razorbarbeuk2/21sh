/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_insert_caract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:47:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/21 16:52:53 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_del_print_caract(t_data *data, char result)
{
	(void)result;
	(void)data;
	return (1);
}

void	ft_add_at(t_list **lst, char result)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(&result);
	tmp[1] = '\0';
	ft_lstadd_back(lst, ft_lstnew(tmp, sizeof(char *)));
	ft_strdel(&tmp);
}

// t_list	*ft_add_swap(t_data *data, t_list **tmp_lst, t_list **tmp_st)
// {
// 	int		count;
// 	t_list	*tmp_swap;
	
// 	tmp_swap = NULL;
// 	count = data->sel->i_lst;
// 	if (tmp_lst)
// 	{
// 		tmp_swap = (*tmp_lst);
// 		while (tmp_swap && count--)
// 		{
// 			tmp_swap->prev = tmp_swap;
// 			tmp_swap = tmp_swap->next;
// 		}
// 		(*tmp_st) = tmp_swap->next;
// 		tmp_swap->next = NULL;
// 	}
// 	return (tmp_swap); 
// }

// int		ft_add_print_caract(t_data *data, char result)
// {
// 	t_list	*tmp_lst;
// 	t_list	*tmp_st;
// 	t_list	*tmp_swap;

// 	tmp_st = NULL;
// 	tmp_swap = NULL;
// 	data->entry->cut_line = NULL;
// 	tmp_lst = data->entry->line;
// 	if (result)
// 	{
// 		if (data->sel->pos[1] < ((int)data->sel->len_prompt + (int)data->entry->len_line))
// 		{
// 			tmp_swap = ft_add_swap(data, &tmp_lst, &tmp_st);
// 			ft_add_at(&tmp_swap, result);
// 			tmp_swap->next = tmp_st;
// 			data->entry->cut_line = tmp_swap->next;
// 			print_lst_line(data, data->entry->cut_line);
// 		}
// 		else
// 			ft_add_at(&tmp_lst, result);
// 		data->entry->line = tmp_lst;
// 		data->entry->len_line++;

// 	}
// 	return (1);
// }

t_list 	*ft_move_at_list(t_data *data, t_list **lst)
{
	t_list	*tmp_lst;
	int 	count;

	tmp_lst = NULL;
	tmp_lst = data->entry->line;
	count = data->sel->i_lst;
	(*lst) = (*lst) + data->sel->i_lst - 1;
	//ft_putstr_fd("F", data->sel->tty);
	while (count--)
		tmp_lst = tmp_lst->next;
	(*lst)->next = NULL;
	return (tmp_lst);
}

int		ft_add_print_caract(t_data *data, char result)
{
	t_list	*tmp_lst;
	t_list	*tmp_st;
	t_list	*st;
	t_list	*tmp_swap;

	tmp_st = NULL;
	tmp_swap = NULL;
	st = NULL;
	tmp_lst = data->entry->line;
	st = tmp_lst;
	data->entry->cut_line = NULL;
	if (result)
	{
		if (data->sel->i_lst < (int)data->entry->len_line)
		{
			tmp_swap = ft_move_at_list(data, &tmp_lst);
			ft_add_at(&tmp_st, result);
			tmp_lst->next = tmp_st;
			tmp_st->next = tmp_swap;
			tmp_lst = st;
			//print_lst_line(data, tmp_lst);
		}
		else
			ft_add_at(&tmp_lst, result);
		data->entry->line = tmp_lst;
		data->entry->len_line++;
	}
	return (1);
}




















