/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:41:40 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/15 17:10:10 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_move_left(t_data *data)
{
	if (data->sel->pos[1] > (int)data->sel->len_prompt && data->sel->pos[0] == data->sel->pos_start[0])
		data->sel->pos[1] -= 1;
	if (data->sel->pos[0] != data->sel->pos_start[0] && data->sel->pos[1] > 0)
		data->sel->pos[1] -= 1;
	if (data->sel->pos[1] == 0)
	{
		data->sel->pos[1] = (data->sel->width - 1);
		data->sel->pos[0] -= 1;
	}
	else
		return ;
}

void ft_move_right(t_data *data)
{
	int size;

	size = ((int)data->entry->len_line + (int)data->sel->len_prompt);
	if ((data->sel->pos[0] - data->sel->pos_start[0]) != data->entry->nb_line)
		data->sel->pos[1] += 1;
	if (data->sel->pos[1] < (int)data->entry->size_line && (data->sel->pos[0] - data->sel->pos_start[0]) == data->entry->nb_line)
		data->sel->pos[1] += 1;
	if (data->sel->pos[1] == data->sel->width)
	{
		data->sel->pos[1] = 0;
		data->sel->pos[0] += 1;
	}
	else
		return ;
}