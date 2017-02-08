/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/02/07 13:55:31 by RAZOR            ###   ########.fr       */
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
		if (data->sel->pos[1] > (data->sel->width))
			ft_putchar_fd('\n', data->sel->tty);
		ft_putstr_fd((char *)tmp->content, data->sel->tty);
		tmp = tmp->next;
	}
}

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
		multipy = data->sel->pos[0] - data->sel->pos_start[0];
		data->sel->pos_search = (data->entry->len_line) - (data->sel->pos[1]*multipy);
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
	if (data->sel->pos[1] < (len - 1))
	{
		// tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		// while (data->entry->cut_line)
		// {
		// 	ft_move_cursor(data, RIGHT);
		// 	del_one_character(data, DEL);
		// 	data->entry->cut_line = data->entry->cut_line->next;

		// }
		// print_lst_line(data, data->entry->cut_line);
		// tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	}
	if (data->sel->pos[0] == (data->sel->height - 1))
		data->sel->pos_start[0] = data->sel->pos[0] - ((int)data->entry->len_line + (int)data->sel->len_prompt)/(data->sel->width);
}