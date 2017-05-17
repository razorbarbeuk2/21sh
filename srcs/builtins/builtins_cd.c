/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:27 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/17 11:59:12 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int		ft_check_caract(t_list **env_lst, char **path, char **line)
{
	if (!get_search_infos(*env_lst, "OLDPWD") \
		|| !get_search_infos(*env_lst, "PWD"))
		print_error("No PWD or OLDPWD in env\n");
	if ((!line[1] && !get_search_infos(*env_lst, "HOME")) \
		|| (!get_search_infos(*env_lst, "HOME")))
		print_error("No HOME in env\n");
	else
	{
		if (!line[1] && (path[1] = \
			builtin_cd_special_caract_home_noline(env_lst, line)))
		{
			ft_strdel(&line[1]);
			line[1] = path[1];
			return (1);
		}
	}
	if (line[1] && (path[1] = builtin_cd_special_caract(env_lst, line)))
	{
		ft_strdel(&line[1]);
		line[1] = path[1];
		return (1);
	}
	return (0);
}

static int		ft_init_path(char ***oldpath, char ***path, char **line)
{
	*oldpath = NULL;
	*path = NULL;
	if (ft_count_tab(line) > 2)
	{
		print_error("Too many arguments\n");
		return (0);
	}
	if (!(*path = (char **)malloc((2) * sizeof(char *))))
		return (0);
	if (!(*oldpath = (char **)malloc((2) * sizeof(char *))))
		return (0);
	*oldpath[0] = ft_strdup("OLDPWD");
	*path[0] = ft_strdup("PWD");
	return (1);
}

int				builtin_cd(t_data *data, t_list **env_lst, char **line)
{
	char	**oldpath;
	char	**path;

	if (!ft_init_path(&oldpath, &path, line))
		return (0);
	oldpath[1] = ft_memalloc(1024);
	getcwd(oldpath[1], 1024);
	ft_strdel(&line[0]);
	ft_check_caract(env_lst, path, line);
	path[1] = ft_memalloc(1024);
	if (path && oldpath && line[1])
	{
		if (ft_check_move(line[1]))
		{
			getcwd(path[1], 1024);
			iter_elem_env(oldpath, env_lst, &modif_elem);
			iter_elem_env(path, env_lst, &modif_elem);
		}
		ft_free_tab_path(oldpath, path);
		return (1);
	}
	ft_free_tab_path(oldpath, path);
	return (0);
}
