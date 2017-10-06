/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:19:36 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/06 21:38:05 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	motion_list(t_data *data, char opt)
{
	if (data->sel->i_lst > 0 && opt == 'L')
		data->sel->i_lst--;
	if ((data->sel->i_lst < (int)data->entry->len_line) && opt == 'R')
		data->sel->i_lst++;
	if (data->sel->i_lst && opt == 'H')
		data->sel->i_lst = 0;
	if ((data->sel->i_lst < (int)data->entry->len_line) && opt == 'E')
		data->sel->i_lst = (int)data->entry->len_line;
	if (opt == 'U')
	{
		if ((data->sel->i_lst - (int)data->term->width) > 0)
			data->sel->i_lst -= ((int)data->term->width);
		else
			data->sel->i_lst = 0;
	}
	if (opt == 'D')
	{
		if ((int)data->entry->len_line >= (data->sel->i_lst + (int)data->term->width))
			data->sel->i_lst += (int)data->term->width;
		else
			data->sel->i_lst = (int)data->entry->len_line;
	}
	return;
}

t_list 	*ft_move_at_list(t_data *data, t_list **lst, int pos)
{
	t_list	*tmp_lst;
	int 	count;

	(void)data;
	count = 0;
	tmp_lst = (*lst);
	while (count != pos && tmp_lst)
	{
		tmp_lst = tmp_lst->next;
		count++;
	}
	return (tmp_lst);
}

int 	ft_move_at_line(t_data *data, t_list **lst, t_list *tmp)
{
	t_list	*tmp_lst;
	int 	count;

	(void)data;
	count = 0;
	tmp_lst = (*lst);
	while (tmp && tmp != tmp_lst)
	{
		tmp_lst = tmp_lst->next;
		count++;
	}
	return (count);
}