/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:52:27 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/12 21:21:03 by gbourson         ###   ########.fr       */
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

static char		*exec_get_path_check_result(char *line, char *paths, int i)
{
	if (line)
	{
		if (i == 0 && ft_strchr(line, '/'))
			return (ft_strdup(line));
		else
			return (ft_name_join(line, paths));
	}
	return (NULL);
}

int				exec_get_path(t_data *data, char **line)
{
	int		i;
	char	*result;

	i = 0;
	while (data->paths && data->paths[i])
	{
		result = exec_get_path_check_result(line[0], data->paths[i], i);
		if (access(result, X_OK) == 0)
			exec_get_access(data, line, result);
		i++;
		ft_strdel(&result);
	}
	return (0);
}