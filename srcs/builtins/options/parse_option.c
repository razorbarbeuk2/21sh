/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:49:26 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/29 13:15:40 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static char *ft_concat_opt(const struct s_option *t)
{
	int 	i;
	char 	*c;

	i = 0;
	c = NULL;
	while (t[i].option)
		i++;
	c = ft_memalloc(i * sizeof(char));
	i = 0;
	while (t[i].option)
	{
		c[i] = t[i].option[0];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static int	builtin_move_opt(char *line)
{
	int i;

	i = 0;
	while (line[i] == '-')
		i++;
	return (i);
}

int builtin_parse_opt(t_data *data, char *line, char *builtins, const struct s_option s_option_tab[])
{
	int i;
	int n;
	int set;

	i = 0;
	n = builtin_move_opt(line);
	while (line[n])
	{
		i = 0;
		set = 0;
		while (s_option_tab[i].option)
		{
			if (ft_strcmp(s_option_tab[i].option, &line[n]) == 0)
			{
				if (s_option_tab[i].f(data, line) == -1)
					ft_print_error("Error Option function");
				set = 1;
			}
			i++;
		}
		if (!set)
			return (ft_print_error_option(&line[n], ft_concat_opt(s_option_tab), builtins));
		n++;
	}
	return (0);
}

