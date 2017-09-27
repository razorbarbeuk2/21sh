/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:25:35 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/27 18:58:22 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char	**get_lst_to_tab(t_list *env_lst)
{
	char	**environ;
	t_list	*tmp_lst;
	t_env	*env;
	int		i;

	env = NULL;
	tmp_lst = NULL;
	environ = (char **)ft_memalloc((ft_lst_count(env_lst) + 1)*sizeof(char *));
	tmp_lst = env_lst;
	i = 0;
	while (tmp_lst)
	{
		env = (t_env *)tmp_lst->content;
		if (env->key && ft_strlen(env->key) > 0)
		{
			if (!env->infos || ft_strlen(env->infos) == 0)
				env->infos = " ";
			environ[i] = ft_strjoin(ft_strjoin(env->key, "="), env->infos);
		}
		i++;
		tmp_lst = tmp_lst->next;
	}
	environ[i] = NULL;
	ft_lstdel(&env_lst, &ft_free_env);
	return (environ);
}

// int	get_tab_to_lst(t_list **data_env, char **environ)
// {
// 	t_env	*env;
// 	char	**tmp;
// 	int		i;

// 	i = 0;
// 	tmp = NULL;
// 	env = NULL;
// 	while (environ[i])
// 	{
// 		env = (t_env *)ft_memalloc(sizeof(t_env));
// 		tmp = ft_strsplit(environ[i], '=');
// 		env->key = ft_strdup(tmp[0]);
// 		if (!tmp[1] || ft_strlen(tmp[1]) == 0)
// 			env->infos = ft_strdup(" ");
// 		else
// 			env->infos = ft_strdup(tmp[1]);
// 		ft_lstadd_back(data_env, ft_lstnew(env, sizeof(t_env)));
// 		ft_free_char(tmp);
// 		ft_memdel((void *)&env);
// 		i++;
// 	}
// 	tmp = NULL;
// 	environ = NULL;
// 	return (1);
// }
