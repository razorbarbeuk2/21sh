/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:35:20 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/26 18:04:23 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			create_pipe(int pipfd[2], t_fd *fd)
{
	(void)fd;
	(void)pipfd;
// 	ft_putstr("PIPE\n");
// 	if (pipe(pipefd) == -1)
// 	{
// 		print_error("pipe error");
// 		return (-1);
// 	}
// 	fd->stdin = pipefd[PIPE_WRITE];
	return (0);
//
}

int			exec_cmd_node_pipe(t_data *data, t_list *prev, t_list *next)
{
// 	t_fd	fd;
// 	int		pipefd[2];
// 	pid_t	pid;

	(void)data;
	(void)prev;
	(void)next;
// 	if (create_pipe(pipefd, fd) == -1)
// 		return (-1);
// 	if ((pid = fork()) == -1)
// 		print_error("fork error");
	
// 	if (pid == 0)
// 	{
// 		/* parent */
// 		ft_putstr("\nDAD\n");
// 		close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		//close(pipefd[0]);
// 		exec_cmd_node(data, next);
// 		return (1);
// 	}
// 	else
// 	{
// 		/* child */
// 		ft_putstr("\nCHILD\n");
// 		close(pipefd[0]);
// 		dup2(pipefd[1], 1);
// 		//close(pipefd[1]);
// 		exec_cmd_node(data, prev);
// 		return (1);
// 	}
// 	waitpid(-1, 0, 0);
	return (0);
}

int		exec_cmd_node(t_data *data, t_list *cur)
{
	char **exec_line;

	exec_line = NULL;
	exec_line = ((t_cmd *)cur->content)->exec_cmd;
	if (exec_line)
	{
		ft_putstr("TEST EXEC : ");
		ft_putnbr_fd(parse_line_builtins(data, &data->env, ((t_cmd *)cur->content)->exec_cmd), data->sel->tty);
		ft_putstr("\n");
	}
	return (0);
}