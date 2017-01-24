/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/01/22 22:59:03 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_list	*ft_find_pos_int_lst(t_data *data)
{
	int count;
	int multipy;
	t_list *tmp;

	count = -1;
	tmp = NULL;
	tmp = data->entry->line;
	data->sel->pos_search = 0;
	if (data->sel->pos[0] == data->sel->pos_start[0])
		data->sel->pos_search = (data->sel->pos[1] - data->sel->len_prompt);
	else
	{
		multipy = 0;
		multipy = (data->entry->len_line - data->sel->len_prompt);
		data->sel->pos_search = (data->entry->len_line - data->sel->len_prompt) - (data->sel->pos[1]);
	}
	while(tmp->next && ++count <= data->sel->pos_search)
		tmp = tmp->next;
	return (tmp);
}

void	ft_pos_new_line(t_data *data)
{
	int len;
	int count;
	t_list *tmp;
	t_list *tmp_;

	count = 0;
	tmp = NULL;
	tmp_ = NULL;
	len = (int)data->sel->len_prompt + (int)data->entry->len_line;
	if (data->sel->pos[1] < len)
	{
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		tmp = ft_find_pos_int_lst(data);
		tmp_ = tmp;
		ft_move_cursor(data, RIGHT);
		while (tmp)
		{
			ft_move_cursor(data, RIGHT);
			del_one_character(data, DEL);
			tmp = tmp->next;
		}
		print_lst_line(data, tmp_);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
		// if (len > (data->sel->width - 1) && pos < len)
		// {
		// 	tmp = data->entry->line;
		// 	//ft_putnbr_fd(data->entry->len_line/data->sel->width, data->sel->tty);
		// 	//print_lst_line(data, tmp);
		// 	tmp = NULL;
		// }
	}
	if (data->sel->pos[1] == (data->sel->width - 1))
	{
		ft_putchar_fd('\n', data->sel->tty);
		tputs(tgetstr("al", NULL), 1, ft_putchar_select);
	}
	if (data->sel->pos[1] == (data->sel->width) && data->sel->pos[0] == (data->sel->height - 1))
	{
		ft_putchar_fd('\n', data->sel->tty);
		tputs(tgetstr("al", NULL), 1, ft_putchar_select);
		data->sel->pos_start[0] -= 1;
	}
}