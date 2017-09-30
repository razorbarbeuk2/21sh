/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:24:27 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/30 19:31:31 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"



static char **builtin_cd_init_oldpath(char ***oldpath)
{
	(*oldpath) = ft_memalloc(3 * sizeof(char *));
	(*oldpath)[0] = ft_strdup("OLDPWD");
	(*oldpath)[1] = ft_memalloc(1024 * sizeof(char *));
	getcwd((*oldpath)[1], 1024);
	return ((*oldpath));
}

char        **builtin_cd_init_path(char ***path)
{
	(*path) = ft_memalloc(3 * sizeof(char *));
	(*path)[0] = ft_strdup("PWD");
	(*path)[1] = ft_memalloc(1024 * sizeof(char *));
	return ((*path));
}

int         builtin_cd_init_paths(char ***oldpath, char ***path, char **line)
{
	if (builtins_check_args(line, 2) == -1)
		return (-1);
	(*path) = builtin_cd_init_path(oldpath);
	(*oldpath) = builtin_cd_init_oldpath(oldpath);
	return (1);
}