/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:25:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/04 23:05:39 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int pos(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void ft_paste_word_cpy(t_data *data)
{
	t_list *tmp;

	tmp = NULL;
	tmp = data->entry->cpy;
	if (data->entry->cpy)
	{
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		while (tmp)
		{
			print_character(data, ((char *)tmp->content)[0]);
			tmp = tmp->next;
		}
		reset_line(data);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	}
	return;
}

void ft_paste_word_cut(t_data *data)
{
	t_list *tmp;
	int _count;
	int _i;
	int _c;

	tmp = NULL;
	tmp = data->entry->cpy;
	_i = data->sel->i_lst;
	_count = 0;
	_c = 0;
	if (data->entry->cpy)
	{
		ft_move(data, (data->sel->pos_tmp[1] - 1), data->sel->pos_tmp[0]);
		_count = ft_lst_count(data->entry->cpy);
		data->sel->i_lst = data->sel->i_lst_tmp;
		while (_count--)
			ft_move_cursor(data, RIGHT, MOVE_LST);
		_count = ft_lst_count(data->entry->cpy);
		while (_count--)
			del_one_character(data, 0);
		_count = ft_lst_count(data->entry->cpy);
		_c = pos(_i - _count);
		data->sel->i_lst = _c;
		ft_move_home(data);
		get_pos_prompt(data);
		while (_c--)
		{
			ft_move_cursor(data, RIGHT, MOVE_LST);
			get_pos_prompt(data);
		}
		ft_paste_word_cpy(data);
	}
	return;
}