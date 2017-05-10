/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_insert_caract.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/10 15:05:51 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		print_character(t_data *data, char result)
{
	ft_add_print_caract(data, result);
	ft_putchar_fd(result, data->sel->tty);
	motion_list(data, 'R');
	if (data->sel->pos[1] == (data->sel->width - 1))
	{
		if (data->sel->_bottom)
			data->sel->pos_start[0]--;
		ft_putchar_fd('\n', data->sel->tty);
	}
	if (data->sel->i_lst < (int)data->entry->len_line && data->sel->i_lst > 1)
	{
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		print_lst_line(data, data->entry->cut_line);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	}
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
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		ft_putnbr_fd(data->sel->i_lst, data->sel->tty);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
		// ft_putnbr_fd(data->sel->width, data->sel->tty);
		// ft_putchar_fd(';', data->sel->tty);
		
		// ft_putchar_fd(';', data->sel->tty);
		// ft_putnbr_fd((int)data->entry->len_line, data->sel->tty);
		
		//print_lst_line_tools(data, data->entry->line);
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

static void		del_print_middle_sentence(t_data *data)
{
	int i_lst;

	i_lst = 0;
	i_lst = data->sel->i_lst;
	tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
	ft_move_end(data);
	get_pos_prompt(data);
	if (data->sel->pos[1] != (data->sel->width - 1))
		tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
	else
	{
		tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
		ft_move(data, data->sel->pos[1]--, data->sel->pos[0]);
	}
	tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	print_lst_line(data, data->entry->cut_line);
	data->sel->i_lst = i_lst;
}

void		del_one_character(t_data *data, char result)
{
	int i_lst;
	int i_;

	i_lst = 0;
	i_ = 0;
	(void)result;
	if ((int)data->entry->len_line && data->sel->i_lst)
	{
		if (data->sel->i_lst == (int)data->entry->len_line)
		{
			if ((data->sel->pos[1]) == 0 && !i_)
			{
				ft_move(data, (data->sel->pos[1] = ((int)data->sel->width - 1)), (data->sel->pos[0] -= 1));
				i_ = 1;
			}
			ft_move_cursor(data, LEFT);
			tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
			if ((data->sel->pos[1]) == (data->sel->width - 1) && i_)
			{
				ft_move(data, data->sel->pos[1] = ((int)data->sel->width - 1), data->sel->pos[0]);
				i_ = 0;
			}
			ft_del_print_caract(data, result);
			data->entry->len_line--;
			return ;
			
		}
		else if (data->sel->i_lst > 0 && data->sel->i_lst < (int)data->entry->len_line)
		{
			ft_del_print_caract(data, result);
			data->entry->len_line--;
			ft_move_cursor(data, LEFT);
			tputs(tgetstr("dc", NULL), 1, ft_putchar_select);
			del_print_middle_sentence(data);
			return ;
		}
		return ;
	}
	return ;
}