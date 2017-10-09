/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:25:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/09 14:15:36 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_cpy_word_pos(t_data *data)
{
	data->sel->pos_tmp[0] = data->sel->pos[0];
	data->sel->pos_tmp[1] = data->sel->pos[1];
	data->sel->i_lst_tmp = data->sel->i_lst;
}

static void print_lst_in_line(t_data *data, t_list *tmp)
{
	while (tmp)
	{
		get_pos_prompt(data);
		print_character(data, ((char *)tmp->content)[0]);
		tmp = tmp->next;
	}
	return ;
}

void init_cpy_list(t_data *data)
{
	t_list *tmp;

	tmp = data->entry->line;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->set_select)
				ft_lstadd_back(&data->entry->cpy, ft_lstnew(&(((char *)tmp->content)[0]), sizeof(char)));
			tmp = tmp->next;
		}
	}
	return;
}

void ft_paste_word_cpy(t_data *data)
{
	init_cpy_list(data);
	if (data->entry->cpy)
	{
		get_pos_prompt(data);
		print_lst_in_line(data, data->entry->cpy);
		ft_lstdel(&data->entry->cpy, &ft_free_node);	
	}
	return ;
}

static void ft_paste_word_cut_del(t_data *data)
{
	t_list *tmp;

	ft_move_end(data);
	tmp = data->entry->line;
	while (data->sel->i_lst != 0)
	{
		tmp = NULL;
		tmp = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst - 1));
		if (tmp && tmp->set_select)
			ft_del_print_caract(data);
		ft_move_cursor(data, LEFT, MOVE_LST);
	}
	return ;
}

void ft_paste_word_cut(t_data *data)
{
	t_list *tmp;

	tmp = data->entry->line;
	init_cpy_list(data);
	tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	ft_paste_word_cut_del(data);
	if (tmp && !tmp->set_select)
		data->sel->i_lst = ft_move_at_line(data, &data->entry->line, tmp);
	else
		data->sel->i_lst = ft_lst_count(data->entry->line);
	print_lst_in_line(data, data->entry->cpy);
	data->entry->len_line = ft_lst_count(data->entry->line);
	ft_lstdel(&data->entry->cpy, &ft_free_node);
	reset_line(data);
	return ;
}

