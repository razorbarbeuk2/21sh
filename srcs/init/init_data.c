/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:30:56 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/02 17:04:29 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int init_data_env_cmd(t_data *data)
{
	data->env = NULL;
	data->env_cpy = NULL;
	data->token_list = NULL;
	data->entry = NULL;
	data->line = NULL;
	data->sel = NULL;
	data->historic = NULL;
	data->term = NULL;
	data->pid = 0;
	data->set_historique = 0;
	data->set_quotes = 0;
	data->nb_pipe = 0;
	data->home = NULL;
	data->paths = NULL;
	
	return (1);
}

t_quote *init_data_quotes()
{
	t_quote *init_quote;

	init_quote = NULL;
	init_quote = (t_quote *)ft_memalloc(sizeof(t_quote));
	init_quote->quote_pos = ft_memalloc(3 * sizeof(int));
	init_quote->quote = init_data_entry();
	init_quote->nb_prompt_quote = 0;

	return (init_quote);
}

t_term 	*init_term()
{
	t_term *init_term;

	init_term = NULL;
	init_term = (t_term *)ft_memalloc(sizeof(t_term));
	init_term->tty = 0;
	init_term->width = 0;
	init_term->height = 0;

	return (init_term);
}

t_entry 	*init_data_entry()
{
	t_entry *init_entry;

	init_entry = NULL;
	init_entry = (t_entry *)ft_memalloc(sizeof(t_entry));
	init_entry->line = NULL;
	init_entry->cpy = NULL;
	init_entry->cut_line = NULL;
	init_entry->line_str = NULL;
	init_entry->line_str_double = NULL;
	init_entry->nb_line = 0;
	init_entry->len_line = 0;
	init_entry->size_line = 0;

	return (init_entry);
}

t_select 	*init_data_sel()
{
	t_select *init_sel;

	init_sel = NULL;
	init_sel = (t_select *)ft_memalloc(sizeof(t_select));
	init_sel->pos = ft_memalloc(2*sizeof(int));
	init_sel->pos_start = ft_memalloc(2*sizeof(int));
	init_sel->pos_tmp = ft_memalloc(2*sizeof(int));
	init_sel->i_lst = 0;
	init_sel->i_lst_tmp = 0;
	init_sel->_bottom = 0;
	init_sel->offset = 0;
	init_sel->prompt = NULL;
	init_sel->len_prompt = 0;

	return (init_sel);
}

t_historic *init_data_hist()
{
	t_historic *init_hist;

	init_hist = NULL;
	init_hist = (t_historic *)ft_memalloc(sizeof(t_historic));
	init_hist->fd = 0;
	init_hist->count_pos = 0;
	init_hist->list_historic = NULL;
	init_hist->nb_prompt_historique = 0;
	init_hist->historique = init_data_entry();
	
	return (init_hist);
}

int init_struct(t_data *data)
{
	if (!init_data_env_cmd(data))
		return (-1);
	if (!(data->term = init_term()))
		return (-1);
	if (!(data->line = init_data_entry()))
		return (-1);
	if (!(data->quotes = init_data_quotes()))
		return (-1);
	if (!(data->historic = init_data_hist()))
		return (-1);
	if (!(data->sel = init_data_sel()))
		return (-1);
	return (1);
}