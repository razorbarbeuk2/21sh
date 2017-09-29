/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:11 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/29 17:44:10 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static const struct s_option s_option_tab[] = {
	{"i", builtin_env_null},
	{"u", builtin_env_unset},
	{NULL, NULL}
};

int builtin_env_null(t_data *data, char *line)
{
	(void)data;
	(void)line;
	ft_putendl("ENV NULL");
	return (0);
}

int builtin_env_unset(t_data *data, char *line)
{
	(void)data;
	(void)line;
	ft_putendl("UNSET");
	return (0);
}

int		builtin_env_next(t_data *data, char **line)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	data->env_cpy = NULL;
	builtin_parse_opt(data, line[i], "env", s_option_tab);
	while (line[i] && ft_strchr(line[i], '='))
	{
		tmp = ft_strsplit(line[i], '=');
		iter_elem_env(tmp, &data->env_cpy, &modif_elem);
		i++;
	}
	if (line[i])
		exec_parse_line_builtins(data, &line[i], UNFORK);
	else
		print_env(data->env_cpy);
	ft_free_char_array(&tmp);
	//ft_lstdel(&data->env_cpy, &ft_free_env);
	return (1);
}

int		builtin_env(t_data *data, char **line)
{
	int		i;

	i = 0;
	while (line[i] && line[i][0] == '-')
	{
		if ((builtin_parse_opt(data, line[i], "env", s_option_tab)) == -1)
			return (-1);
		i++;
	}
	return(builtin_env_next(data, &line[i]));
}