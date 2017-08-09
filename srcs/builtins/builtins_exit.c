/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:04:15 by gbourson          #+#    #+#             */
/*   Updated: 2017/07/19 17:35:01 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void end_shell(t_data *data)
{
	if (data)
	{
		add_sentence_historic_list_to_file(data);
		ft_term_reset(data->term);
		free_destruction_final(data);
	}
	return ;
}

static int test_param_exit(char *line)
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

int builtin_exit(t_data *data, char **line)
{
	int i;

	i = 1;
	if (!line[i])
	{
		end_shell(data);
		exit(0);
	}
	else if (!test_param_exit(line[1]))
		ft_putendl(ft_strcat(line[0], ": Expression Syntax."));
	else if (test_param_exit(line[1]))
	{
		end_shell(data);
		exit(ft_atoi(line[1]));
		return (1);
	}
	return (0);
}
