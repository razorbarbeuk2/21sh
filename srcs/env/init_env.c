/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:15:08 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/13 18:25:12 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	init_env(t_list **env_lst)
{
	t_env	*env;
	t_list	*tmp;
	int		lvl;

	env = NULL;
	tmp = *env_lst;
	while (tmp)
	{
		env = ((t_env *)tmp->content);
		if (ft_strcmp(env->key, "SHLVL") == 0)
		{
			if (env->infos)
			{
				lvl = (ft_atoi(env->infos) + 1);
				free(env->infos);
				env->infos = ft_itoa(lvl);
			}
		}
		tmp = tmp->next;
	}
	tmp = NULL;
}
