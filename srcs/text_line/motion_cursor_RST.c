/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_RST.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:19:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/27 18:05:51 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	reset_line(t_data *data)
{
	ft_move_home(data);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
	if (data->entry->line)
	{
		get_pos_prompt(data);
		print_lst_line(data, data->entry->line);
		// data->entry = free_data_entry(data->entry);
		// data->line = free_data_entry(data->line);
	}
	return ;
}