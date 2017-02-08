/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:41:40 by RAZOR             #+#    #+#             */
/*   Updated: 2017/01/24 16:34:06 by RAZOR            ###   ########.fr       */
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
	if (sel->pos[1] > (int)sel->len_prompt && sel->pos[0] == sel->pos_start[0])
		tputs(tgoto((tgetstr("LE", NULL)), 0, 0), 0, ft_putchar_select);
	else if (sel->pos[0] != sel->pos_start[0] && sel->pos[1] > 0)
		tputs(tgoto((tgetstr("LE", NULL)), 0, 0), 0, ft_putchar_select);
	else if (sel->pos[1] == 0)
		ft_move(data, (data->sel->width - 1), (data->sel->pos[0] -= 1));
	else
		return ;
}

void ft_move_right(t_data *data)
{
	if (((int)data->sel->len_prompt + (int)data->entry->len_line) > data->sel->width)
	{
		if (data->sel->pos[0] == data->sel->pos_start[0] + ((int)(data->entry->len_line + data->sel->len_prompt)/data->sel->width))
		{
			if (data->sel->pos[1] < (((int)data->sel->len_prompt + (int)data->entry->len_line)%(int)data->sel->width))
				tputs(tgoto(tgetstr("RI", NULL), 0, 0), 1, ft_putchar_select);
			else
				return;
		}
		else
			tputs(tgoto(tgetstr("RI", NULL), 0, 0), 1, ft_putchar_select);
		if (data->sel->pos[1] == (data->sel->width - 1))
			ft_move(data, (data->sel->pos[1] = 0), (data->sel->pos[0] += 1));
	}
	if (((int)data->sel->len_prompt + (int)data->entry->len_line) < data->sel->width)
	{
		if (data->sel->pos[1] < (int)data->sel->len_prompt + (int)data->entry->len_line)
			tputs(tgoto(tgetstr("RI", NULL), 0, 0), 1, ft_putchar_select);
	}
	else
		return ;
}

void ft_move_home(t_data *data)
{
	t_select *sel;

	sel = NULL;
	sel = data->sel;
	if (sel->pos[1] != (sel->pos_start[1] + (int)sel->len_prompt) && sel->pos[0] != sel->pos_start[0])
		ft_move(data, data->sel->pos_start[1], data->sel->pos_start[0]);
	if (sel->pos[0] == sel->pos_start[0])
		ft_move(data, data->sel->pos_start[1], data->sel->pos[0]);
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
}
