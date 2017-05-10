/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:50:33 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/12 15:54:47 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char	*get_search_infos(t_list *env, char *str)
{
	t_list *tmp;

	tmp = NULL;
	tmp = env;
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
