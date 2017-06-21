/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:30:56 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/21 16:31:43 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int init_data_env_cmd(t_data *data)
{
	data->env = NULL;
	data->env_cpy = NULL;
	data->cmd = NULL;
	data->nb_pipe = 0;
	data->set_historique = 0;
	return (1);
}

t_entry 	*init_data_entry()
{
	t_entry *init_entry;

	init_entry = NULL;
	if (!(init_entry = (t_entry *)malloc(sizeof(t_entry))))
		return (NULL);
	init_entry->line = NULL;
	init_entry->cpy = NULL;
	init_entry->cut_line = NULL;
	init_entry->line_str = NULL;
	init_entry->line_str_double = NULL;
	init_entry->len_line = 0;
	init_entry->nb_line = 0;
	return (init_entry);
}

static t_select *init_data_sel()
{
	t_select *init_sel;

	init_sel = NULL;
	if (!(init_sel = (t_select *)malloc(sizeof(t_select))))
		return (NULL);
	init_sel->path_arg = NULL;
	init_sel->arg = NULL;
	init_sel->termcapbuf = NULL;
	init_sel->i_lst = 0;
	init_sel->i_lst_tmp = 0;
	init_sel->tty = 0;
	init_sel->width = 0;
	init_sel->height = 0;
	init_sel->prompt = NULL;
	init_sel->len_prompt = 0;
	init_sel->_bottom = 0;
	return (init_sel);
}

static t_historic *init_data_hist()
{
	t_historic *init_hist;

	init_hist = NULL;
	if (!(init_hist = (t_historic *)malloc(sizeof(t_historic))))
		return (NULL);
	init_hist->fd = 0;
	init_hist->count_pos = -10;
	init_hist->list_historic = NULL;
	return (init_hist);
}

int init_struct(t_data *data)
{
	if (!init_data_env_cmd(data))
		return (-1);
	if (!(data->line = init_data_entry()))
		return (-1);
	if (!(data->historique = init_data_entry()))
		return (-1);
	if (!(data->sel = init_data_sel()))
		return (-1);
	if (!(data->historic = init_data_hist()))
		return (-1);
	return (1);
}