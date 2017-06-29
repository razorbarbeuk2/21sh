/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/29 17:16:58 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int data_exec_cmd(t_data *data)
{
	t_list *prev;
	t_list *lst;

	prev = NULL;
	lst = NULL;
	lst = data->cmd;
	print_list_cmd(data, data->cmd);
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

void exec_cmd_character(t_data *data)
{
	char **tmp;
	char *caract;
	int i;

	i = 0;
	tmp = NULL;
	caract = NULL;
	data->entry->line_str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			print_error("historic error\n");
		data->entry->line_str_double = ft_strsplit(data->entry->line_str, ';');
		data_check_str_list_struct_cmd_loop(data, data->entry->line_str_double, 0, ft_count_tab(data->entry->line_str_double));
		ft_putstr_fd("\n", data->term->tty);
		data_exec_cmd(data);
	}
	if (!get_reset_prompt(data))
		print_error("Prompt error\n");
	return;
}


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