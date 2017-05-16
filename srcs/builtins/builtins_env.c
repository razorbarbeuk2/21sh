/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:11 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/16 15:21:05 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_list	*ft_lst_cpy(t_list **env_lst)
{
	t_list	*start;
	t_list	*cpy;
	t_env	*env;
	t_env	*env_cpy;

	cpy = NULL;
	start = *env_lst;
	env_cpy = NULL;
	while (start)
	{
		env_cpy = (t_env *)malloc(sizeof(t_env));
		env = ((t_env *)start->content);
		if (env->key)
			env_cpy->key = ft_strdup(env->key);
		if (env->infos)
			env_cpy->infos = ft_strdup(env->infos);
		ft_lstadd_back(&cpy, ft_lstnew(env_cpy, sizeof(t_env)));
		free(env_cpy);
		env_cpy = NULL;
		start = start->next;
	}
	return (cpy);
}

int		builtin_env(t_data *data, t_list **env_lst, char **line)
{
	int		i;
	char	**tmp;
	t_list	*cpy;

	i = 1;
	cpy = NULL;
	tmp = NULL;
	cpy = get_parse_opt(line, OPT_ENV) ? NULL : ft_lst_cpy(env_lst);
	while (line[i] && line[i][0] == '-')
		i++;
	while (line[i] && ft_strchr(line[i], '='))
	{
		tmp = ft_strsplit(line[i], '=');
		iter_elem_env(tmp, &cpy, &modif_elem);
		i++;
	}
	if (line[i])
		parse_line_builtins(data, &cpy, &line[i]);
	else
		print_lst(cpy);
	ft_free_char(tmp);
	ft_lstdel(&cpy, &free_env);
	return (1);
}
