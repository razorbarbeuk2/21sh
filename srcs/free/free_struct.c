/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:03:08 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/06 13:47:28 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void 	ft_free_pos(t_select *sel)
{
	ft_memdel((void **)&sel->pos);
	sel->pos = NULL;
	ft_memdel((void **)&sel->pos_start);
	sel->pos_start = NULL;
	ft_memdel((void **)&sel->pos_tmp);
	sel->pos_tmp = NULL;
}

t_select *free_data_select(t_select *sel)
{
	if (sel)
	{
		ft_free_pos(sel);
		sel->i_lst = 0;
		sel->i_lst_tmp = 0;
		sel->_bottom = 0;
		ft_strdel(&sel->prompt);
		sel->prompt = NULL;
	}
	free(sel);
	sel = NULL;
	return (init_data_sel());
}

t_entry *free_data_entry(t_entry *entry)
{
	if (entry)
	{
		
		if (entry->line)
			ft_lstdel(&entry->line, &ft_free_node);
		if (entry->cpy)
			ft_lstdel(&entry->cpy, &ft_free_node);
		if (entry->line_str)
			ft_strdel(&entry->line_str);
		//ft_free_char(entry->line_str_double);
		entry->line_str = NULL;
		entry->line_str_double = NULL;
		entry->nb_line = 0;
		entry->len_line = 0;
		entry->size_line = 0;
	}
	entry = NULL;
	return (init_data_entry());
}

t_historic *free_data_historic(t_historic *historic)
{
	if (historic)
	{
		historic->fd = 0;
		historic->count_pos = 0;
		historic->count_node = 0;
		ft_lstdel(&historic->list_historic, &ft_free_node);
		historic->list_historic = NULL;
		historic->historique = free_data_entry(historic->historique);
	}
	return (init_data_hist());
}

t_quote *free_data_quotes(t_quote *quotes)
{
	if (quotes)
	{
		ft_memdel((void **)&quotes->quote_pos);
		quotes->quote_pos = NULL;
		quotes->nb_prompt_quote = 0;
		quotes->quote = free_data_entry(quotes->quote);
	}
	return (init_data_quotes());
}