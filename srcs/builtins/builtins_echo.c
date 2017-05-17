/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 14:32:16 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/17 12:01:41 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_opt		*ft_opt_echo(void)
{
	static t_opt opt_echo[] = {
		{"-n", builtin_echo_use_n},
		{"-e", builtin_echo_use_e},
		{NULL, NULL}
	};

	return ((void *)opt_echo);
}

int					builtin_echo_parse_opt(t_list *env_lst, char **line, t_opt *opt)
{
	int n;
	int i;

	n = 0;
	i = 1;
	while ((line[i]) && (line[i][0] == '-'))
	{
		while (opt[n].opt)
		{
			if ((ft_strcmp(line[i], opt[n].opt)) == 0)
			{
				opt[n].f(env_lst, &line[i]);
				return (1);
			}
			n++;
		}
		i++;
	}
	return (0);
}

static int			builtin_echo_var(char **tmp, char **str, t_list *env_lst)
{
	char *tmp_n;

	tmp_n = NULL;
	tmp_n = *tmp;
	if (tmp_n[0] == '$')
	{
		*str = ft_strsub(tmp_n, 1, ft_strlen(tmp_n) - 1);
		if (!(tmp_n = get_search_infos(env_lst, *str)))
		{
			print_error("No variable in env\n");
			ft_strdel(&tmp_n);
			ft_strdel(&*str);
			return (0);
		}
		*tmp = tmp_n;
	}
	ft_strdel(&*str);
	return (1);
}

void				builtin_echo_quote(t_list *env_lst, char **line)
{
	char		*tmp;
	char		*str;
	int			i;

	i = 0;
	tmp = NULL;
	str = NULL;
	tmp = *line;
	if (tmp)
	{
		if (tmp[0] == '"')
			tmp++;
		if (tmp[ft_strlen(tmp) - 1] == '"')
		{
			while (tmp[i] != '"' && tmp[i])
				i++;
			tmp[i] = '\0';
		}
		if (!(builtin_echo_var(&tmp, &str, env_lst)))
			return ;
		ft_strcpy(*line, tmp);
	}
	return ;
}

int					builtin_echo(t_data *data, t_list **env_lst, char **line)
{
	int		i;
	t_opt	*opt;

	(void)data;
	i = 1;
	opt = ft_opt_echo();
	while (line[i])
	{
		builtin_echo_quote(*env_lst, &line[i]);
		if (builtin_echo_parse_opt(*env_lst, line, opt))
			return (1);
		else
			ft_putstr(line[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}
