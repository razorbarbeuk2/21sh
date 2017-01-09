/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/14 13:24:43 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_pos_new_line(t_data *data)
{
	if (data->sel->pos[1] == (data->sel->width - 1) && data->sel->pos[0] == (data->sel->height - 1))
	{
		ft_putchar_fd('\n', data->sel->tty);
		data->sel->pos_start[0] -= 1;
	}
}