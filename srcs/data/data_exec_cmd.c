/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/11 16:22:08 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		exec_cmd_character(t_data *data, char result)
{
	
	(void)result;
	if (data->sel)
	{
		//ft_putnbr_fd(ft_strlen(data->cmd), data->sel->tty);
		// ft_putnbr_fd(data->pos_test, data->sel->tty);
		
		// ft_putnbr_fd(data->sel->pos_search, data->sel->tty);
		// ft_putchar_fd(';', data->sel->tty);
		//****************
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		// ft_putnbr_fd(data->sel->i_lst, data->sel->tty);
		//ft_putstr_fd(data->entry->cpy, data->sel->tty);
		//print_lst_line_tools(data, data->entry->cpy);
		ft_putnbr_fd(ft_lst_count(data->entry->line), data->sel->tty);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
		// ft_putnbr_fd(data->sel->width, data->sel->tty);
		// ft_putchar_fd(';', data->sel->tty);
		
		// ft_putchar_fd(';', data->sel->tty);
		// ft_putnbr_fd((int)data->entry->len_line, data->sel->tty);
		
		
		// ft_putnbr_fd(data->sel->i_lst - 1, data->sel->tty);
		// ft_putnbr_fd(data->entry->len_line, data->sel->tty);
		//****************
		// ft_putnbr_fd(data->sel->pos[0], data->sel->tty);
		// ft_putchar_fd(' ', data->sel->tty);
		// ft_putnbr_fd(data->sel->pos[1], data->sel->tty);
		// ft_putchar_fd(';', data->sel->tty);
		// ft_putnbr_fd(data->sel->pos_start[0], data->sel->tty);
		// ft_putchar_fd(' ', data->sel->tty);
		// ft_putnbr_fd(data->sel->pos_start[1], data->sel->tty);
		//****************
		// ft_putchar_fd(';', data->sel->tty);
		// ft_putnbr_fd(((data->sel->pos_start[0] + (data->entry->len_line + data->sel->len_prompt)/data->sel->width)), data->sel->tty);
		// ft_putnbr_fd(data->sel->width, data->sel->tty);
		// ft_putchar_fd(';', data->sel->tty);
		
		// ft_putstr_fd(data->cmd, data->sel->tty);
		// ft_putstr_fd(data->test, data->sel->tty);
	}
	else
		ft_putstr_fd("FUCK", data->sel->tty);
}