/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_insert_caract.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/26 18:01:33 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		print_character(t_data *data, char result)
{
	
	ft_add_print_caract(data, result);
	ft_putchar_fd(result, data->sel->tty);
	motion_list(data, 'R');
	if ((data->sel->pos[1]) == (data->sel->width - 1))
		ft_move(data, (data->sel->pos[1] = 0), (data->sel->pos[0] += 1));
	if (data->sel->i_lst < (int)data->entry->len_line)
		print_lst_line(data, data->entry->cut_line);
}

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
		//print_lst_line(data, data->entry->line);
		ft_putnbr_fd(data->sel->i_lst, data->sel->tty);
		ft_putnbr_fd((int)data->entry->len_line, data->sel->tty);
		// ft_putnbr_fd(data->sel->i_lst - 1, data->sel->tty);
		// ft_putnbr_fd(data->entry->len_line, data->sel->tty);
		//****************
		// ft_putnbr_fd(data->sel->pos[0], data->sel->tty);
		// ft_putchar_fd(' ', data->sel->tty);
		// ft_putnbr_fd(data->sel->pos[1], data->sel->tty);
		//ft_putchar_fd(';', data->sel->tty);
		//ft_putnbr_fd(data->sel->pos_start[0], data->sel->tty);
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

void		del_one_character(t_data *data, char result)
{
	int i_lst;

	i_lst = 0;	
	(void)result;
	ft_del_print_caract(data, result);
	if (data->sel->i_lst != 0)
		ft_move_cursor(data, LEFT);
	if ((data->sel->i_lst != 0) && (data->sel->pos[1] == 0) && (data->sel->pos[0] != data->sel->pos_start[0]))
		tputs(tgetstr("dl", NULL), 1, ft_putchar_select);
	tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
	if (data->sel->i_lst < (int)data->entry->len_line)
	{
		i_lst = data->sel->i_lst;
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		ft_move_end(data);
		ft_move_cursor(data, LEFT);
		tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
		data->sel->i_lst = i_lst;
	}
	if (data->sel->i_lst < (int)data->entry->len_line)
		print_lst_line(data, data->entry->cut_line);
	return ;
	
	
	// if (data->sel->pos[1] == 0)
	// {
	// 	ft_move_cursor(data, LEFT);
	// 	tputs(tgoto((tgetstr("dc", NULL)), 0, 0), 0, ft_putchar_select);
	// }
	//tputs(tgetstr("dm", NULL), 1, ft_putchar_select);
	
	//tputs(tgetstr("ed", NULL), 1, ft_putchar_select);
	
	//motion_list(data, 'L');
	//print_lst_line(data, data->entry->cut_line);
}