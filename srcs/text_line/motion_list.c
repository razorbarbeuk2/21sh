/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:19:36 by gbourson          #+#    #+#             */
/*   Updated: 2017/04/19 17:45:59 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	motion_list(t_data *data, char opt)
{
	if (data->sel->i_lst > 0 && opt == 'L')
		data->sel->i_lst--;
	if ((data->sel->i_lst < (int)data->entry->len_line) && opt == 'R')
		data->sel->i_lst++;
	if (data->sel->i_lst && opt == 'H')
		data->sel->i_lst = 1;
	if ((data->sel->i_lst < (int)data->entry->len_line) && opt == 'E')
		data->sel->i_lst = (int)data->entry->len_line;
	return;
}