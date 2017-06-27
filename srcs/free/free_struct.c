/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:03:08 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/27 18:54:12 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_select		*free_data_select(t_select *sel)
{
	if (sel)
	{
		ft_memdel((void **)&sel->pos);
		sel->pos = NULL;
		ft_memdel((void **)&sel->pos_start);
		sel->pos_start = NULL;
		ft_memdel((void **)&sel->pos_tmp);
		sel->pos_tmp = NULL;
		ft_strdel(&sel->prompt);
		sel->prompt = NULL;
	}
	return (init_data_sel(0));
}

t_entry	*free_data_entry(t_entry *entry)
{
	if (entry)
	{
		if (entry->line)
			ft_lstdel(&entry->line, &ft_free_node);
		if (entry->cpy)
			ft_lstdel(&entry->cpy, &ft_free_node);
		if (entry->cut_line)
			ft_lstdel(&entry->cut_line, &ft_free_node);
		ft_strdel(&entry->line_str);
		ft_free_char(entry->line_str_double);
		entry->line_str = NULL;
		entry->line_str_double = NULL;
	}
	entry = NULL;
	return (init_data_entry());
}

t_historic	*free_data_historic(t_historic *historic)
{
	if(historic)
	{
		historic->fd = 0;
		historic->count_pos = 0;
		historic->count_node = 0;
		ft_lstdel(&historic->list_historic, &ft_free_node);
		historic->list_historic = NULL;
	}
	return (init_data_historic());
}