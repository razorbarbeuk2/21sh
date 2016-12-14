/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:35:06 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/13 16:22:56 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int init_struct(t_data *data)
{
	data->env = NULL;
	data->entry = NULL;
	data->sel = NULL;
	if ((data->entry = (t_entry *)malloc(sizeof(t_entry))) == NULL)
		return (0);
	if ((data->sel = (t_select *)malloc(sizeof(t_select))) == NULL)
		return (0);
	data->entry->line = NULL;
	data->sel->path_arg = NULL;
	data->sel->arg = NULL;
	data->sel->termcapbuf = NULL;
	data->sel->tty = 0;
	data->sel->width = 0;
	data->sel->height = 0;
	return (1);
}

int	init_sh(t_data *data, char **env)
{
	if (!get_tab_to_lst(&data->env, env))
		return (0);
	term_init(data->sel);
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
		return (0);
	return (0);
}
