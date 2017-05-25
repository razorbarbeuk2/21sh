/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/25 18:18:02 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		print_list_cmd(t_data *data, t_list *lst)
{
	t_cmd *cmd_lst;

	cmd_lst = NULL;
	while (lst)
	{
		cmd_lst = (t_cmd *)lst->content;
		//ft_putstr_fd("CMD :", data->sel->tty);
		if (!cmd_lst)
			ft_putstr_fd("FUCK", data->sel->tty);
		else if (cmd_lst->cmd)
		{
			ft_putstr_fd("cmd :", data->sel->tty);
			ft_putstr_fd(cmd_lst->cmd, data->sel->tty);
		}
		else if (cmd_lst->opt)
		{
			ft_putstr_fd("opt :", data->sel->tty);
			ft_putstr_fd(cmd_lst->opt, data->sel->tty);
		}
		else if (cmd_lst->file)
		{
			ft_putstr_fd("file :", data->sel->tty);
			ft_putstr_fd(cmd_lst->file, data->sel->tty);
		}
		write(1, " ", 1);
		lst = lst->next;
		cmd_lst = NULL;
	}
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