/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/23 22:03:23 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_list 	*ft_move_at_list(t_data *data, t_list **lst, int pos)
{
	t_list	*tmp_lst;
	int 	count;

	tmp_lst = NULL;
	tmp_lst = (*lst);
	(void)data;
	count = pos;
	while (count-- && tmp_lst)
		tmp_lst = tmp_lst->next;
	return (tmp_lst);
}

void		print_lst_line(t_data *data, t_list *lst)
{
	tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
	if (data->sel->pos[1] == (data->sel->width - 1))
		ft_move_cursor(data, LEFT);
	while(lst)
	{
		ft_putstr_fd((char *)lst->content, data->sel->tty);
		lst = lst->next;
	}
	tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
}