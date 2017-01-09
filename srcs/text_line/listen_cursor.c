/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:43:20 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/15 12:21:40 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_move_cursor(t_data *data, int result)
{
	if (result == LEFT)
		ft_move_left(data);
	if (result == RIGHT)
		ft_move_right(data);
	// if (result == DOWN)

	// if (result == UP)
	tputs(tgoto(tgetstr("cm", NULL), data->sel->pos[1], data->sel->pos[0]), 1, ft_putchar_select);
}

void		ft_cmd_cursor(t_data *data, int result)
{
	// ft_putnbr_fd(result, data->sel->tty);
	// ft_putchar_fd(':', data->sel->tty);
	// ft_putnbr_fd(DEL, data->sel->tty);
	// if (result == ESC)
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
	tputs(tgoto(tgetstr("cm", NULL), data->sel->pos[1], data->sel->pos[0]), 1, ft_putchar_select);
	while(read(0, buf, 8))
	{
		result = ft_concat_int(buf);
		ft_cmd_cursor(data, result);
		if (result >= 32 && result <= 126)
			print_character(data, result);
		if (result >= UP && result <= LEFT)
			ft_move_cursor(data, result);
		get_pos_prompt(data);
		ft_bzero(buf, 8);
	}
	return (0);
}
