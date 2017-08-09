/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:50:15 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/01 15:31:33 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		get_exe_cmd(t_data *data, char **path, char **cmd, t_list *env_lst)
{
	pid_t	pid;
	int		status;

	pid = fork();
	(void)data;
	if (pid != 0)
		waitpid(-1, &status, 0);
	else
		return(execve(*path, cmd, get_lst_to_tab(env_lst)));
	return (0);
}
