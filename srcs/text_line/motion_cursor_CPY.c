/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_CPY.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:18:02 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/04 23:09:47 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void ft_cpy_word_pos(t_data *data)
{
	data->sel->pos_tmp[0] = data->sel->pos[0];
	data->sel->pos_tmp[1] = data->sel->pos[1];
	data->sel->i_lst_tmp = data->sel->i_lst;
}

static void ft_cpy_word_set_state(t_data *data, t_list *tmp)
{
	if (!tmp->set_select)
	{
		tputs(tgetstr("so", NULL), 1, ft_putchar_select);
		ft_putchar_fd(((char *)tmp->content)[0], data->term->tty);
		tputs(tgetstr("me", NULL), 1, ft_putchar_select);
		tmp->set_select = 1;
	}
	else
	{
		ft_putchar_fd(((char *)tmp->content)[0], data->term->tty);
		tmp->set_select = 0;
	}
}

static void ft_cpy_word_left_set_select(t_data *data, int DIR)
{
	t_list 			*tmp;

	tmp = NULL;
	ft_move_cursor(data, DIR, MOVE_LST);
	tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	ft_cpy_word_set_state(data, tmp);
	ft_lstadd(&data->entry->cpy, ft_lstnew(&(((char *)tmp->content)[0]), sizeof(char)));
}

void ft_cpy_word_left(t_data *data)
{
	int	PROMPT_CPY;

	PROMPT_CPY = 0;
	if (data->sel->pos[1] == 0)
		PROMPT_CPY = 1;
	if (data->entry->line && data->sel->i_lst)
	{
		ft_cpy_word_left_set_select(data, LEFT);
		(!PROMPT_CPY) ? ft_move_cursor(data, LEFT, 0) : ft_move(data, data->sel->pos[1]--, data->sel->pos[0]);
		ft_cpy_word_pos(data);
		PROMPT_CPY = 0;
	}
	return;
}

void ft_cpy_word_right(t_data *data)
{
	if (data->sel->i_lst < (int)data->entry->len_line)
	{
		ft_cpy_word_left_set_select(data, RIGHT);
		motion_list(data, 'R');
		// tputs(tgetstr("so", NULL), 1, ft_putchar_select);
		//tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
		// ft_putchar_fd(((char *)tmp->content)[0], data->term->tty);
		// tputs(tgetstr("me", NULL), 1, ft_putchar_select);
		//ft_lstadd_back(&data->entry->cpy, ft_lstnew(&(((char *)tmp->content)[0]), sizeof(char)));
		ft_cpy_word_pos(data);
	}
	return;
}

