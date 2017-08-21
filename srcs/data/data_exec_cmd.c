/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/21 12:20:01 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int dup_it_child(t_data *data, t_list *lst, int *save_fd, int p[2])
{
	(void)save_fd;
	close(1);
	close(p[1]);
	dup2(p[0], STDIN_FILENO);
	close(p[0]);
	return (exec_cmd_node(data, lst));
}

int dup_it_dad(t_data *data, t_list *lst, int *save_fd, int p[2])
{
	(void)save_fd;
	close(0);
	close(p[0]);
	dup2(p[1], STDOUT_FILENO);
	close(p[1]);
	return (exec_cmd_node(data, lst));
}

int 	data_exec_cmd(t_data *data)
{
	t_list *lst;

	lst = NULL;
	lst = data->token_list;
	while (lst)
	{
		// if (lst->type == TYPE_CMD)
		// 	ft_putendl((char *)(t_cmd *)lst->content->cmd);
		// if (lst->type == TYPE_PIPE)
		// 	ft_putendl((t_cmd *)lst->content->separate);
		lst = lst->next;
	}
	return (1);
}

void 	exec_cmd_character(t_data *data)
{
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			print_error("historic error\n");
		data_check_str_list_struct_cmd_loop(data, data->entry->line_str);
		data_exec_cmd(data);
	}
	if (!get_reset_prompt(data))
		print_error("Prompt error\n");
	return;
}

// ft_putendl("NEXT ---------------------");
// ft_putendl(((t_cmd *)lst->next->content)->exec_cmd[0]);
// ft_putendl("--------------------------");

// ft_putendl("FD -------------------");
// ft_putnbr(pid);
// write(1, " - ", 1);
// ft_putnbr(pfd[1]);
// write(1, " ", 1);
// ft_putnbr(pfd[0]);
// ft_putendl("\n--------------------");

// int data_exec_cmd(t_data *data)
// {
// 	t_list *prev;
// 	t_list *lst;
// 	int save_fd;
// 	int pfd[2];
// 	char **exec_line;
// 	pid_t pid;

// 	save_fd = 0;
// 	lst = NULL;
// 	lst = data->cmd;
// 	exec_line = NULL;
// 	print_list_cmd(data, data->cmd);
// 	while (lst)
// 	{
// 		ft_putendl("\nNEXT >>>>>>>>>>>>");
// 		pid = fork();
// 		if ((lst->type == TYPE_SEP) && lst->next)
// 		{
// 			pipe(pfd);
// 			if (pid == 0)
// 				dup_it_child(data, lst->next, &save_fd, pfd);
// 			else
// 				dup_it_dad(data, prev, &save_fd, pfd);
// 			save_fd = pfd[0];
// 		}
// 		if(lst->type == TYPE_CMD)
// 			prev = lst;
// 		lst = lst->next;
// 	}
// 	return (1);
// }

/*DEBUG*******************************************/
// ft_putstr("\n[-]\n");
// ft_putnbr_fd(data->sel->pos[0], data->term->tty);
// write(1, " ", 1);
// ft_putnbr_fd(data->sel->pos[1], data->term->tty);
// ft_putstr("[-]\n");
// ft_putnbr_fd(data->sel->pos_start[0], data->term->tty);
// write(1, " ", 1);
// ft_putnbr_fd(data->sel->pos_start[1], data->term->tty);
// ft_putstr("[-]\n");
/************************************************/