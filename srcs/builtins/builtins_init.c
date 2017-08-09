/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:19 by gbourson          #+#    #+#             */
/*   Updated: 2017/08/04 15:54:47 by RAZOR            ###   ########.fr       */
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

int				buil_drive(t_data *data, t_list **env_lst, char **line, int opt)
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
			{
				if (!opt)
					return (1);
				else
					return (buil[i].f(data, line));
			}
			i++;
		}
	}
	return (0);
}

int			parse_line_builtins(t_data *data, t_list **env_lst, char **line)
{
	if (buil_drive(data, env_lst, line, BUILD_FIND))
		return(buil_drive(data, env_lst, line, BUILD_EXE));
	else
		return(get_exe_path(data, line));
	return (0);
}
