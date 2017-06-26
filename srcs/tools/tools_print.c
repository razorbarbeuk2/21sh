/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/26 11:48:00 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_print_tab(t_data *data, char **str_tab)
{
	int i;

	i = 0;
	while(str_tab[i])
	{
		ft_putstr_fd(str_tab[i], data->sel->tty);
		i++;
	}
}

void 		count_list_cmd(t_data *data, t_list *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	ft_putnbr_fd(count, data->sel->tty);
	return ;
}

void		print_list_node_cmd(t_data *data, t_list *lst)
{
	t_cmd *cmd_lst;

	cmd_lst = NULL;
	cmd_lst = (t_cmd *)lst->content;
	if (!cmd_lst)
		ft_putstr_fd("FUCK", data->sel->tty);
	if (cmd_lst->cmd)
	{
		ft_putstr_fd("cmd :", data->sel->tty);
		ft_putstr_fd(cmd_lst->cmd, data->sel->tty);
		write(1, "\n", 1);
	}
	if (cmd_lst->opt)
	{
		ft_putstr_fd("opt :", data->sel->tty);
		ft_putstr_fd(cmd_lst->opt, data->sel->tty);
		write(1, "\n", 1);
	}
	if (cmd_lst->file)
	{
		ft_putstr_fd("file :", data->sel->tty);
		ft_putstr_fd(cmd_lst->file, data->sel->tty);
		write(1, "\n", 1);
	}
}

void		print_list_node_sep(t_data *data, t_list *lst)
{
	t_sep *sep;

	sep = NULL;
	sep = (t_sep *)lst->content;
	if (!sep->separate)
		ft_putstr_fd("FUCK", data->sel->tty);
	if (sep->separate)
	{
		ft_putstr_fd("sep :", data->sel->tty);
		ft_putstr_fd(sep->separate, data->sel->tty);
		write(1, "\n", 1);
	}
}

void		print_list_cmd(t_data *data, t_list *lst)
{
	while (lst)
	{
		if (lst->type == TYPE_CMD)
		{
			ft_putstr_fd("TYPE_CMD : ", data->sel->tty);
			ft_putnbr_fd(TYPE_CMD, data->sel->tty);
			write(1, "\n", 1);
			print_list_node_cmd(data, lst);
		}
		if (lst->type == TYPE_SEP)
		{
			ft_putstr_fd("TYPE_SEP : ", data->sel->tty);
			ft_putnbr_fd(TYPE_SEP, data->sel->tty);
			write(1, "\n", 1);
			print_list_node_sep(data, lst);
		}
		lst = lst->next;
	}
}

void		print_lst_line(t_data *data, t_list *lst)
{
	t_list		*list;

	list = NULL;
	list = lst;
	if (lst)
	{
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
	return ;
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