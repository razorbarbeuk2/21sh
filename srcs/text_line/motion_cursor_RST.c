/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_RST.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:19:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/23 17:25:32 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	free_data_entry(t_data *data)
{
	if (data->entry)
	{
		if (data->entry->line)
			ft_lstdel(&data->entry->line, &ft_free_node);
		if (data->entry->cpy)
			ft_lstdel(&data->entry->cpy, &ft_free_node);
		if (data->entry->cut_line)
			ft_lstdel(&data->entry->cut_line, &ft_free_node);
		ft_strdel(&data->entry->line_str);
		ft_free_char(data->entry->line_str_double);
		data->entry->line_str = NULL;
		data->entry->line_str_double = NULL;
	}
	data->entry = init_data_entry();
	return ;
}

void	reset_line(t_data *data)
{
	ft_move_home(data);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
	if (data->entry->line)
	{
		free_data_entry(data);
		get_pos_prompt(data);
		print_lst_line(data, data->entry->line);
	}
	return ;
}