/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:41:40 by RAZOR             #+#    #+#             */
/*   Updated: 2017/01/22 17:54:49 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_move_left(t_data *data)
{
	t_select *sel;

	sel = NULL;
	sel = data->sel;
	if (sel->pos[1] > (int)sel->len_prompt && sel->pos[0] == sel->pos_start[0])
		data->sel->pos[1] -= 1;
	else if (sel->pos[0] != sel->pos_start[0] && sel->pos[1] > 0)
		data->sel->pos[1] -= 1;
	else if (sel->pos[1] == 0)
	{
		data->sel->pos[1] = (data->sel->width - 1);
		data->sel->pos[0] -= 1;
	}
	else
		return ;
}

void ft_move_right(t_data *data)
{
	t_select *sel;
	int ret;
	int len;

	sel = NULL;
	sel = data->sel;
	ret = ((data->entry->len_line + data->sel->len_prompt)/data->sel->width);
	len = ((int)sel->len_prompt + (int)data->entry->len_line);
	if (len > sel->width)
	{
		if (sel->pos[0] == (sel->pos_start[0] + ret))
		{
			if (sel->pos[1] < (((int)sel->len_prompt + (int)data->entry->len_line)%(int)sel->width))
				data->sel->pos[1] += 1;
			else
				return;
		}
		else
			data->sel->pos[1] += 1;
		if (sel->pos[1] == data->sel->width)
		{
			data->sel->pos[1] = 0;
			data->sel->pos[0] += 1;
		}
	}
	if (len < sel->width)
	{
		if (sel->pos[1] < (int)sel->len_prompt + (int)data->entry->len_line)
			data->sel->pos[1] += 1;
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
	{
		data->sel->pos[1] = data->sel->pos_start[1];
		data->sel->pos[0] = data->sel->pos_start[0];
	}
	if (sel->pos[0] == sel->pos_start[0])
		data->sel->pos[1] = data->sel->pos_start[1];
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
	return;
}
