/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd_check_caract.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:22:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/30 19:23:19 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

typedef char *(*t_func_caract)(t_data *data, char *str);

struct s_caract
{
	char *caract;
	char *token;
	t_func_caract f;
};

static const struct s_caract s_caract_tab[] = {
	{"~", "HOME", env_search_infos},
	{"~/", "HOME", env_search_infos},
	{"-", "OLDPWD", env_search_infos},
	{"/", NULL, builtin_cd_special_caract_slash},
	{"..", NULL, builtin_cd_special_caract_return},
	{"../", NULL, builtin_cd_special_caract_return},
	{NULL, NULL, NULL}
};

static char *builtin_cd_parse_special_caract(t_data *data, char *line)
{
	int i;

	i = 0;
	while (s_caract_tab[i].caract)
	{
		if (ft_strcmp(s_caract_tab[i].caract, line) == 0)
			return (s_caract_tab[i].f(data, s_caract_tab[i].token));
		i++;
	}
	return (line);
}

int 	builtin_cd_check_caract(t_data *data, char **path, char **line)
{
	if (!env_search_infos(data, "OLDPWD") || !env_search_infos(data, "PWD"))
		return (ft_print_error("No PWD or OLDPWD in env\n"));
	if (!line[1])
		return (builtin_cd_special_caract_home(data, path));
	if (line[1])
	{
		(*path) = ft_strdup(builtin_cd_parse_special_caract(data, line[1]));
		return (1);
	}
	return (0);
}