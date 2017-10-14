/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:44:29 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/14 11:56:34 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int	ft_putchar_select(int c)
{
	return (write(0, &c, 1));
}

int ft_concat_int(char *buf)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (buf[i])
	{
		result = result*100 + buf[i];
		i++;
	}
	ft_bzero(buf, 8);
	return (result);
}

void		print_pos_cursor(t_data *data)
{
	int i;

	i = 0;
	while(data->sel->pos[i])
	{
		ft_putnbr_fd(data->sel->pos[i], data->term->tty);
		if (data->sel->pos[i + 1])
			ft_putchar_fd(';', data->term->tty);
		i++;
	}
}
