/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_insert_caract.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/01/10 14:36:05 by RAZOR            ###   ########.fr       */
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
		ft_putstr_fd((char *)tmp->content, data->sel->tty);
		tmp = tmp->next;
	}
}

void		print_character(t_data *data, char result)
{
	tputs(tgetstr("im", NULL), 1, ft_putchar_select);
	ft_putchar_fd(result, data->sel->tty);
	ft_add_print_caract(data, result);
	ft_pos_new_line(data);
	tputs(tgetstr("ic", NULL), 1, ft_putchar_select);
	tputs(tgetstr("ip", NULL), 1, ft_putchar_select);
	tputs(tgetstr("ei", NULL), 1, ft_putchar_select);
}

void		exec_cmd_character(t_data *data, char result)
{
	(void)result;
	if (data->sel)
	{
		//ft_putnbr_fd(ft_strlen(data->cmd), data->sel->tty);
		// ft_putnbr_fd(data->pos_test, data->sel->tty);
		//print_lst_line(data, data->entry->line);
		ft_putnbr_fd(data->sel->pos[0], data->sel->tty);
		ft_putchar_fd(';', data->sel->tty);
		ft_putnbr_fd(data->sel->pos_start[0], data->sel->tty);
		ft_putchar_fd(';', data->sel->tty);
		ft_putnbr_fd(((data->sel->pos_start[0] + (data->entry->len_line + data->sel->len_prompt)/data->sel->width)), data->sel->tty);
		// ft_putnbr_fd(data->sel->width, data->sel->tty);
		// ft_putchar_fd(';', data->sel->tty);
		
		// ft_putstr_fd(data->cmd, data->sel->tty);
		// ft_putstr_fd(data->test, data->sel->tty);
	}
	else
		ft_putstr_fd("FUCK", data->sel->tty);
}

void		del_one_character(t_data *data, char result)
{
	(void)result;
	ft_move_cursor(data, LEFT);
	tputs(tgetstr("dm", NULL), 1, ft_putchar_select);
	tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
	tputs(tgetstr("ed", NULL), 1, ft_putchar_select);
	ft_del_print_caract(data, result);
}