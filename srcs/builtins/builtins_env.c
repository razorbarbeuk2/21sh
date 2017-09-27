/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:11 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/27 19:43:21 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_free_char_array(char ***tmp)
{
	int 	i;
	char 	**tmp_n;

	i = 0;
	tmp_n = (*tmp);
	if (!tmp_n)
		return ;
	while (tmp_n[i])
	{
		free(tmp_n[i]);
		tmp_n[i] = NULL;
		i++;
	}
	free(tmp_n);
	tmp_n = NULL;
	return ;
}

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

static t_list	*env_cpy(t_data *data)
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

int		builtin_env(t_data *data, char **line)
{
	int		i;
	char	**tmp;

	i = 1;
	tmp = NULL;
	data->env_cpy = NULL;
	data->env_cpy = get_parse_opt(line, OPT_ENV) ? NULL : env_cpy(data);
	while (line[i] && line[i][0] == '-')
		i++;
	while (line[i] && ft_strchr(line[i], '='))
	{
		tmp = ft_strsplit(line[i], '=');
		iter_elem_env(tmp, &data->env_cpy, &modif_elem);
		i++;
	}
	if (line[i])
		parse_line_builtins(data, &data->env_cpy, &line[i]);
	else
		print_env(data->env_cpy);
	ft_free_char_array(&tmp);
	ft_lstdel(&data->env_cpy, &ft_free_env);
	return (1);
}