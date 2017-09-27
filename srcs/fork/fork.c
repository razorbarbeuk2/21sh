/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:50:15 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/27 19:55:46 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		get_exe_cmd(t_data *data, char **path, char **cmd, t_list *env_lst)
{
	(void)data;
	return (execve(*path, cmd, get_lst_to_tab(env_lst)));
}
