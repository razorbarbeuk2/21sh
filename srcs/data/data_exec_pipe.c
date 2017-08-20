/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:35:20 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/20 17:52:28 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// int			exec_cmd_node_pipe(t_data *data, t_list *prev, t_list *next, int *save_fd)
// {
// 	int 	pfd[2];
// 	pid_t	pid;

// 	(void)save_fd;
// 	if ((pid = fork()) == -1)
// 		print_error("fork error");
// 	pipe(pfd);
// 	if (pid == 0)
// 	{
// 		ft_putendl("CHILD ---------------------");
// 		close(pfd[1]);
//        	dup2(pfd[0], STDIN_FILENO);
//        	close(pfd[0]);
// 		return (exec_cmd_node(data, next));
// 	}
// 	else
// 	{
// 		ft_putendl("FATHER ---------------------");
// 		close(pfd[0]);
// 		dup2(pfd[1], STDOUT_FILENO);
// 		close(pfd[1]);
// 		return (exec_cmd_node(data, next));
// 	}
// 	close(pfd[0]);
// 	close(pfd[1]);
// 	waitpid(pid, 0, 0);
// 	return (0);
// }

// int		exec_cmd_node(t_data *data, t_list *cur)
// {
// 	char **exec_line;

// 	exec_line = NULL;
// 	// exec_line = ((t_cmd *)cur->content)->exec_cmd;
// 	if (exec_line)
// 		parse_line_builtins(data, &data->env, ((t_cmd *)cur->content)->exec_cmd);
// 	return (0);
// }