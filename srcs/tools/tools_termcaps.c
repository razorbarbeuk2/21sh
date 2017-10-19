/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:44:29 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/19 11:40:42 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_data *restor_data(t_data *data, int flag)
{
	static t_data *data_static;
	if (flag == SEND)
		data_static = data;
	return (data_static);
}

int	ft_putchar_select(int c)
{
	t_data *data;

	data = restor_data(NULL, 0);
	return (write(data->term->tty, &c, 1));
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
		ft_putnbr_fd(data->sel->pos[i], STDOUT_FILENO);
		if (data->sel->pos[i + 1])
			ft_putchar_fd(';', STDOUT_FILENO);
		i++;
	}
}
