/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:48:45 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/04 23:34:40 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			exec_no_paths(t_data *data, char **line)
{
	if (!data->paths)
	{
		if (access(line[0], X_OK) == 0)
		{
			if (execve(line[0], line, get_lst_to_tab(data->env)) == -1)
				return (-1);
			return (1);
		}
		return(ft_print_error("PATH is empty"));
	}
	return (0);
}

int			exec_get_access(t_data *data, char **line, char *result)
{
	if (access(result, X_OK) == 0)
	{
		if (execve(result, line, get_lst_to_tab(data->env)) == -1)
			return (-1);
		ft_strdel(&result);
		return (1);
	}
	return (0);
}
