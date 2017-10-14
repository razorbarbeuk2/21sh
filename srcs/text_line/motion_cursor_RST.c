/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_RST.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:19:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 15:04:42 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void 	reset_line_cpy(t_data *data)
{
	if (data->entry->cpy)
		ft_lstdel(&data->entry->cpy, &ft_free_node);
	return ;
}

void	reset_line(t_data *data)
{
	ft_move_home(data);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
	if (data->entry->line)
		print_lst_line(data, data->entry->line);
	return ;
}