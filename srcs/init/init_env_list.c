/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 19:17:06 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/29 19:20:59 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_env *init_env_lst_node(char **tmp)
{
	t_env		*env;
	
	env = NULL;
	if (tmp)
	{
		env = ft_memalloc(sizeof(t_env));
		if(tmp[0])
			env->key = ft_strdup(tmp[0]);
		env->infos = tmp[1] ? ft_strdup(tmp[1]) : ft_strdup(" ");
		return (env);
	}
	return (NULL);
}

int         init_env_lst(t_data *data)
{
	t_env		*env;
	extern char **environ;
	char 		**tmp_env;
	int 		i;

	i = 0;
	env = NULL;
	while (environ[i])
	{
		tmp_env = NULL;
		tmp_env = ft_strsplit(environ[i], '=');
		if (tmp_env)
		{	
			env = init_env_lst_node(tmp_env);
			ft_lstadd_back(&data->env, ft_lstnew(env, sizeof(t_env)));
			ft_free_char_array(&tmp_env);
			ft_memdel((void *)&env);
		}
		i++;
	}
	return (1);
}