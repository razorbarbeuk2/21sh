/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_elem_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:29:33 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/13 17:34:58 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	del_elem_next(char **tab_line, t_list **env_lst)
{
	t_env	*env;
	t_list	*tmp;
	t_list	*prev;

	env = NULL;
	tmp = NULL;
	prev = NULL;
	prev = *env_lst;
	tmp = prev->next;
	if (prev && tmp)
	{
		env = ((t_env *)tmp->content);
		if (env && ft_strcmp(tab_line[0], env->key) == 0)
		{
			prev->next = tmp->next;
			ft_strdel(&env->key);
			ft_strdel(&env->infos);
			ft_memdel((void **)&env);
			ft_memdel((void **)&tmp);
			return ;
		}
	}
}

int			del_elem(char **tab_line, t_list **env_lst, t_list **start)
{
	t_env	*env;
	t_list	*tmp;

	env = NULL;
	tmp = NULL;
	if (tab_line[0])
	{
		tmp = *env_lst;
		env = ((t_env *)tmp->content);
		if (env && ft_strcmp(tab_line[0], env->key) == 0)
		{
			*start = tmp->next;
			return (1);
		}
		del_elem_next(tab_line, &tmp);
	}
	return (0);
}
