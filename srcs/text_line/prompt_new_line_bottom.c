/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/14 11:16:55 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_pos_new_line(t_data *data)
{
	if (data->sel->pos[1] == (data->sel->width - 1) && data->sel->pos[0] == (data->sel->height - 1))
	{
		//ft_putstr_fd("FUCK", data->sel->tty);
		data->sel->pos_start[0] = (data->sel->pos_start[0] - 1);
	}
}