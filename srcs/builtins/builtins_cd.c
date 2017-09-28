/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:27 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/28 17:45:05 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

typedef char *(*t_func_caract)(t_data *data, char *str);

struct s_caract
{
	char *caract;
	char *token;
	t_func_caract f;
};

static const struct s_caract s_caract_tab[] = {
	{"~", "HOME", get_search_infos},
	{"~/", "HOME", get_search_infos},
	{"-", "OLDPWD", get_search_infos},
	{"/", NULL, builtin_cd_special_caract_slash},
	{"..", NULL, builtin_cd_special_caract_return},
	{"../", NULL, builtin_cd_special_caract_return},
	{NULL, NULL, NULL}};

static char *builtin_cd_parse_special_caract(t_data *data, char *line)
{
	int i;

	i = 0;
	while (s_caract_tab[i].caract)
	{
		if (ft_strcmp(s_caract_tab[i].caract, line) == 0)
			return (s_caract_tab[i].f(data, s_caract_tab[i].token));
		i++;
	}
	return (line);
}

static int ft_check_caract(t_data *data, char **path, char **line)
{
	if (!get_search_infos(data, "OLDPWD") || !get_search_infos(data, "PWD"))
		return (ft_print_error("No PWD or OLDPWD in env"));
	if (!line[1])
		return (builtin_cd_special_caract_home(data, &path[1]));
	if (line[1])
	{
		path[1] = ft_strdup(builtin_cd_parse_special_caract(data, line[1]));
		ft_strdel(&line[1]);
		line[1] = path[1];
		return (1);
	}
	return (0);
}

static int ft_init_path(char ***oldpath, char ***path, char **line)
{
	if (builtins_check_args(line, 2) == -1)
		return (-1);
	(*path) = ft_memalloc(2 * sizeof(char *));
	(*oldpath) = ft_memalloc(2 * sizeof(char *));
	(*oldpath)[0] = ft_strdup("OLDPWD");
	(*path)[0] = ft_strdup("PWD");
	(*oldpath)[1] = ft_memalloc(1024 * sizeof(char *));
	(*path)[1] = ft_memalloc(1024 * sizeof(char *));
	return (1);
}

int builtin_cd(t_data *data, char **line)
{
	char **oldpath;
	char **path;

	if (ft_init_path(&oldpath, &path, line) == -1)
		return (-1);
	getcwd(oldpath[1], 1024);
	ft_strdel(&line[0]);
	// ft_putendl("test-------------");
	// ft_putendl(oldpath[0]);
	// ft_putendl(oldpath[1]);
	// ft_putendl(path[0]);
	// ft_putendl(path[1]);
	// ft_putendl("------------------");
	if (ft_check_caract(data, &path[1], line))
	{
		if (path[1] && oldpath)
		{
			if (ft_check_move(line[1]))
			{
				getcwd(path[1], 1024);
				ft_putendl(oldpath[1]);
				ft_putendl(path[1]);
				print_env(data->env);
				iter_elem_env(oldpath, &data->env, &modif_elem);
				iter_elem_env(path, &data->env, &modif_elem);
			}
			ft_free_tab_path(oldpath, path);
			return (1);
		}
	}
	ft_free_tab_path(oldpath, path);
	return (0);
}
