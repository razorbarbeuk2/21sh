/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_envcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 18:35:37 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/01 17:43:38 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_env	*env_cpy_node(t_list *env_node)
{
	t_env  	*env_cpy;
	t_env  	*env_struct;

	env_struct = NULL;
	if (env_node)
	{
		env_struct = (t_env *)env_node->content;
		env_cpy = ft_memalloc(sizeof(t_env));
		if(env_struct->key)
			env_cpy->key = ft_strdup(env_struct->key);
		env_cpy->infos = env_struct->infos ? ft_strdup(env_struct->infos) : ft_strdup(" ");
		return (env_cpy);
	}
	return (NULL);
}

t_list	*builtin_env_cpy(t_data *data)
{
	t_list	*env;
	t_env  	*env_cpy;
	t_list	*env_cpy_lst;

	env = NULL;
	env_cpy_lst = NULL;
	env = data->env;
	while (env)
	{
		env_cpy = NULL;
		if (env)
		{
			env_cpy = env_cpy_node(env);
			ft_lstadd_back(&env_cpy_lst, ft_lstnew(env_cpy, sizeof(t_env)));
			ft_memdel((void *)&env_cpy);
		}
		env = env->next;
	}
	return (env_cpy_lst);
}