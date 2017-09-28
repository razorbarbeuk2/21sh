/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:11 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/28 20:15:15 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

typedef int (*t_function_opt)(t_data *data);

struct 	s_option
{
	char 			*option;
	t_function_opt 	f;	
};

static const struct s_option s_option_tab[] = {
	{"i", builtin_env_null},
	{NULL, NULL}
};

static int	builtin_move_opt(char *line)
{
	int i;

	i = 0;
	while (line[i] == '-')
		i++;
	return (i);
}

static char *ft_concat_opt(struct s_option *t)
{
	int 	i;
	char 	*c;

	i = 0;
	c = NULL;
	while (t[i].option)
		i++;
	c = ft_memalloc(i * sizeof(char));
	i = 0;
	while (t[i].option)
	{
		c[i] = t[i].option;
		i++;
	}
	c[i] = '\0';
	return (c);
}

static int builtin_env_opt(t_data *data, char *line, char *builtins)
{
	int i;
	int n;
	int set;

	i = 0;
	n = builtin_move_opt(line);
	while (line[n])
	{
		i = 0;
		set = 0;
		while (s_option_tab[i].option)
		{
			if (ft_strcmp(s_option_tab[i].option, &line[n]) == 0)
			{
				if (s_option_tab[i].f(data) == -1)
					ft_print_error("Error Option function");
			}
			i++;
		}
		if (!set)
			return (ft_print_error_option(line[n], builtins, ft_concat_opt(s_option_tab)));
		n++;
	}
	return (0);
}


int		builtin_env(t_data *data, char **line)
{
	int		i;
	char	**tmp;

	i = 1;
	tmp = NULL;
	data->env_cpy = NULL;
	data->env_cpy = builtin_env_opt(data, line[1], "env") ? NULL : env_cpy(data);
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
	//ft_lstdel(&data->env_cpy, &ft_free_env);
	return (1);
}