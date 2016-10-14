/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:40:50 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/14 14:31:00 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		termios_init(struct	termios *term)
{
	term->c_lflag &= ~(ECHO | ICANON);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
}

int			term_init(t_select *sel)
{
	struct winsize	win;

	sel->tty = open("/dev/tty", O_RDWR);
	if(isatty(sel->tty))
	{
		if (tgetent(NULL, getenv("TERM")) == ERR)
			return (-1);
		if (tcgetattr(0, &sel->myterm) == -1)
			return (-1);
		termios_init(&sel->myterm);
		if (ioctl(sel->tty, TIOCGWINSZ, &win) == -1)
			return (-1);
		if (tcsetattr(sel->tty, TCSADRAIN, &sel->myterm) == -1)
			return (-1);
		sel->width = win.ws_col;
		sel->height = win.ws_row;
		// tputs(tgetstr("ti", NULL), 1, ft_putchar_select);
		// tputs(tgetstr("vi", NULL), 1, ft_putchar_select);
	}
	return (1);
}
