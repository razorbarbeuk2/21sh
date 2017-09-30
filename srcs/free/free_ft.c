/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:53:55 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/30 20:08:38 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_free_char_array(char ***tmp)
{
	int i;
	char **tmp_n;

	i = 0;
	tmp_n = (*tmp);
	if (tmp_n)
	{
		while (tmp_n[i])
		{
			ft_strdel(&tmp_n[i]);
			i++;
		}
		ft_strdel_double(tmp_n);
	}
	return;
}

int free_quote(t_data *data)
{
	if (data->quotes->quote_pos[0])
	{
		data->quotes = free_data_quotes(data->quotes);
		free(data->quotes->quote);
		data->quotes->quote = NULL;
		free(data->quotes);
		data->quotes = NULL;
	}
	return (1);
}

int free_cursor(t_data *data)
{
	if (data->sel)
	{
		data->sel = free_data_select(data->sel);
		ft_free_pos(data->sel);
		free(data->sel);
		data->sel = NULL;
	}
	if (data->entry)
	{
		data->entry = free_data_entry(data->entry);
		free(data->entry);
		data->entry = NULL;
	}
	return (1);
}

int free_destruction_final(t_data *data)
{
	free_cursor(data);
	if (data->env)
	{
		ft_lstdel(&data->env, &ft_free_env);
		data->env = NULL;
		ft_lstdel(&data->env_cpy, &ft_free_env);
		data->env_cpy = NULL;
	}
	if (data->token_list)
	{
		ft_lstdel_token(&data->token_list);
		data->token_list = NULL;
	}
	if (data->historic)
	{
		data->historic = free_data_historic(data->historic);
		free(data->historic->historique);
		data->historic->historique = NULL;
		free(data->historic);
		data->historic = NULL;
	}
	if (data->term)
		term_reset(data->term);
	ft_free_char_array(&data->paths);
	return (1);
}