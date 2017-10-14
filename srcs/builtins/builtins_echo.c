/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 14:32:16 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/14 18:50:03 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// static t_opt		*ft_opt_echo(void)
// {
// 	static t_opt opt_echo[] = {
// 		{"-n", builtin_echo_use_n},
// 		{"-e", builtin_echo_use_e},
// 		{NULL, NULL}
// 	};

// 	return ((void *)opt_echo);
// }

// int					builtin_echo_parse_opt(t_data *data, char **line, t_opt *opt)
// {
// 	int n;
// 	int i;

// 	n = 0;
// 	i = 1;
// 	while ((line[i]) && (line[i][0] == '-'))
// 	{
// 		while (opt[n].opt)
// 		{
// 			if ((ft_strcmp(line[i], opt[n].opt)) == 0)
// 			{
// 				opt[n].f(data, &line[i]);
// 				return (1);
// 			}
// 			n++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

static int			builtin_echo_var(t_data *data, char **line)
{
	char *tmp;

	if ((*line)[0] == '$')
	{
		if (!(tmp = env_search_infos(data, (*line))))
		{
			ft_print_error("No variable in env\n");
			return (-1);
		}
		else
		{
			ft_strdel(&(*line));
			(*line) = ft_strdup(tmp);
		}
	}
	tmp = NULL;
	return (1);
}

int					builtin_echo(t_data *data, char **line)
{
	int		i;
	//t_opt	*opt;

	i = 1;
	//opt = ft_opt_echo();
	while (line[i])
	{
		builtin_echo_var(data, &line[i]);
		ft_putstr(line[i]);
		if (line[i + 1])
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
	return (1);
}

// int					builtin_echo(t_data *data, char **line)
// {
// 	int		i;
// 	t_opt	*opt;

// 	i = 1;
// 	opt = ft_opt_echo();
// 	while (line[i])
// 	{
// 		builtin_echo_var(data, &line[i]);
// 		if (builtin_echo_parse_opt(data, line, opt))
// 			return (1);
// 		else
// 			ft_putstr(line[i]);
// 		ft_putchar(' ');
// 		i++;
// 	}
// 	ft_putchar('\n');
// 	return (1);
// }
