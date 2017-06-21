/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/21 18:55:43 by gbourson         ###   ########.fr       */
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
			if (cmd_list->type == TYPE_CMD && cmd_list->next->type == TYPE_SEP && cmd_list->next->next)
				exec_cmd_node_pipe(data, cmd_list, cmd_list->next->next);
		}
		else if (cmd_list->type == TYPE_CMD)
			exec_cmd_node(data, cmd_list);
		cmd_list = cmd_list->next;
	}
	ft_lstdel(&data->cmd, &ft_free_cmd);
	return (1);
}

void		exec_cmd_character(t_data *data)
{
	char 	**tmp;
	char 	*caract;
	int		i;
	

	i = 0;
	tmp = NULL;
	caract = NULL;
	data->entry->line_str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		if (data->entry->line_str_double)
		{
			ft_free_char(data->entry->line_str_double);
			data->entry->line_str_double = NULL;
		}
		data_check_and_create_history_cmd(data, data->entry->line_str);
		data->entry->line_str_double = ft_strsplit(data->entry->line_str, ';');
		ft_putstr_fd("\nGETCHAR 1", data->sel->tty);
		getchar();
		data_check_str_list_struct_cmd_loop(data, data->entry->line_str_double, 0, ft_count_tab(data->entry->line_str_double));
		ft_putstr_fd("\nGETCHAR 2", data->sel->tty);
		getchar();
		ft_putstr_fd("\n", data->sel->tty);
		
		data_exec_cmd(data, data->cmd);
	}
	free_data_entry(data);
	get_reset_prompt(data);
	return ;
}