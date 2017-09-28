/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:17:54 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/28 16:39:21 by gbourson         ###   ########.fr       */
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
	if (!get_search_infos(data, "HOME"))
		return (ft_print_error("No HOME in env"));
	(*path) = ft_strdup(get_search_infos(data, "HOME"));
	return (1);
}

int			ft_check_move(char *path)
{
	struct stat		infos;

	if (stat(path, &infos) == -1)
		return (ft_print_move_error(path, ": No such file or directory."));
	if (!S_ISDIR(infos.st_mode))
		return (ft_print_move_error(path, ": Not a directory."));
	if(!chdir(path))
		return (1);
	else
		return (ft_print_error("ERROR"));
}
