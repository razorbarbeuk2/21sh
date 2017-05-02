/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_ALT_UD.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:17:52 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/02 17:45:34 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_move_up(t_data *data)
{
	t_select	*sel;
	int			len;

	sel = NULL;
	sel = data->sel;
	len = (int)data->sel->len_prompt + (int)data->entry->len_line;
	if (sel->pos[0] > sel->pos_start[0] && ((data->sel->pos[0] - 1) != sel->pos_start[0]))
		ft_move(data, data->sel->pos[1], (data->sel->pos[0] -= 1));
	else
	{
		if (data->sel->pos[1] < data->sel->pos_start[1])
			ft_move_home(data);
		else
			ft_move(data, data->sel->pos[1], (data->sel->pos[0] -= 1));
	}
	motion_list(data, 'U');
	return ;
}

void ft_move_down(t_data *data)
{
	t_select	*sel;
	int			len;
	int			nb_line_start;

	sel = NULL;
	sel = data->sel;
	nb_line_start = 0;
	len = (int)data->sel->len_prompt + (int)data->entry->len_line;
	nb_line_start = data->sel->pos_start[0] + (len/data->sel->width);
	if ((data->sel->pos[0]) < (nb_line_start) && (len > data->sel->width))
	{
		if ((data->sel->pos[0] + 1) == nb_line_start)
		{
			if (data->sel->pos[1] < (len%(int)data->sel->width))
				ft_move(data, data->sel->pos[1], (data->sel->pos[0] += 1));
			else
				ft_move_end(data);
		}
		else
			ft_move(data, data->sel->pos[1], (data->sel->pos[0] += 1));
		motion_list(data, 'D');
		return ;
	}
}