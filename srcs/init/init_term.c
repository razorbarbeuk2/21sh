/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:40:50 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/03 15:00:33 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void		termios_init(struct	termios *term)
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
		//ft_putnbr(tgetent(NULL, getenv("TERM")));
		if (tgetent(NULL, getenv("TERM")) == -1)
			return (ft_print_error("Tgetent ERROR\n"));
		if (tcgetattr(0, &term->myterm) == -1)
			return (ft_print_error("Tcgetattr ERROR\n"));
		termios_init(&term->myterm);
		if (ioctl(term->tty, TIOCGWINSZ, &win) == -1)
			return (ft_print_error("Ioctl ERROR\n"));
		if (tcsetattr(term->tty, TCSADRAIN, &term->myterm) == -1)
			return (ft_print_error("Tcsetattr ERROR\n"));
		term->width = tgetnum("co");
		term->height = tgetnum("li");
		
		// ft_putnbr(term->height);
		// write(1, "\n", 1);
		// cl_string = tgetstr ("cl", 0);
  		// cm_string = tgetstr ("cm", 0);
		//ft_putnbr(tgetflag("am"));
		//tputs(tgetstr("am", NULL), 1, ft_putchar_select);
	}
	return (1);
}


