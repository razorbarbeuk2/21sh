/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_HE.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:16:52 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/05 18:06:48 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

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
	ret = ((data->entry->len_line + data->sel->len_prompt)/data->term->width);
	if (ret > 0)
	{
		data->sel->pos[1] = ((int)sel->len_prompt + (int)data->entry->len_line)%(int)data->term->width;
		data->sel->pos[0] = data->sel->pos_start[0] + ret;
	}
	if (ret == 0)
		data->sel->pos[1] = (int)sel->len_prompt + (int)data->entry->len_line;
	if (data->sel->pos[1] != (data->term->width - 1))
		ft_move(data, data->sel->pos[1], data->sel->pos[0]);
	else
		ft_move(data, (data->sel->pos[1] = (data->term->width - 1)), data->sel->pos[0]);
	motion_list(data, 'E');
	return ;
}