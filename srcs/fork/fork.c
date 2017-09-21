/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:50:15 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/21 18:52:33 by gbourson         ###   ########.fr       */
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
	{
		ft_putendl("PATH=-----------");
		ft_putendl(*path);
		ft_putendl("CMD-----------");
		print_tab(data, cmd);
		ft_putendl("-----------");
		ft_putnbr(execve(*path, cmd, get_lst_to_tab(env_lst)));
	}
		
	return (0);
}
