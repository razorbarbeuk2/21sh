/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_set_unset_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:23 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/28 12:03:07 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int				builtin_unsetenv(t_data *data, char **line)
{
	int i;

	i = 1;
	(void)data;
	ft_strdel(&line[0]);
	while (line[i])
	{
		iter_elem_env(&line[i], &data->env, &del_elem);
		ft_strdel(&line[i]);
		i++;
	}
	return (0);
}

static void		builtin_setenv_next(char **tmp, t_list **env_lst, \
	char **line, int n)
{
	if (!line[2])
		tmp[1] = " ";
	tmp[n] = NULL;
	iter_elem_env(tmp, env_lst, &modif_elem);
	ft_strdel_double(tmp);
}

int				builtin_setenv(t_data *data, char **line)
{
	int		i;
	int		n;
	char	**tmp;

	i = 1;
	n = 0;
	(void)data;
	if (line[i] && ft_isalpha_string(line[i]))
	{
		if (ft_count_tab(&line[i]) > 2)
		{
			print_error("Too many arguments.\n");
			return (0);
		}
		if (!(tmp = (char **)malloc((3) * sizeof(char *))))
			return (0);
		while (line[i])
		{
			tmp[n] = line[i];
			n++;
			i++;
		}
		builtin_setenv_next(tmp, &data->env, line, n);
	}
	return (0);
}
