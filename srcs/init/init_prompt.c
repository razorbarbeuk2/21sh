/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:41:09 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/19 18:36:23 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int 	init_pos(t_data *data)
{
	get_super_prompt(data, NULL);
	if (!(data->sel->pos = ft_memalloc(2*sizeof(int))))
		return (-1);
	if (!(data->sel->pos_start = ft_memalloc(2*sizeof(int))))
		return (-1);
	if (!(data->sel->pos_tmp = ft_memalloc(2*sizeof(int))))
		return (-1);
	get_pos_prompt(data);
	data->sel->pos_start[0] = data->sel->pos[0];
	data->sel->pos_start[1] = data->sel->pos[1];
	if (data->sel->pos_start[0] == (data->sel->height - 1))
		data->sel->_bottom = 1;
	return (1);
}