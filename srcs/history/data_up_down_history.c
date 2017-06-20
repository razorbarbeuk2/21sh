/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_up_down_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:17:19 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/20 18:21:12 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char			*ft_search_up_down_historic(t_data *data, int count_pos)
{
	char 		*tmp;
	int 		pos;

	tmp = NULL;
	pos = 0;
	while (data->historic->list_historic && pos < count_pos)
	{
		tmp = (char *)data->historic->list_historic->content;
		data->historic->list_historic = data->historic->list_historic->next;
		pos++;
	}
	return (tmp);
}

int				ft_move_up_down_historic(t_data *data, int result)
{
	char  		*tmp;
	
	tmp = NULL;
	if (data->historic->list_historic)
	{

		ft_move_home(data);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
		ft_putstr_fd("||", data->sel->tty);
		ft_putnbr_fd(data->historic->count_pos, data->sel->tty);
		ft_putstr_fd("||", data->sel->tty);
		data->historic->count_pos++;
		tmp = ft_search_up_down_historic(data, data->historic->count_pos);
		if (tmp)
		{
			ft_putstr_fd(tmp, data->sel->tty);
			write(data->sel->tty, " ", 1);
			ft_putnbr_fd(data->historic->count_pos, data->sel->tty);
		}
		// if (result == UP && data->historic->count_pos < data->historic->count_node)
		// {
		// 	data->historic->count_pos++;
		// 	ft_putstr_fd("||", data->sel->tty);
		// 	ft_putnbr_fd(data->historic->count_pos, data->sel->tty);
		// 	ft_putstr_fd("||", data->sel->tty);
		// }
	}
	return (0);
}