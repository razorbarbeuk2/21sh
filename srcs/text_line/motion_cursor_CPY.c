/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor_CPY.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:18:02 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/10 19:12:33 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_cpy_word_left(t_data *data, int result)
{
	t_list	*tmp;

	(void)result;
	tmp = NULL;
	//  = 0;

	tputs(tgetstr("so", NULL), 1, ft_putchar_select);
	// // ft_putnbr_fd(tgetflag("ms"), data->sel->tty);
	// // if (!tgetflag("ms"))
	
	
	// tmp = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
	ft_putchar_fd('f', data->sel->tty);
	tputs(tgetstr("me", NULL), 1, ft_putchar_select);
	ft_move_cursor(data, LEFT);
	return ;
}

void	ft_cpy_word_right(t_data *data, int result)
{
	t_list	*tmp;

	(void)result;
	tmp = NULL;
	tputs(tgetstr("so", NULL), 1, ft_putchar_select);
	ft_move_right(data);
	tputs(tgetstr("se", NULL), 1, ft_putchar_select);
	return ;
}