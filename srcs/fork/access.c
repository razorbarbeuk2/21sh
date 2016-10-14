/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:48:45 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/13 14:28:59 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_no_paths(t_list *env, char **line, char ***paths, char **result)
{
	*result = NULL;
	*paths = NULL;
	*paths = ft_strsplit(get_search_infos(env, "PATH"), ':');
	if (!*paths)
	{
		if (access(line[0], X_OK) == 0)
			get_exe_cmd(&line[0], line, env);
		else
			print_error("PATH is empty\n");
		return (0);
	}
	return (1);
}

int			ft_get_access(t_list *env, char **line, char **paths, char *result)
{
	if (access(result, X_OK) == 0)
	{
		get_exe_cmd(&result, line, env);
		ft_free_char(paths);
		ft_strdel(&result);
		return (1);
	}
	return (0);
}
