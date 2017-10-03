/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_ADD.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:59:10 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/03 19:13:00 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void print_character_next(t_data *data)
{
	if (data->sel->pos[0] == (data->term->height - 1))
	{
		data->sel->pos_start[0]--;
		tputs(tgetstr("do", NULL), 1, ft_putchar_select);
		tputs(tgetstr("al", NULL), 1, ft_putchar_select);
	}
	ft_move(data, (data->sel->pos[1] = 0), (data->sel->pos[0] += 1));
	return ;
}

void print_character(t_data *data, char result)
{
	int offset;
	int len;

	len = ((int)data->sel->len_prompt + (int)data->entry->len_line);
	data->entry->offset_line = len/(data->term->width - 1);
	data->entry->offset_line += (data->term->height - 1);
	ft_add_print_caract(data, result);
	ft_putchar_fd(result, data->term->tty);
	motion_list(data, 'R');
	if (data->sel->pos[1] == (data->term->width - 1))
		print_character_next(data);
	if (data->sel->i_lst < (int)data->entry->len_line && data->sel->i_lst > 1)
	{
		tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
		offset = ft_lst_count(data->entry->cut_line) + data->sel->pos[1];
		print_lst_line(data, data->entry->cut_line);
		if (data->sel->pos[0] == (data->term->height - 1) && data->entry->offset_line > (data->term->height - 1))
		{
			data->sel->pos_start[0]--;
			ft_move(data, (data->sel->pos[1] += 1), (data->sel->pos[0] -= 1));
		}
	}
	return;
}