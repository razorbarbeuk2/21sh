/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:50:15 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/26 16:58:09 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		get_exe_cmd(char **path, char **cmd, t_list *env_lst)
{
	pid_t	pid;
	int		status;

	pid = fork();
	// ft_putstr("\nEXEC_CMD\n");
	// ft_putnbr(pid);
	// ft_putstr("\n******\n");
	//signal(SIGINT, handler_2);
	if (pid != 0)
		waitpid(-1, &status, 0);
	else
		return(execve(*path, cmd, get_lst_to_tab(env_lst)));
	return (0);
}
