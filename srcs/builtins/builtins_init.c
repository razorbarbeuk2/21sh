/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:19 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/27 19:54:06 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_buil	*buil_init(void)
{
	static	t_buil		f[] = {
		{"env", builtin_env},
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{"echo", builtin_echo},
		{"cd", builtin_cd},
		{"exit", builtin_exit},
		{NULL, NULL}
	};

	return ((void *)f);
}

int				buil_drive(t_data *data, t_list **env_lst, char **line)
{
	int		i;
	t_buil	*buil;

	i = 0;
	(void)env_lst;
	buil = NULL;
	buil = buil_init();
	if (*line)
	{
		while (buil[i].name)
		{
			if (ft_strcmp(*line, buil[i].name) == 0)
				return (buil[i].f(data, line));
			i++;
		}
	}
	return (0);
}

int			parse_line_builtins(t_data *data, t_list **env_lst, char **line)
{
	int state;

	state = 0;
	if ((state = buil_drive(data, env_lst, line)))
		return (state);
	else
	{
		state = get_exe_path(data, line);
		if (state)
			return(0);
	}
	return (0);
}
