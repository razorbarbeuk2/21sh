/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:25:35 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/14 12:10:53 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void print_lst(t_list *lst)
{
	t_list	*tmp;
	t_env	*env;

	tmp = lst;
	env = NULL;

	while (tmp)
	{
		env = (t_env *)tmp->content;
		ft_putstr(env->key);
		ft_putchar('=');
		ft_putendl(env->infos);
		tmp = tmp->next;
	}
	tmp = NULL;
}

char	**get_lst_to_tab(t_list *env_lst)
{
	char	**environ;
	t_list	*tmp_lst;
	t_env	*env;
	int		i;

	env = NULL;
	tmp_lst = NULL;
	environ = (char **)malloc(sizeof(char *) * (lst_count(env_lst) + 1));
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
	ft_lstdel(&env_lst, &free_env);
	return (environ);
}

int	get_tab_to_lst(t_list **data_env, char **environ)
{
	t_env	*env;
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	env = NULL;
	while (environ[i])
	{

		if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
			return (0);
		tmp = ft_strsplit(environ[i], '=');
		env->key = ft_strdup(tmp[0]);
		env->infos = ft_strdup(tmp[1]);
		ft_lstadd_back(data_env, ft_lstnew(env, sizeof(t_env)));
		ft_free_char(tmp);
		ft_memdel((void *)&env);
		i++;
	}
	tmp = NULL;
	environ = NULL;
	return (1);
}
