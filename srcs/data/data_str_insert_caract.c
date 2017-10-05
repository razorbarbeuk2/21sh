/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_insert_caract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:47:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/05 17:01:29 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_list *ft_add_print_new_node(char result)
{
	t_list *lst;

	lst = ft_memalloc(sizeof(t_list));
	if (lst)
	{
		lst->content = ft_memalloc(2 * sizeof(char));
		((char *)lst->content)[0] = result;
		((char *)lst->content)[1] = '\0';
		lst->content_size = 0;
		lst->set_select = 0;
		lst->type = 0;
		lst->next = NULL;
		lst->prev = NULL;
		lst->content_size = 2;
	}
	return (lst);
}

static t_list *ft_add_print_caract_middleline(t_data *data, char result)
{
	t_list *tmp_cur;
	t_list *tmp_next;

	tmp_next = NULL;
	tmp_cur = data->entry->line;
	tmp_cur = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst - 1));
	tmp_next = tmp_cur->next;
	tmp_cur->next = NULL;
	ft_lstadd_back(&tmp_cur, ft_add_print_new_node(result));
	tmp_cur->next->next = tmp_next;
	data->entry->cut_line = tmp_next;
	return (tmp_cur);
}

int ft_add_print_caract(t_data *data, char result)
{
	t_list *tmp_cur;
	
	tmp_cur = data->entry->line;
	data->entry->cut_line = NULL;
	if (!data->sel->i_lst)
	{
		ft_lstadd(&tmp_cur, ft_add_print_new_node(result));
		data->entry->cut_line = tmp_cur->next;
	}
	else if (data->sel->i_lst < (int)data->entry->len_line)
	{
		tmp_cur = ft_add_print_caract_middleline(data, result);
		tmp_cur = data->entry->line;
	}
	else 
		ft_lstadd_back(&tmp_cur, ft_add_print_new_node(result));
	data->entry->len_line++;
	data->entry->line = tmp_cur;
	return (1);
}