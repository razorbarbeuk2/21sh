/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_RST.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:19:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/12 18:09:07 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	reset_line(t_data *data)
{
	ft_move_home(data);
	get_pos_prompt(data);
	print_lst_line(data, data->entry->line);
	return ;
}