/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:17:54 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/30 18:59:23 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char 		*builtin_cd_special_caract_return(t_data *data, char *str)
{
	(void)data;
	(void)str;
	return ("..");
}

char 		*builtin_cd_special_caract_slash(t_data *data, char *str)
{
	(void)data;
	(void)str;
	return ("/");
}

int			builtin_cd_special_caract_home(t_data *data, char **path)
{
	if (((*path) = ft_strdup(env_search_infos(data, "HOME"))) == NULL)
	{
		if (data->home)
		{
			(*path) = ft_strdup(data->home);
			return (1);
		}
		return (ft_print_error("No HOME in env\n"));
	}
	return (1);
}

int			builtin_cd_move(char *path)
{
	struct stat		infos;

	if (stat(path, &infos) == -1)
		return (ft_print_move_error(path, ": No such file or directory.\n"));
	if (!S_ISDIR(infos.st_mode))
		return (ft_print_move_error(path, ": Not a directory.\n"));
	if(!chdir(path))
		return (1);
	else
		return (ft_print_error("ERROR"));
}
