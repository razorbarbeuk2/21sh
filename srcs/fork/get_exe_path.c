/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:52:27 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/17 12:00:13 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void		*ft_name_join(char *name, char *path)
{
	char *tmp;

	tmp = NULL;
	if (name[0] != '/')
		path = ft_strjoin(path, "/");
	tmp = ft_strjoin(path, name);
	ft_strdel(&path);
	return (tmp);
}

static char		*get_exe_path_check_result(char *line, char *paths, int i)
{
	if (i == 0 && ft_strchr(line, '/'))
		return (ft_strdup(line));
	else
		return (ft_name_join(line, paths));
}

void			get_exe_path(t_data *data, char **line)
{
	char	**paths;
	char	*result;
	int		i;

	i = 0;
	if (!ft_no_paths(data->env, line, &paths, &result))
		return ;
	while (paths && paths[i])
	{
		result = get_exe_path_check_result(line[0], paths[i], i);
		if (ft_get_access(data->env, line, paths, result))
			return ;
		else if (i == 0 && ft_strchr(line[0], '/'))
		{
			print_cmd_not_found(line[0]);
			ft_free_char(paths);
			ft_strdel(&result);
			return ;
		}
		ft_strdel(&result);
		i++;
	}
	ft_free_char(paths);
	print_cmd_not_found(line[0]);
}
