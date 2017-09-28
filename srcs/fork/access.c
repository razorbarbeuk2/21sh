/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:48:45 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/28 12:26:02 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_no_paths(t_data *data, char **line)
{
	if (!data->paths)
	{
		if (access(line[0], X_OK) == 0)
			get_exe_cmd(data, &line[0], line, data->env);
		else
			return(ft_print_error("PATH is empty"));
		return (0);
	}
	return (1);
}

int			ft_get_access(t_data *data, char **line, char *result)
{
	if (access(result, X_OK) == 0)
	{
		if (get_exe_cmd(data, &result, line, data->env))
			ft_strdel(&result);
		return (1);
	}
	return (0);
}
