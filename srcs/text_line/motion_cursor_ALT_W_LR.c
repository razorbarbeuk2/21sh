/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_ALT_W_LR.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:14:09 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/09 17:30:10 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_is_caract(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

void ft_move_word_left(t_data *data)
{ 
	t_list		*tmp;

	tmp = NULL;
	tmp = data->entry->line;
	while (data->sel->i_lst > 0)
	{
		tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
		if (ft_is_caract((char)tmp->content) && !ft_is_caract((char)tmp->next->content))
		{
			ft_move_left(data);
			break ;
		}
		ft_move_left(data);
	}
	return ;
}

void ft_move_word_right(t_data *data)
{ 
	t_list		*tmp;

	tmp = NULL;
	tmp = data->entry->line;
	while (data->sel->i_lst <  (int)data->entry->len_line)
	{
		tmp = ft_move_at_list(data, &tmp, data->sel->i_lst);
		if (ft_is_caract((char)tmp->content) && !ft_is_caract((char)tmp->next->content))
		{
			ft_move_right(data);
			break ;
		}
		else
			ft_move_right(data);
		tmp = NULL;
	}
	return ;
}