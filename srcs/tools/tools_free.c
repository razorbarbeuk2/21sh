/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:42:06 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/13 12:41:39 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

/*A REFAIRE*/
char	*ft_cut_path(t_list *env_lst, char *line)
{
	char	*pwd;
	char	*home;

	(void)line;
	pwd = NULL;
	home = NULL;
	if (!(pwd = get_search_infos(env_lst, "PWD")))
		pwd = " ";
	if (!(home = get_search_infos(env_lst, "HOME")))
		home = " ";
	if ((ft_strlen(pwd) > ft_strlen(home)))
	{
		return (ft_strsub(pwd, ft_strlen(home), ft_strlen(pwd) - \
		ft_strlen(home)));
	}
	else if ((ft_strcmp(pwd, home)) == 0)
		return (ft_strdup("~"));
	else if ((ft_strcmp(pwd, "/")) == 0)
		return (ft_strdup("/"));
	else
		return (ft_strdup(pwd));
}

void	ft_free_char(char **tmp)
{
	int i;

	i = 0;
	if (!tmp)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;
}

void		free_env(void *tmp, size_t tmp_size)
{
	t_env	*env;

	env = NULL;
	env = ((t_env *)tmp);
	if (env->key)
		ft_strdel(&env->key);
	if (env->infos)
		ft_strdel(&env->infos);
	ft_memdel((void **)&env);
	tmp_size = 0;
}

void		ft_free_tab_path(char **oldpath, char **path)
{
	ft_strdel(&path[0]);
	ft_strdel(&path[1]);
	ft_strdel_double(path);
	ft_strdel(&oldpath[0]);
	ft_strdel(&oldpath[1]);
	ft_strdel_double(oldpath);
	return ;
}
