/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:27 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/30 19:32:48 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int builtin_cd_next(t_data *data, char **oldpath, char **path)
{
	if (path[1] && oldpath[1])
	{
		if (builtin_cd_move(path[1]) == -1)
			return (-1);
		ft_free_char_array(&path);
		builtin_cd_init_path(&path);
		getcwd(path[1], 1024);
		iter_elem_env(oldpath, &data->env, &modif_elem);
		iter_elem_env(path, &data->env, &modif_elem);
		return (1);
	}
	return (-1);
}

int builtin_cd(t_data *data, char **line)
{
	char **oldpath;
	char **path;

	if (builtin_cd_init_paths(&oldpath, &path, line) == -1)
		return (-1);
	if (builtin_cd_check_caract(data, &path[1], line) == -1)
		return (-1);
	if (builtin_cd_next(data, oldpath, path))
		return (-1);
	ft_free_char_array(&oldpath);
	ft_free_char_array(&path);
	return (1);
}
