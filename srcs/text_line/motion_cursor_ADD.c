/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_ADD.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:59:10 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/29 14:57:24 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		print_character(t_data *data, char result)
{
	ft_add_print_caract(data, result);
	ft_putchar_fd(result, data->term->tty);
	motion_list(data, 'R');
	if (data->sel->pos[1] == (data->term->width - 1))
	{
		if (data->sel->_bottom)
			data->sel->pos_start[0]--;
		ft_putchar_fd('\n', data->term->tty);
	}
	if (data->sel->i_lst < (int)data->entry->len_line && data->sel->i_lst > 1)
	{
		tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
		print_lst_line(data, data->entry->cut_line);
	}
	return ;
}