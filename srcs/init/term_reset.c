/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:11:25 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/27 19:11:27 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_reset_myterm(struct termios *term)
{
	term->c_lflag |= (ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
}

void		ft_term_reset(int opt)
{
	t_select		*sel_finish;

	sel_finish = NULL;
	sel_finish = ft_static_select(sel_finish, 1);
	if (tcgetattr(0, &sel_finish->myterm) == -1)
		return ;
	ft_reset_myterm(&sel_finish->myterm);
	if (tcsetattr(0, TCSANOW, &sel_finish->myterm) == -1)
		return ;
	if (!opt)
		tputs(tgetstr("te", NULL), 1, ft_putchar_select);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_select);
	exit(0);
}

void		ft_term_stop(void)
{
	t_select	*sel;
	char		st[2];

	sel = NULL;
	sel = ft_static_select(sel, 1);
	sel->myterm.c_lflag |= (ICANON | ECHO);
	st[0] = sel->myterm.c_cc[VSUSP];
	st[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_select);
	tcsetattr(0, 0, &(sel->myterm));
	tputs(tgetstr("te", NULL), 1, ft_putchar_select);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_select);
	ioctl(0, TIOCSTI, st);
}

void		ft_term_cont(void)
{
	t_select *sel;

	sel = NULL;
	sel = ft_static_select(sel, 1);
	ft_init_term(&(sel->myterm));
	tcsetattr(0, 0, &(sel->myterm));
	tputs(tgetstr("ti", NULL), 1, ft_putchar_select);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_select);
	signal(SIGTSTP, ft_signal_ctrl);
	ft_term_resize();
}
