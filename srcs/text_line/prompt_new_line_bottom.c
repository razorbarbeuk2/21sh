/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_new_line_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/21 16:04:25 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// t_list 	*ft_move_at_list(t_data *data)
// {
// 	t_list	*tmp_lst;
// 	int		count;

// 	tmp_lst = NULL;
// 	tmp_lst = data->entry->line;
// 	count = data->sel->i_lst;
// 	while (count--)
// 		tmp_lst = tmp_lst->next;
// 	return (tmp_lst);
// }

// void		print_lst_line(t_data *data, t_list *lst)
// {
// 	t_list *tmp;
	
// 	tmp = NULL;
// 	tmp = lst;
// 	tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
// 	while(tmp)
// 	{
// 		ft_move_cursor(data, RIGHT);
// 		del_one_character(data, DEL);
// 		tmp = tmp->next;
// 	}
// 	tmp = lst;
// 	tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
// 	while(tmp)
// 	{
// 		ft_putstr_fd((char *)tmp->content, data->sel->tty);
// 		tmp = tmp->next;
// 	}
// 	tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
// }




void		print_lst_line(t_data *data, t_list *lst)
{
	t_list *tmp;
	
	tmp = NULL;
	tmp = lst;
	while(tmp)
	{
		ft_putstr_fd((char *)tmp->content, data->sel->tty);
		tmp = tmp->next;
	}
}