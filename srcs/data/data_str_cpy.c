/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:25:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/05 19:42:03 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void print_lst_in_line(t_data *data, t_list *tmp)
{
	while (tmp)
	{
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

void ft_paste_word_cpy(t_data *data, int mode)
{
	if (mode)
		init_cpy_list(data);
	if (data->entry->cpy)
	{
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		print_lst_in_line(data, data->entry->cpy);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	}
	return;
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
		if (tmp->set_select)
			ft_del_print_caract(data);
		ft_move_cursor(data, LEFT, MOVE_LST);
	}
	reset_line(data);
	return ;
}

void ft_paste_word_cut(t_data *data)
{
	t_list *tmp;
	t_list *start;
	//int 	pos;

	tmp = data->entry->line;
	start = data->entry->line;
	init_cpy_list(data);
	ft_paste_word_cut_del(data);
	ft_paste_word_cpy(data, CUT);
	//tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	//data->sel->i_lst = ft_move_at_line(data, &data->entry->line, tmp);
	//pos = ft_move_at_line(data, &data->entry->line, tmp);
	//if (data->entry->cpy)
	//{
		// tmp = ft_move_at_list(data, &data->entry->line, pos);
		// data->entry->line = tmp;
		// tmp = data->entry->line->next;
		// data->entry->line->next = NULL;
		// print_lst_in_line(data, data->entry->cpy);
		// ft_putendl("\nTEST==========");
		// print_lst_line(data, data->entry->cpy);
		// ft_putendl("\n--------------");
		// print_lst_line(data, data->entry->line);
		// ft_putendl("\n--------------");
		// ft_putnbr(pos);
		// ft_putendl("\n--------------");
		// data->entry->line = ft_move_at_list(data, &data->entry->line, ft_lst_count(data->entry->line));
		// data->entry->line->next = tmp;
		// data->entry->len_line = ft_lst_count(data->entry->line);
		// data->entry->line = start;
	//}
	//return;
}

// void ft_paste_word_cut(t_data *data)
// {
// 	t_list *tmp;
// 	int _count;
// 	int _i;
// 	int _c;

// 	tmp = NULL;
// 	tmp = data->entry->cpy;
// 	_i = data->sel->i_lst;
// 	_count = 0;
// 	_c = 0;
// 	if (data->entry->cpy)
// 	{
// 		ft_move(data, (data->sel->pos_tmp[1] - 1), data->sel->pos_tmp[0]);
// 		_count = ft_lst_count(data->entry->cpy);
// 		data->sel->i_lst = data->sel->i_lst_tmp;
// 		while (_count--)
// 			ft_move_cursor(data, RIGHT, MOVE_LST);
// 		_count = ft_lst_count(data->entry->cpy);
// 		while (_count--)
// 			del_one_character(data, 0);
// 		_count = ft_lst_count(data->entry->cpy);
// 		_c = pos(_i - _count);
// 		data->sel->i_lst = _c;
// 		ft_move_home(data);
// 		get_pos_prompt(data);
// 		while (_c--)
// 		{
// 			ft_move_cursor(data, RIGHT, MOVE_LST);
// 			get_pos_prompt(data);
// 		}
// 		ft_paste_word_cpy(data);
// 	}
// 	return;
// }

