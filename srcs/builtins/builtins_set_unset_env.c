/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_set_unset_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:23 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/28 11:56:28 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int				builtin_unsetenv(t_data *data, char **line)
{
	int i;

	i = 1;
	ft_strdel(&line[0]);
	while (line[i])
	{
		iter_elem_env(&line[i], &data->env, &del_elem);
		ft_strdel(&line[i]);
		i++;
	}
	return (0);
}

static void		builtin_setenv_next(char **tmp, t_list **env_lst, char **line)
{
	if (!line[2])
		tmp[1] = " ";
	tmp[2] = NULL;
	iter_elem_env(tmp, env_lst, &modif_elem);
	ft_strdel_double(tmp);
}

int				builtin_setenv(t_data *data, char **line)
{
	char	**tmp;
	int		i;

	i = 1;
	if (line[i] && ft_isalpha_string(line[i]))
	{
		if (builtins_check_args(line, 3))
			return (-1);
		tmp = ft_memalloc(3*sizeof(char *));
		while (line[i])
		{
			tmp[i - 1] = line[i];
			i++;
		}
		builtin_setenv_next(tmp, &data->env, line);
	}
	return (1);
}
