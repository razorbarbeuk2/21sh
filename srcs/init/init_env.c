/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:15:08 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/28 14:12:50 by gbourson         ###   ########.fr       */
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

int		init_paths_home_env(t_data *data)
{
	char *tmpstr;

	tmpstr = NULL;
	if (data->env && (tmpstr = get_search_infos(data, "PATH")))
	{
		data->home = ft_strdup(get_search_infos(data, "HOME"));
		data->paths = ft_strsplit(tmpstr, ':');
		return (1);
	}
	return (-1);
}
