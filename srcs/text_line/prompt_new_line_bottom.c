/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/18 13:32:40 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		print_lst_line(t_data *data, t_list *lst)
{
	t_list *tmp;

	tmp = NULL;
	tmp = lst;
	if (tmp == NULL)
		ft_putstr_fd("FUCK", data->sel->tty);
	while(tmp)
	{
		// if (data->sel->pos[1] > (data->sel->width))
		// 	ft_putchar_fd('\n', data->sel->tty);
		ft_putstr_fd((char *)tmp->content, data->sel->tty);
		tmp = tmp->next;
	}
}

void	ft_pos_new_line(t_data *data)
{
	
}