/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:35:06 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/28 12:29:11 by gbourson         ###   ########.fr       */
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

int init_env_lst(t_data *data)
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

int	init_sh(t_data *data)
{
	if (!init_env_lst(data))
		return (-1);
	if (!init_paths_home_env(data))
		return (-1);
	if (!term_init(data->term))
		return (-1);
	if (!init_prompt(data))
		return (-1);
	if (!data_init_history_file(data))
		return (-1);
	listen_cursor(data, data->line);
	return (1);
}

int main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	if (!(init_struct(&data)))
	{
		ft_print_error("21 is Dead\n");
		return (0);
	}
	if (!init_sh(&data))
	{
		ft_print_error("21 is Dead\n");
		return (0);
	}
	return (0);
}
