/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:11 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/13 16:01:08 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

struct s_option *builtins_stat_option(void)
{
	static struct s_option s_option_tab[] = {
		{'i', 0},
		{'u', 0},
		{0, 0}
	};
	
	return (s_option_tab);
}

int builtin_env_unset(t_data *data, char **line)
{
	(void)data;
	(void)line;
	ft_putendl("UNSET");
	return (0);
}

int		builtin_env_next(t_data *data, char **line, struct s_option *s_option_tab)
{
	int		i;
	char	**tmp;

	i = 1;
	tmp = NULL;
	data->env_cpy = s_option_tab[0].set ? NULL : builtin_env_cpy(data, &data->env);
	if (s_option_tab[1].set)
		builtin_env_unset(data, line);
	while (line[i] && line[i][0] == '-')
		i++;
	while (line[i] && ft_strchr(line[i], '='))
	{
		tmp = ft_strsplit(line[i], '=');
		iter_elem_env(tmp, &data->env_cpy, &modif_elem);
		i++;
	}
	if (line[i])
		exec_parse_builtins(data, &line[i], UNFORK);
	else
		print_env(data->env_cpy);
	ft_free_char_array(&tmp);
	ft_lstdel(&data->env_cpy, &ft_free_env);
	return (1);
}

int		builtin_env(t_data *data, char **line)
{
	struct s_option *s_option_tab;

	s_option_tab = builtins_stat_option();
	builtin_opt_init(s_option_tab);
	if (builtin_parse_opt(data, line, "env", NULL) == -1)
		return (-1);
	return(builtin_env_next(data, line, s_option_tab));
}