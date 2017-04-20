/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:41:40 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/20 14:57:40 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_move(t_data *data, int x, int y)
{
	if (data)
		tputs(tgoto((tgetstr("cm", NULL)), x, y), 0, ft_putchar_select);
}

void ft_move_left(t_data *data)
{ 
	t_select *sel;

	sel = NULL;
	sel = data->sel;
	if ((sel->pos[1] > (int)sel->len_prompt && sel->pos[0] == sel->pos_start[0]) || (sel->pos[0] != sel->pos_start[0] && sel->pos[1] > 0) || (sel->pos[1] == 0))
	{
		tputs(tgoto((tgetstr("LE", NULL)), 0, 0), 0, ft_putchar_select);
		motion_list(data, 'L');
	}
	return ;
}

void ft_move_right(t_data *data)
{
	int len;

	len = (int)data->sel->len_prompt + (int)data->entry->len_line;
	if (data->sel->pos[0] == (data->sel->pos_start[0] + (len/data->sel->width)) && (len > data->sel->width))
	{
		if (data->sel->pos[1] < (len%(int)data->sel->width))
		{
			tputs(tgoto(tgetstr("RI", NULL), 0, 0), 1, ft_putchar_select);
			motion_list(data, 'R');
		}
		return;
	}
	if ((data->sel->pos[1] == (data->sel->width - 1)) && (len > data->sel->width))
	{
		ft_move(data, (data->sel->pos[1] = 0), (data->sel->pos[0] += 1));
		motion_list(data, 'R');
		return;
	}
	if ((data->sel->pos[1] < len))
	{
		tputs(tgoto(tgetstr("RI", NULL), 0, 0), 1, ft_putchar_select);
		motion_list(data, 'R');
		return;
	}
}

void ft_move_home(t_data *data)
{
	t_select *sel;

	sel = NULL;
	sel = data->sel;
	if ((sel->pos[1] != (sel->pos_start[1] + (int)sel->len_prompt) && sel->pos[0] != sel->pos_start[0]) || (sel->pos[0] == sel->pos_start[0]))
	{
		ft_move(data, data->sel->pos_start[1], data->sel->pos_start[0]);
		motion_list(data, 'H');
	}
	return;
}

void ft_move_end(t_data *data)
{
	t_select *sel;
	int ret;

	sel = NULL;
	sel = data->sel;
	ret = ((data->entry->len_line + data->sel->len_prompt)/data->sel->width);
	if (ret > 0)
	{
		data->sel->pos[1] = ((int)sel->len_prompt + (int)data->entry->len_line)%(int)sel->width;
		data->sel->pos[0] = data->sel->pos_start[0] + ret;
	}
	if (ret == 0)
		data->sel->pos[1] = (int)sel->len_prompt + (int)data->entry->len_line;
	ft_move(data, data->sel->pos[1], data->sel->pos[0]);
	motion_list(data, 'E');
}
