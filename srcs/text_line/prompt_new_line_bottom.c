/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/09 17:13:17 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_list 	*ft_move_at_list(t_data *data, t_list **lst, int pos)
{
	t_list	*tmp_lst;
	int 	count;

	(void)data;
	tmp_lst = NULL;
	tmp_lst = (*lst);
	if (!pos)
		return (tmp_lst);
	count = 1;
	if (pos)
	{
		while (count != pos && tmp_lst)
		{
			tmp_lst = tmp_lst->next;
			count++;
		}
		return (tmp_lst);
	}
	tmp_lst = NULL;
	return (NULL);
}

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

void print_lst_line_tools(t_data *data, t_list *lst)
{
	t_list *list;

	list = NULL;
	list = lst;
	while(list)
	{
		ft_putstr_fd((char *)list->content, data->sel->tty);
		list = list->next;
	}
}