/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_ALT_W_LR.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:14:09 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/04 23:30:37 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	ft_move_word_LR(t_data *data, int offset, char opt)
{
	while (offset)
	{
		if (opt == 'L')
			ft_move_cursor(data, LEFT, MOVE_LST);
		if (opt == 'R')
			ft_move_cursor(data, RIGHT, MOVE_LST);
		get_pos_prompt(data);
		offset--;
	}
	return ;
}

void 		ft_move_word_left(t_data *data)
{ 
	t_list		*tmp;
	int 		count;
	int 		offset;
	int			_i;

	_i = 0;
	offset = 0;
	count = data->sel->i_lst;
	while (count--)
	{
		tmp = NULL;
		tmp = ft_move_at_list(data, &data->entry->line, count);
		if (tmp && tmp->next)
		{
			if (!data_check_caract(((char *)tmp->content)[0]) && data_check_caract(((char *)tmp->next->content)[0]) && !_i)
				_i = 1;
			if (data_check_caract(((char *)tmp->content)[0]) && !data_check_caract(((char *)tmp->next->content)[0]) && _i)
				break ;
		}
	}
	offset = (data->sel->i_lst - count - 1);
	ft_move_word_LR(data, offset, 'L');
	return ;
}

void 		ft_move_word_right(t_data *data)
{ 
	t_list		*tmp;
	int 		offset;

	tmp = NULL;
	offset = 0;
	tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	while (tmp && tmp->next)
	{
		if (data_check_caract(((char *)tmp->content)[0]) && !data_check_caract(((char *)tmp->next->content)[0]))
			break ;
		tmp = tmp->next;
		offset++;
	}
	ft_move_word_LR(data, (offset + 1), 'R');
	return ;
}