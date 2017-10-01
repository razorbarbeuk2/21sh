/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:49:26 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/01 20:32:22 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static char *ft_concat_opt(const struct s_option *t)
{
	int i;
	char *c;

	i = 0;
	c = NULL;
	while (t[i].option)
		i++;
	c = ft_memalloc(i * sizeof(char));
	i = 0;
	while (t[i].option)
	{
		c[i] = t[i].option;
		i++;
	}
	c[i] = '\0';
	return (c);
}

static int builtin_move_opt(char *line)
{
	int i;

	i = 0;
	while (line[i] == '-')
		i++;
	return (i);
}

int builtin_opt_init(struct s_option *s_option_tab)
{
	int opt;

	opt = 0;
	while (s_option_tab[opt].option)
	{
		s_option_tab[opt].set = 0;
		opt++;
	}
	return (1);
}

int builtin_parse_opt_check(char c, struct s_option *s_option_tab)
{
	int opt;
	int set_option;

	opt = 0;
	set_option = 0;
	while (s_option_tab[opt].option)
	{
		if (c == s_option_tab[opt].option)
		{
			s_option_tab[opt].set = OPT;
			set_option = 1;
		}
		opt++;
	}
	if (!set_option)
		return (-1);
	return (1);
}

int builtin_parse_opt(t_data *data, char **line, char *builtins, struct s_option *s_option_tab)
{
	int i;
	int n;

	i = 1;
	(void)data;
	s_option_tab = builtins_stat_option();
	while (line[i] && line[i][0] == '-')
	{
		n = builtin_move_opt(line[i]);
		while (line[i][n])
		{
			
			if (builtin_parse_opt_check(line[i][n], s_option_tab) == -1)
				return (ft_print_error_option(line[i][n], ft_concat_opt(s_option_tab), builtins));
			n++;
		}
		i++;
	}
	return (0);
}
