/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/19 16:54:01 by gbourson         ###   ########.fr       */
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
	ft_putnbr_fd(data->sel->i_lst, data->sel->tty);
}