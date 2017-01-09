/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:41:40 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/13 17:11:47 by RAZOR            ###   ########.fr       */
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

	sel = NULL;
	sel = data->sel;
	ret = ((data->entry->len_line + data->sel->len_prompt)/data->sel->width);
	if (((int)sel->len_prompt + (int)data->entry->len_line) > sel->width)
	{
		if (sel->pos[1] < (((int)sel->len_prompt + (int)data->entry->len_line)%(int)sel->width) && sel->pos[0] != sel->pos_start[0])
			data->sel->pos[1] += 1;
		if (sel->pos[1] < (int)sel->width && (sel->pos[0] == sel->pos_start[0]))
			data->sel->pos[1] += 1;
		if (sel->pos[1] == (data->sel->width - 1))
		{
			data->sel->pos[1] = 0;
			data->sel->pos[0] += 1;
		}
	}
	if (((int)sel->len_prompt + (int)data->entry->len_line) < sel->width)
	{
		if (sel->pos[1] < (int)sel->len_prompt + (int)data->entry->len_line)
			data->sel->pos[1] += 1;
	}
	else
		return ;
}