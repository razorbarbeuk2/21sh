/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_elem_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:34:20 by RAZOR             #+#    #+#             */
/*   Updated: 2017/07/06 17:40:27 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	modif_elem_reel(char **tab_line, t_env *env)
{
	if (env && ft_strcmp(tab_line[0], env->key) == 0)
	{
		if (env->infos)
			ft_strdel(&env->infos);
		env->infos = tab_line[1] ? ft_strdup(tab_line[1]) : ft_strdup(" ");
		return (1);
	}
	return (0);
}

int			modif_elem(char **tab_line, t_list **env_lst, t_list **start)
{
	t_env	*env;
	t_list	*env_tmp;

	(void)start;
	env = NULL;
	env_tmp = *env_lst;
	if (env_tmp)
		env = ((t_env *)env_tmp->content);
	if (modif_elem_reel(tab_line, env))
		return (1);
	else if ((!env_tmp || !env_tmp->next))
	{
		env = (t_env *)ft_memalloc(sizeof(t_env));
		if (tab_line[0])
			env->key = ft_strdup(tab_line[0]);
		env->infos = tab_line[1] ? ft_strdup(tab_line[1]) : ft_strdup(" ");
		ft_lstadd_back(env_lst, ft_lstnew(env, sizeof(t_env)));
		ft_memdel((void **)&env);
		return (1);
	}
	return (0);
}
