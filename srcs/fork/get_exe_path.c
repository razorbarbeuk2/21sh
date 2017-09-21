/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:52:27 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/21 18:50:28 by gbourson         ###   ########.fr       */
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
	if (line)
	{
		if (i == 0 && ft_strchr(line, '/'))
			return (ft_strdup(line));
		else
			return (ft_name_join(line, paths));
	}
	return (NULL);
}

int			get_exe_path(t_data *data, char **line)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	if (!ft_no_paths(data, line))
		return (0);
	while (data->paths && data->paths[i])
	{
		result = get_exe_path_check_result(line[0], data->paths[i], i);
		if(ft_get_access(data, line, result))
			return (1);
		if (i == 0 && ft_strchr(line[0], '/'))
		{
			print_cmd_not_found(line[0]);
			ft_strdel(&result);
			return (1);
		}
		ft_strdel(&result);
		result = NULL;
		i++;
	}
	print_cmd_not_found(line[0]);
	return (1);
}
