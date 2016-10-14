/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:43:20 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/14 16:25:03 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"



void		ft_move_cursor(t_select *sel, int result)
{
	if (result == LEFT)
		ft_move_left(sel, sel->pos);
	if (result == RIGHT)

	if (result == DOWN)

	if (result == UP)
	tputs(tgoto(tgetstr("cm", NULL), sel->pos[0], sel->pos[1]), 1, ft_putchar_select);

}

void		print_character(t_data *data, char result)
{
	tputs(tgetstr("im", NULL), 1, ft_putchar_select);
	ft_putchar_fd(result, data->sel->tty);
	tputs(tgetstr("ic", NULL), 1, ft_putchar_select);
	tputs(tgetstr("ip", NULL), 1, ft_putchar_select);
	tputs(tgetstr("ei", NULL), 1, ft_putchar_select);
}

int			listen_cursor(t_data *data)
{
	char				buf[7];
	int					result;

	result = 0;
	ft_bzero(buf, 7);
	get_super_prompt(data, NULL);
	ft_putstr(tgetstr("cv", NULL));
	ft_putchar(' ');
	ft_putstr(tgetstr("ch", NULL));
	while(read(0, buf, 7))
	{
		result = ft_concat_int(buf);

		if (ft_isalpha(result))
			print_character(data, result);
		if (result >= UP && result <= LEFT)
			ft_move_cursor(data->sel, result);

		ft_bzero(buf, 7);
	}
	return (0);
}
