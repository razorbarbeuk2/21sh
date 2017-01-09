/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/15 17:20:38 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_pos_new_line_bottom_page(t_data *data, int opt)
{
	if (data->sel->pos[0] == data->sel->pos_start[0])
	{
		data->entry->size_line++;
		if ((int)data->entry->size_line >= (data->sel->width))
		{
			data->sel->pos[1] = 0;
			data->sel->pos[0] = (data->sel->pos_start[0] + 1);
			if (opt)
				data->sel->pos_start[0] -= 1;
			data->entry->size_line = 0;
			data->entry->nb_line++;
		}
	}
	else if (data->sel->pos[0] > data->sel->pos_start[0])
	{
		data->entry->size_line++;
		if ((int)data->entry->size_line > (data->sel->width))
		{
			data->sel->pos[1] = 0;
			data->sel->pos[0] = (data->sel->pos_start[0] + 1);
			if (opt)
				data->sel->pos_start[0] -= 1;
			data->entry->size_line = 0;
			data->entry->nb_line++;
		}
	}
}


void	ft_pos_new_line(t_data *data)
{
	if (data->sel->pos_start[0] == (data->sel->height - 1))
		ft_pos_new_line_bottom_page(data, 1);
	else
		ft_pos_new_line_bottom_page(data, 0);
}