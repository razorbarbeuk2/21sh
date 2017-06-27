/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:53:55 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/27 18:58:02 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int     free_cursor(t_data *data)
{
    if (data->sel)
		data->sel = ft_free_select(data->sel);
	if (data->entry)
		data->entry = free_data_entry(data->entry);
    return (1);
}

int 	free_destruction_final(t_data *data)
{
	if (data->env)
	{
		ft_lstdel(&data->env, &ft_free_env);
		data->env = NULL;
		ft_lstdel(&data->env_cpy, &ft_free_env);
		data->env_cpy = NULL;
	}
	if (data->cmd)
	{
		ft_lstdel_cmd(&data->cmd);
		data->cmd = NULL;
	}
	if (data->sel)
		data->sel = ft_free_select(data->sel);
	if (data->entry)
	{
		data->entry = free_data_entry(data->entry);
		data->historic = NULL;
		data->line = NULL;
	}
	if (data->historic)
		data->historic = free_data_historic(data->historic);
    if (data->term)
    {
        
    }
	
}