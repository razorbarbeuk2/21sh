/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_line_builtins.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:19 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/13 15:59:26 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

typedef	int			(*t_function)(t_data *data, char **line);

struct				s_builtins
{
	char			*name;
	t_function		function;
};

static const struct	s_builtins	builtins[] = {
		{"env", builtin_env},
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{"echo", builtin_echo},
		{"cd", builtin_cd},
		{"exit", builtin_exit},
		{NULL, NULL}
};

int		exec_builtins_parsing(t_data *data, char **line)
{
	int		i;

	i = 0;
	while (builtins[i].name)
	{
			if (ft_strcmp(line[0], builtins[i].name) == 0)
				return (builtins[i].function(data, line));
			i++;
	}
	return (0);
}
