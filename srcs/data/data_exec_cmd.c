/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/19 16:29:41 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			data_exec_cmd(t_data *data, t_list *cmd_list)
{
	t_list *prev;

	(void)data;
	prev = NULL;
	while (cmd_list)
	{
		prev = cmd_list;
		// ft_putstr("\nEXE*****\n");
		// ft_putstr(((t_cmd *)cmd_list->content)->cmd);
		// ft_putstr("\nEND\n");
		if (cmd_list->next && cmd_list->next->type == TYPE_SEP && cmd_list->next->next)
		{
			// if (cmd_list->type == TYPE_CMD && cmd_list->next->type == TYPE_SEP && cmd_list->next->next)
			// 	exec_cmd_node_pipe(data, cmd_list, cmd_list->next->next);
		}
		// else if (cmd_list->type == TYPE_CMD)
		// 	exec_cmd_node(data, cmd_list);
		cmd_list = cmd_list->next;
	}
	return (1);
}

void		exec_cmd_character(t_data *data)
{
	char 	*str;
	char 	**tmp;
	char 	*caract;
	int		i;
	

	i = 0;
	str = NULL;
	tmp = NULL;
	caract = NULL;
	ft_putnbr_fd(data->sel->pos[1], data->sel->tty);
	ft_putchar_fd(':', data->sel->tty);
	ft_putnbr_fd(data->sel->pos_start[1], data->sel->tty);
	// data->entry->line_str = convert_data_lst_tab(data);
	// if (data->entry->line_str_double)
	// {
	// 	ft_free_char(data->entry->line_str_double);
	// 	data->entry->line_str_double = NULL;
	// }
	// data_check_and_create_history_file(data, str);
	// data->entry->line_str_double = ft_strsplit(str, ';');
	// data_check_str_list_struct_cmd_loop(data, data->entry->line_str_double, 0, ft_count_tab(data->entry->line_str_double));
	// ft_putstr("\nGO EXEC\n");
	// ft_putstr("NB PIPE :");
	// ft_putnbr(data->nb_pipe);
	// ft_putstr("\n");
	//data_exec_cmd(data, data->cmd);
	return ;
}