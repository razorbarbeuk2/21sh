/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/28 23:41:15 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			data_exec_cmd(t_data *data)
{
	t_list *prev;
	t_list *lst;

	prev = NULL;
	lst = NULL;
	lst = data->cmd;
	while (lst)
	{
		prev = lst;
		if (lst->next && lst->next->type == TYPE_SEP && lst->next->next)
		{
			if (lst->type == TYPE_CMD && lst->next->type == TYPE_SEP && lst->next->next)
				exec_cmd_node_pipe(data, lst, lst->next->next);
		}
		else if (lst->type == TYPE_CMD)
			exec_cmd_node(data, lst);
		lst = lst->next;
		prev = NULL;
	}
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
		data_check_and_create_history_cmd(data, data->entry->line_str);
		data->entry->line_str_double = ft_strsplit(data->entry->line_str, ';');
		data_check_str_list_struct_cmd_loop(data, data->entry->line_str_double, 0, ft_count_tab(data->entry->line_str_double));
		ft_putstr_fd("\n", data->term->tty);
		data_exec_cmd(data);
	}
	if (!get_reset_prompt(data))
		print_error("Prompt error\n");
	return ;
}