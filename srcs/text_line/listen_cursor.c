/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:43:20 by RAZOR             #+#    #+#             */
/*   Updated: 2017/04/26 12:32:42 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_check_cursor(t_data *data)
{
	if(data->sel->pos[0] == 0) // A verifier en cas de clear window;
		data->sel->pos[0] = 1;
}

void		ft_move_cursor(t_data *data, int result)
{
	t_select *sel;

	sel = NULL;
	sel = data->sel;
	//ft_check_cursor(data);
	if (result == LEFT)
		ft_move_left(data);
	if (result == RIGHT)
		ft_move_right(data);
	if (result == HOME)
		ft_move_home(data);
	if (result == END)
		ft_move_end(data);
	// if (result == DOWN)

	// if (result == UP)
	//tputs(tgoto(tgetstr("cm", NULL), data->sel->pos[1], data->sel->pos[0]), 1, ft_putchar_select);
}

void		ft_cmd_cursor(t_data *data, int result)
{
	// ft_putnbr_fd(result, data->sel->tty);
	// ft_putchar_fd(':', data->sel->tty);
	// ft_putnbr_fd(DEL, data->sel->tty);
	// if (result == ESC)
	//ft_putstr_fd("FUCK", data->sel->tty);
	if (result == ENTER)
		exec_cmd_character(data, result);
	if (result == DEL)
		del_one_character(data, result);
}

int			listen_cursor(t_data *data)
{
	char	buf[8];
	int		result;

	result = 0;
	ft_bzero(buf, 8);
	get_super_prompt(data, NULL);
	data->sel->pos = ft_memalloc(2);
	data->sel->pos_start = ft_memalloc(2);
	get_pos_prompt(data);
	data->entry->size_line = data->sel->len_prompt;
	data->sel->pos_start[0] = data->sel->pos[0];
	data->sel->pos_start[1] = data->sel->pos[1];
	//tputs(tgoto(tgetstr("cm", NULL), data->sel->pos[1], data->sel->pos[0]), 1, ft_putchar_select);
	while(read(0, buf, 8))
	{
		result = ft_concat_int(buf);
		if (result == DEL || result == ENTER)
			ft_cmd_cursor(data, result);
		if (result == HOME || result == END)
			ft_move_cursor(data, result);
		if ((result >= 32 && result <= 126) && result != HOME && result != END) //Enlever HOME et END dans cette condition Num de touche à changer
			print_character(data, result);
		if (result >= UP && result <= LEFT)
			ft_move_cursor(data, result);
		get_pos_prompt(data);
		ft_bzero(buf, 8);
	}
	return (0);
}
