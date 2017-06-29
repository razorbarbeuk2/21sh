/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_RST.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:19:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/29 16:48:16 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	reset_line(t_data *data)
{
	ft_move_home(data);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
	if (data->entry->line)
		print_lst_line(data, data->entry->line);
	return ;
}