/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_ALT_W_LR.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:14:09 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/10 16:16:39 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			ft_is_caract(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

static void	ft_move_word_LR(t_data *data, int offset, char opt)
{
	while (offset--)
	{
		if (opt == 'L')
			ft_move_cursor(data, LEFT);
		if (opt == 'R')
			ft_move_cursor(data, RIGHT);
		get_pos_prompt(data);
	}
	return ;
}

void 		ft_move_word_left(t_data *data)
{ 
	t_list		*tmp;
	int 		count;
	int 		offset;
	int			_i;

	tmp = NULL;
	offset = 0;
	_i = 0;
	count = data->sel->i_lst;
	while (count--)
	{
		tmp = ft_move_at_list(data, &data->entry->line, count);
		if (tmp && tmp->next)
		{
			if (!ft_is_caract(((char *)tmp->content)[0]) && ft_is_caract(((char *)tmp->next->content)[0]) && !_i)
				_i = 1;
			if (ft_is_caract(((char *)tmp->content)[0]) && !ft_is_caract(((char *)tmp->next->content)[0]) && _i)
				break ;
		}
		tmp = NULL;
	}
	offset = data->sel->i_lst - count - 1;
	ft_move_word_LR(data, offset, 'L');
	return ;
}

void 		ft_move_word_right(t_data *data)
{ 
	t_list		*tmp;
	int 		offset;

	tmp = NULL;
	offset = 1;
	tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	while (tmp && tmp->next)
	{
		if (ft_is_caract(((char *)tmp->content)[0]) && !ft_is_caract(((char *)tmp->next->content)[0]))
			break ;
		offset++;
		tmp = tmp->next;
	}
	ft_move_word_LR(data, offset, 'R');
	return ;
}