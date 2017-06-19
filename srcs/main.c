/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:35:06 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/19 15:05:34 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int init_struct(t_data *data)
{
	data->env = NULL;
	data->env_cpy = NULL;
	data->cmd = NULL;
	data->entry = NULL;
	data->sel = NULL;
	if ((data->entry = (t_entry *)malloc(sizeof(t_entry))) == NULL)
		return (0);
	if ((data->sel = (t_select *)malloc(sizeof(t_select))) == NULL)
		return (0);
	data->entry->line = NULL;
	data->entry->cpy = NULL;
	data->entry->cut_line = NULL;
	data->entry->line_str = NULL;
	data->entry->line_str_double = NULL;
	data->entry->len_line = 0;
	data->entry->nb_line = 0;
	data->sel->path_arg = NULL;
	data->sel->arg = NULL;
	data->sel->termcapbuf = NULL;
	data->sel->i_lst = 0;
	data->sel->i_lst_tmp = 0;
	data->sel->tty = 0;
	data->sel->width = 0;
	data->sel->height = 0;
	data->sel->prompt = NULL;
	data->sel->len_prompt = 0;
	data->sel->_bottom = 0;
	data->nb_pipe = 0;
	return (1);
}

int	init_sh(t_data *data, char **env)
{
	if (!get_tab_to_lst(&data->env, env))
		return (-1);

	if (!init_paths_env(data))
		return (-1);
	if (!term_init(data->sel))
		return (-1);
	listen_cursor(data);
	return (1);
	// if (!init_env(&data->env))
	// 	return (0);
}

int main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	init_struct(&data);
	if (!init_sh(&data, env))
	{
		print_cmd_not_found("21 is Dead\n");
		return (0);
	}
	return (0);
}
