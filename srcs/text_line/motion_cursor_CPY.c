/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_CPY.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:18:02 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/07 17:22:47 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void ft_cpy_word_set_state(t_data *data, t_list *tmp)
{
	if (!tmp->set_select)
	{
		tputs(tgetstr("so", NULL), 1, ft_putchar_select);
		ft_putchar_fd(((char *)tmp->content)[0], data->term->tty);
		tputs(tgetstr("me", NULL), 1, ft_putchar_select);
		tmp->set_select = 1;
	}
	return ;
}

static int ft_cpy_word_left_set_select(t_data *data, int DIR)
{
	t_list 			*tmp;

	tmp = NULL;
	tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	if (tmp)
	{
		ft_cpy_word_set_state(data, tmp);
		if (data->sel->i_lst != 0)
			ft_move_cursor(data, DIR, MOVE_LST);
		return (1);
	}
	return (0);
}

void ft_cpy_word_left(t_data *data)
{
	if (data->entry->line && data->sel->i_lst < (int)data->entry->len_line)
	{
		ft_cpy_word_left_set_select(data, LEFT);
		ft_move_cursor(data, LEFT, 0);
	}
	return;
}

void ft_cpy_word_right(t_data *data)
{
	if (data->sel->i_lst < ((int)data->entry->len_line))
	{
		ft_cpy_word_left_set_select(data, RIGHT);
		ft_move_cursor(data, LEFT, 0);
	}
	return;
}

