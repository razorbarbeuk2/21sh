/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:53:55 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/28 17:22:28 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int     free_cursor(t_data *data)
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

int 	free_destruction_final(t_data *data)
{
	free_cursor(data);
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
	if (data->historic)
	{
		data->historic = free_data_historic(data->historic);
		free(data->historic);
		data->historic = NULL;
	}
    if (data->term)
    {
        
    }
	if(!data->sel)
		ft_putstr("FUCK");
	return (1);
}