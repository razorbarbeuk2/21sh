/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_DEL.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:57:50 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/05 18:16:33 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void		del_print_end_sentence(t_data *data)
{
	int i_;
	
	i_ = 0;
	ft_del_print_caract(data);
	if ((data->sel->pos[1]) == 0 && !i_)
	{
		ft_move(data, (data->sel->pos[1] = ((int)data->term->width - 1)), (data->sel->pos[0] -= 1));
		i_ = 1;
	}
	ft_move_cursor(data, LEFT, MOVE_LST);
	tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
	if ((data->sel->pos[1]) == (data->term->width - 1) && i_)
	{
		ft_move(data, data->sel->pos[1] = ((int)data->term->width - 1), data->sel->pos[0]);
		i_ = 0;
	}
	return ;
}

static void		del_print_middle_sentence(t_data *data)
{
	int i_lst;

	i_lst = 0;
	i_lst = data->sel->i_lst;
	ft_del_print_caract(data);
	ft_move_cursor(data, LEFT, MOVE_LST);
	tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
	print_lst_line(data, data->entry->cut_line);
	data->sel->i_lst = i_lst;
	return ;
}

void		del_one_character(t_data *data, int result)
{
	int len;

	(void)result;
	len = ((int)data->sel->len_prompt + (int)data->entry->len_line);
	data->entry->offset_line = (len / (data->term->width) + 1);
	if ((int)data->entry->len_line && data->sel->i_lst)
	{
		if (data->sel->i_lst == (int)data->entry->len_line)
			return(del_print_end_sentence(data));
		else if (data->sel->i_lst > 0 && data->sel->i_lst < (int)data->entry->len_line)
			return (del_print_middle_sentence(data));
	}
	return ;
}