/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_line_builtins.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:19 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/04 23:39:13 by gbourson         ###   ########.fr       */
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

static int	builtins_parsing(t_data *data, char **line)
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

int 		exec_exe_step(t_data *data, char **line, int fork_state)
{
	if (exec_get_path(data, line) == -1)
		return (ft_print_error("Error path cmd\n"));
	return (exec_exit(fork_state));
}

int			exec_parse_line_builtins(t_data *data, char **line, int fork_state)
{
	int result;

	result = 0;
	if ((result = builtins_parsing(data, line)))
		return (result);
	else
	{
		if (fork_state)
		{
			if (exec_fork_step(data, fork_state))
				return (exec_exe_step(data, line, fork_state));
		}
		else
			return (exec_exe_step(data, line, fork_state));
	}
	return (0);
}
