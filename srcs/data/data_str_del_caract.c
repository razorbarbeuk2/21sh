/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_del_caract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:23:36 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/05 18:02:02 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_del_lst(void *content, size_t content_size)
{
	if (content)
	{
		free(content);
		content_size = 0;
	}
	return;
}

int ft_del_print_caract_first_line(t_data *data)
{
	t_list *tmp_cur;
	t_list *tmp_next;

	tmp_cur = data->entry->line;
	tmp_next = tmp_cur->next;
	ft_lstdelone(&tmp_cur, &ft_del_lst);
	data->entry->line = tmp_next;
	data->entry->cut_line = tmp_next;
	data->entry->len_line--;
	return (1);
}

int ft_del_print_middle_caract_line(t_data *data)
{
	t_list *tmp_cur;
	t_list *tmp_prev;
	t_list *tmp_next;

	tmp_cur = ft_move_at_list(data, &data->entry->line, data->sel->i_lst - 1);
	tmp_prev = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst - 2));
	tmp_next = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst));
	tmp_prev->next = tmp_next;
	ft_lstdelone(&tmp_cur, &ft_del_lst);
	data->entry->cut_line = tmp_next;
	data->entry->len_line--;
	return (1);
}

int ft_del_print_last_caract_line(t_data *data)
{
	t_list *tmp_cur;
	t_list *tmp_prev;

	tmp_cur = ft_move_at_list(data, &data->entry->line, ((int)data->entry->len_line - 1));
	tmp_prev = ft_move_at_list(data, &data->entry->line, ((int)data->entry->len_line - 2));
	ft_lstdelone(&tmp_cur, &ft_del_lst);
	tmp_prev->next = NULL;
	data->entry->len_line--;
	return (1);
}

int ft_del_print_caract(t_data *data)
{
	data->entry->cut_line = NULL;
	if ((int)data->entry->len_line)
	{
		if (data->sel->i_lst == 1)
			ft_del_print_caract_first_line(data);
		else if (data->sel->i_lst < (int)data->entry->len_line)
			ft_del_print_middle_caract_line(data);
		else if (data->sel->i_lst == (int)data->entry->len_line)
			ft_del_print_last_caract_line(data);
		return (1);
	}
	return (0);
}