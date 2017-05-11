/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/11 14:50:12 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		print_lst_line(t_data *data, t_list *lst)
{
	t_list *list;

	list = NULL;
	list = lst;
	tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
	if (data->sel->pos[1] == (data->sel->width - 1))
		ft_move_cursor(data, LEFT);
	while(list)
	{
		ft_putstr_fd((char *)list->content, data->sel->tty);
		list = list->next;
	}
	tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	list = NULL;
}

void		print_lst_line_tools(t_data *data, t_list *lst)
{
	t_list *list;

	list = NULL;
	list = lst;
	if (!lst)
		ft_putstr_fd("FUCK", data->sel->tty);	
	while(list)
	{
		ft_putstr_fd((char *)list->content, data->sel->tty);
		list = list->next;
	}
	return ;
}