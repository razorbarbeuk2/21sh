/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:52:27 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/13 14:58:18 by gbourson         ###   ########.fr       */
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

void 			exec_get_path(t_data *data, char **line)
{
	int		i;
	char	*result;

	i = 0;
	while (data->paths && data->paths[i])
	{
		result = exec_get_path_check_result((*line), data->paths[i], i);
		if (access(result, F_OK) == 0)
		{
			(*line) = result;
			return ;
		}
		ft_strdel(&result);
		i++;
	}
}