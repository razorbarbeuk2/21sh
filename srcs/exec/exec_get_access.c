/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:48:45 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/12 21:17:11 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			exec_get_access(t_data *data, char **line, char *result)
{
	execve(result, line, get_lst_to_tab(data->env));
	exit(EXIT_FAILURE);
	return (0);
}