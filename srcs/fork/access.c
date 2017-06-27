/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:48:45 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/26 18:12:17 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_no_paths(t_data *data, char **line)
{
	if (!data->paths)
	{
		if (access(line[0], X_OK) == 0)
			get_exe_cmd(&line[0], line, data->env);
		else
			print_error("PATH is empty\n");
		return (0);
	}
	return (1);
}

int			ft_get_access(t_data *data, char **line, char *result)
{
	
	// ft_putstr(result);
	// ft_putstr("\n");
	// ft_putstr("PP");
	// ft_putstr(result);
	// ft_putstr("TUTU");
	// write(1, "\n", 1);
	if (access(result, X_OK) == 0)
	{
		get_exe_cmd(&result, line, data->env);
		ft_strdel(&result);
		return (1);
	}
	return (0);
}
