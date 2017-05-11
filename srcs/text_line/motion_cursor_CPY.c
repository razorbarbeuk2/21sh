/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_CPY.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:18:02 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/11 18:26:17 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int pos(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_cpy_word_pos(t_data *data)
{
	data->sel->pos_tmp[0] = data->sel->pos[0];
	data->sel->pos_tmp[1] = data->sel->pos[1];
	data->sel->i_lst_tmp = data->sel->i_lst;
}

void	ft_cpy_word_left(t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	tputs(tgetstr("so", NULL), 1, ft_putchar_select);
	tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	ft_move_cursor(data, LEFT);
	ft_putchar_fd(((char *)tmp->content)[0], data->sel->tty);	
	tputs(tgetstr("me", NULL), 1, ft_putchar_select);
	data->sel->i_lst++;
	ft_lstadd(&data->entry->cpy, ft_lstnew(&(((char *)tmp->content)[0]), sizeof(char)));
	ft_move_cursor(data, LEFT);
	ft_cpy_word_pos(data);
	return ;
}

void	ft_cpy_word_right(t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	if (data->sel->i_lst < (int)data->entry->len_line - 1)
	{
		tputs(tgetstr("so", NULL), 1, ft_putchar_select);
		tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
		ft_putchar_fd(((char *)tmp->content)[0], data->sel->tty);
		motion_list(data, 'R');
		tputs(tgetstr("me", NULL), 1, ft_putchar_select);
		ft_add_at(&data->entry->cpy, ((char *)tmp->content)[0]);
		ft_cpy_word_pos(data);
	}
	return ;
}

void	ft_paste_word_cpy(t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = data->entry->cpy;
	if (data->entry->cpy)
	{
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		tputs(tgetstr("im", NULL), 1, ft_putchar_select);
		while (tmp)
		{
			print_character(data, ((char *)tmp->content)[0]);
			tmp = tmp->next;
		}
		tputs(tgetstr("ei", NULL), 1, ft_putchar_select);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	}
	return ;
}


void	ft_paste_word_cut(t_data *data)
{
	t_list	*tmp;
	int		_count;
	int		_i;

	tmp = NULL;
	tmp = data->entry->cpy;
	_i = data->sel->i_lst;
	_count = (ft_lst_count(data->entry->cpy) - 1);
	if (data->entry->cpy)
	{
		ft_move(data, data->sel->pos_tmp[1], data->sel->pos_tmp[0]);
		while (_count--)
			ft_move_cursor(data, RIGHT);
		_count = ft_lst_count(data->entry->cpy);
		while (_count--)
		{
			tmp = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst_tmp + _count));
			del_one_character(data, ((char *)tmp->content)[0]);
			tmp = NULL;
		}
		// _count = ft_lst_count(data->entry->cpy);
		// ft_move_home(data);
		pos(2);
		// _i = pos(_i - _count);
		// while (_i--)
		// 	ft_move_cursor(data, RIGHT);
		// ft_paste_word_cpy(data);
	}
	return ;
}