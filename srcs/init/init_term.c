/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:40:50 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/27 17:03:17 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		termios_init(struct	termios *term)
{
	term->c_lflag &= ~(ECHO | ICANON);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
}

int			term_init(t_term *term)
{
	struct winsize	win;

	term->tty = open("/dev/tty", O_RDWR);
	if(isatty(term->tty))
	{
		if (tgetent(NULL, getenv("TERM")) == ERR)
			return (-1);
		if (tcgetattr(0, &term->myterm) == -1)
			return (-1);
		termios_init(&term->myterm);
		if (ioctl(term->tty, TIOCGWINSZ, &win) == -1)
			return (-1);
		if (tcsetattr(term->tty, TCSADRAIN, &term->myterm) == -1)
			return (-1);
		term->width = win.ws_col;
		term->height = win.ws_row;
	}
	return (1);
}
