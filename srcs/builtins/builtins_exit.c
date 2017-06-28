/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:15 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/28 17:14:00 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	test_param_exit(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isalpha(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int			builtin_exit(t_data *data, char **line)
{
	int i;

	i = 1;
	if (!line[i])
		exit(0);
	else if (!test_param_exit(line[1]))
		ft_putendl(ft_strcat(line[0], ": Expression Syntax."));
	else if (test_param_exit(line[1]))
	{
		ft_term_reset(data->term);
		free_destruction_final(data);
		exit(ft_atoi(line[1]));
		return (1);
	}
	return (0);
}
