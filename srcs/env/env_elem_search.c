/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_elem_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:50:33 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/28 17:56:32 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char	*get_search_infos(t_data *data, char *str)
{
	t_list *tmp;

	tmp = NULL;
	tmp = data->env;
	if (!str)
		return (NULL);
	while (tmp)
	{
		if (ft_strcmp(((t_env *)tmp->content)->key, str) == 0)
			return (((t_env *)tmp->content)->infos);
		tmp = tmp->next;
	}
	return (NULL);
}
