/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:30:56 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/19 16:57:34 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int init_data_env_cmd(t_data *data)
{
	data->env = NULL;
	data->env_cpy = NULL;
	data->cmd = NULL;
	data->nb_pipe = 0;
	return (1);
}

static int init_data_entry(t_data *data)
{
	data->entry = NULL;
	if (!(data->entry = (t_entry *)malloc(sizeof(t_entry))))
		return (-1);
	data->entry->line = NULL;
	data->entry->cpy = NULL;
	data->entry->cut_line = NULL;
	data->entry->line_str = NULL;
	data->entry->line_str_double = NULL;
	data->entry->len_line = 0;
	data->entry->nb_line = 0;
	return (1);
}

static int init_data_sel(t_data *data)
{
	data->sel = NULL;
	if (!(data->sel = (t_select *)malloc(sizeof(t_select))))
		return (-1);
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
	return (1);
}

int init_struct(t_data *data)
{
	if (!init_data_env_cmd(data))
		return (-1);
	if (!init_data_entry(data))
		return (-1);
	if (!init_data_sel(data))
		return (-1);
	return (1);
}