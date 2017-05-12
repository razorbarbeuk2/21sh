/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_DEL.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:57:50 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/12 13:52:03 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void		del_print_middle_sentence(t_data *data)
{
	int i_lst;

	i_lst = 0;
	i_lst = data->sel->i_lst;
	tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
	ft_move_end(data);
	get_pos_prompt(data);
	if (data->sel->pos[1] != (data->sel->width - 1))
		tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
	else
	{
		tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
		ft_move(data, data->sel->pos[1]--, data->sel->pos[0]);
	}
	tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	print_lst_line(data, data->entry->cut_line);
	data->sel->i_lst = i_lst;
}

void		del_one_character(t_data *data, char result)
{
	int i_lst;
	int i_;

	i_lst = 0;
	i_ = 0;
	(void)result;
	if ((int)data->entry->len_line && data->sel->i_lst)
	{
		if (data->sel->i_lst == (int)data->entry->len_line)
		{
			ft_del_print_caract(data, result);
			data->entry->len_line--;
			if ((data->sel->pos[1]) == 0 && !i_)
			{
				ft_move(data, (data->sel->pos[1] = ((int)data->sel->width - 1)), (data->sel->pos[0] -= 1));
				i_ = 1;
			}
			ft_move_cursor(data, LEFT);
			tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
			if ((data->sel->pos[1]) == (data->sel->width - 1) && i_)
			{
				ft_move(data, data->sel->pos[1] = ((int)data->sel->width - 1), data->sel->pos[0]);
				i_ = 0;
			}
			return ;
			
		}
		else if (data->sel->i_lst > 0 && data->sel->i_lst < (int)data->entry->len_line)
		{
			ft_del_print_caract(data, result);
			data->entry->len_line--;
			ft_move_cursor(data, LEFT);
			tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
			del_print_middle_sentence(data);
			return ;
		}
		return ;
	}
	return ;
}