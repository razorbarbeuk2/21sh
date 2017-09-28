/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 12:21:40 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/28 19:59:11 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		builtin_echo_use_n(t_data *data, char **line)
{
	int		i;

	i = 1;
	while (line[i])
	{
		builtin_echo_quote(data, &line[i]);
		while ((line[i]) && (line[i][0] == '-'))
			i++;
		ft_putstr(line[i]);
		ft_putchar(' ');
		ft_strdel(&line[i]);
		i++;
	}
}

static int	type_op(char c)
{
	static t_char	t[] = {
		{'a', 7},
		{'b', 8},
		{'c', 4},
		{'f', 12},
		{'n', 10},
		{'r', 13},
		{'t', 9},
		{'v', 11},
		{'\\', 92},
		{'\0', 0}
	};
	int				r;

	r = 0;
	while (t[r].l)
	{
		if (c == t[r].l)
			return (t[r].g);
		r++;
	}
	return (c);
}

static char	*ft_put_opt(char *line, char *st)
{
	while (*st != *line)
		ft_putchar(*st++);
	line += 2;
	if (type_op(*line))
	{
		ft_putchar(type_op(*line));
		line += 2;
		return (line);
	}
	return (NULL);
}

void		builtin_echo_use_e(t_data *data ,char **line)
{
	char	*st;
	int		i;

	i = 1;
	st = NULL;
	ft_strdel(&line[0]);
	while (line[i])
	{
		builtin_echo_quote(data, &line[i]);
		st = line[i];
		if (ft_strchr(st, 39))
		{
			ft_strdel(&line[i]);
			line[i] = ft_strdup(ft_strchr(st, 39));
			st = ft_strdup(ft_put_opt(line[i], st));
			ft_strdel(&line[i]);
		}
		ft_striter_c(st, &ft_putchar);
		ft_putchar(' ');
		ft_strdel(&st);
		i++;
	}
	ft_putstr("\n");
}
