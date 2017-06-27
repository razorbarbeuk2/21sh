/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_CPY.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:18:02 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/26 15:51:39 by gbourson         ###   ########.fr       */
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
	ft_putchar_fd(((char *)tmp->content)[0], data->term->tty);	
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
		tmp = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst + 1));
		ft_putchar_fd(((char *)tmp->content)[0], data->term->tty);
		motion_list(data, 'R');
		tputs(tgetstr("me", NULL), 1, ft_putchar_select);
		ft_lstadd_back(&data->entry->cpy, ft_lstnew(&tmp->content, ft_strlen(tmp->content + 1)));
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
		while (tmp)
		{
			print_character(data, ((char *)tmp->content)[0]);
			tmp = tmp->next;
		}
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	}
	return ;
}


void	ft_paste_word_cut(t_data *data)
{
	t_list	*tmp;
	int		_count;
	int		_i;
	int		_c;

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
			ft_move_cursor(data, RIGHT);
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
			ft_move_cursor(data, RIGHT);
			get_pos_prompt(data);
		}
		ft_paste_word_cpy(data);
	}
	return ;
}