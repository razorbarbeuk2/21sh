/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/01/19 22:15:47 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_list	*ft_find_pos_int_lst(t_data *data)
{
	int count;
	int pos_search;
	int multipy;
	t_list *tmp;

	count = 0;
	tmp = NULL;
	pos_search = 0;
	data->sel->pos_search = 0;
	if (data->sel->pos[0] == data->sel->pos_start[0])
		data->sel->pos_search = data->sel->pos[1];
	else
	{
		multipy = ((data->sel->pos[0] - data->sel->pos_start[0]) + 1)*data->sel->pos_start[1];
		data->sel->pos_search = data->sel->pos_start[1];
	}
	tmp = data->entry->line;
	while(tmp && ++count)
		tmp = tmp->next;
	return (tmp);
}

void	ft_pos_new_line(t_data *data)
{
	int len;
	int pos;
	int count;
	t_list *tmp;

	count = 0;
	tmp = NULL;
	len = (int)data->sel->len_prompt + (int)data->entry->len_line;

	if (data->sel->pos[1] < len)
	{

		pos = data->sel->pos[1];
		ft_find_pos_int_lst(data);
		// if (len > (data->sel->width - 1) && pos < len)
		// {
		// 	tmp = data->entry->line;
			
		// 	//ft_putnbr_fd(data->entry->len_line/data->sel->width, data->sel->tty);
		// 	//print_lst_line(data, tmp);
		// 	tmp = NULL;
		// }
	}
	
	if (data->sel->pos[1] == (data->sel->width - 1) && data->sel->pos[0] == (data->sel->height - 1))
	{
		ft_putchar_fd('\n', data->sel->tty);
		data->sel->pos_start[0] -= 1;
	}
}