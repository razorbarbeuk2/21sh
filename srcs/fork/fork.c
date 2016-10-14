/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:50:15 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/13 15:03:06 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		get_exe_cmd(char **path, char **cmd, t_list *env_lst)
{
	pid_t	pid;
	int		status;

	pid = fork();
	//signal(SIGINT, handler_2);
	if (pid != 0)
		waitpid(pid, &status, 0);
	else
		execve(*path, cmd, get_lst_to_tab(env_lst));
}
