/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:48:45 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/14 12:43:31 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			exec_get_access(t_data *data, char **line)
{
	
	if (access(line[0], X_OK) == 0)
	{
		execve(line[0], line, get_lst_to_tab(data->env));
		ft_print_cmd_not_found(line[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_print_error_access(line[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}