/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_LR.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:41:40 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/05 18:33:43 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_move(t_data *data, int x, int y)
{
	if (data)
		tputs(tgoto((tgetstr("cm", NULL)), x, y), 0, ft_putchar_select);
}

void ft_move_left(t_data *data, int state)
{ 
	if (data->sel->pos[1] > (int)data->sel->len_prompt && data->sel->pos[0] == data->sel->pos_start[0])
		tputs(tgoto((tgetstr("le", NULL)), 0, 0), 0, ft_putchar_select);
	else if (data->sel->pos[0] != data->sel->pos_start[0] && data->sel->pos[1] > 0)
		tputs(tgoto((tgetstr("le", NULL)), 0, 0), 0, ft_putchar_select);
	else if (data->sel->pos[0] != data->sel->pos_start[0] && data->sel->pos[1] == 0)
		ft_move(data, (data->sel->pos[1] = ((int)data->term->width - 1)), (data->sel->pos[0] -= 1));
	if (state)
		motion_list(data, 'L');
	return ;
}

void ft_move_right(t_data *data, int state)
{
	int len;

	len = ((int)data->sel->len_prompt + (int)data->entry->len_line);
	if (data->sel->pos[0] == (data->sel->pos_start[0] + (len/data->term->width)) && (len > data->term->width))
	{
		if (data->sel->pos[1] < (len%(int)data->term->width))
			tputs(tgoto(tgetstr("nd", NULL), 0, 0), 1, ft_putchar_select);
	}
	else if ((data->sel->pos[1] == (data->term->width - 1)) && (len > data->term->width))
		ft_move(data, (data->sel->pos[1] = 0), (data->sel->pos[0] += 1));
	else if (data->sel->pos[1] < len)
		tputs(tgoto(tgetstr("nd", NULL), 0, 0), 1, ft_putchar_select);
	if (state)
		motion_list(data, 'R');
	return ;
}