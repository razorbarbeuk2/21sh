/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_CPY.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:18:02 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/11 11:55:54 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_cpy_word_left(t_data *data, int result)
{
	t_list	*tmp;
	int		_i;

	(void)result;
	tmp = NULL;
	_i = 0;
	_i = data->sel->i_lst;
	if (data->sel->i_lst > 0)
	{
		tputs(tgetstr("so", NULL), 1, ft_putchar_select);
		tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
		ft_move_cursor(data, LEFT);
		ft_putchar_fd(((char *)tmp->content)[0], data->sel->tty);	
		tputs(tgetstr("me", NULL), 1, ft_putchar_select);
		ft_move_cursor(data, LEFT);
	}
	if (data->sel->i_lst != 0)
			data->sel->i_lst++;
	return ;
}

void	ft_cpy_word_right(t_data *data, int result)
{
	t_list	*tmp;

	(void)result;
	tmp = NULL;
	if (data->sel->i_lst < (int)data->entry->len_line - 1)
	{
		tputs(tgetstr("so", NULL), 1, ft_putchar_select);
		tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
		ft_putchar_fd(((char *)tmp->content)[0], data->sel->tty);
		motion_list(data, 'R');
		tputs(tgetstr("me", NULL), 1, ft_putchar_select);
	}
	return ;
}