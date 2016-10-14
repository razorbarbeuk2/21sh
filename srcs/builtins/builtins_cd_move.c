/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:17:54 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/12 17:14:33 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	free_move_infos_print(char *path, char *tmp)
{
	ft_putendl(tmp);
	ft_strdel(&tmp);
	ft_strdel(&path);
}

int			ft_check_move(char *path)
{
	struct stat		infos;
	char			*tmp;

	if (stat(path, &infos) == -1)
	{
		tmp = ft_strjoin(path, ": No such file or directory.");
		free_move_infos_print(path, tmp);
		return (0);
	}
	if (!S_ISDIR(infos.st_mode))
	{
		tmp = ft_strjoin(path, ": Not a directory.");
		free_move_infos_print(path, tmp);
		return (0);
	}
	if (chdir(path) != 0)
	{
		tmp = ft_strjoin(path, ": Permission denied");
		free_move_infos_print(path, tmp);
		return (0);
	}
	ft_strdel(&path);
	return (1);
}

char		*builtin_cd_special_caract_home_noline(t_list **env_lst, \
	char **line)
{
	if ((!line[1]) && (get_search_infos(*env_lst, "HOME")))
		return (ft_strdup(get_search_infos(*env_lst, "HOME")));
	else
		return (NULL);
}

char		*builtin_cd_special_caract_home(t_list **env_lst, char **line)
{
	if ((ft_strcmp(line[1], "~") == 0) || (ft_strcmp(line[1], "~/") == 0))
		return (ft_strdup(get_search_infos(*env_lst, "HOME")));
	else
		return (ft_strjoin(get_search_infos(*env_lst, "HOME") \
		, ft_strchr(line[1], '/')));
}

char		*builtin_cd_special_caract(t_list **env_lst, char **line)
{
	if ((line[1][0] == '~' || (ft_strcmp(line[1], "~") == 0)) \
		&& (get_search_infos(*env_lst, "HOME")))
		return (builtin_cd_special_caract_home(env_lst, line));
	else if (line[1] && (ft_strcmp(line[1], "/") == 0))
		return (ft_strdup("/"));
	else if (line[1] && (ft_strcmp(line[1], "-") == 0) \
		&& get_search_infos(*env_lst, "OLDPWD"))
		return (ft_strdup(get_search_infos(*env_lst, "OLDPWD")));
	else if (line[1] && ((ft_strcmp(line[1], "..") == 0) \
		|| (ft_strcmp(line[1], "../") == 0)))
		return (ft_strdup(".."));
	else
		return (ft_strdup(line[1]));
}
