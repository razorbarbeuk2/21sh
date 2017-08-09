/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:27:13 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/07 15:48:12 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int parse_pipe_and_semicolumn(char *line_str)
{
	if (ft_strcmp(line_str, "|") == 0)
		return (1);
	if (ft_strcmp(line_str, ";") == 0)
		return (2);
	return (0);
}

int data_create_node_separator(char *line_str, t_sep **sep)
{
	(*sep)->separate = ft_strdup(line_str);
	return (1);
}

void data_create_list_struct(t_data *data, char **line_str, void **node, int *t)
{
	t_cmd *cmd_node_tmp;
	t_sep *sep_node_tmp;
	int i;

	i = 0;
	cmd_node_tmp = NULL;
	sep_node_tmp = NULL;
	if (line_str[i] && parse_pipe_and_semicolumn(line_str[i]))
	{
		sep_node_tmp = init_t_sep();
		if (data_create_node_separator(line_str[i], &sep_node_tmp))
		{
			(*t) = TYPE_PIPE;
			(*node) = sep_node_tmp;
			data->nb_pipe += 1;
		}
	}
	else
	{
		cmd_node_tmp = init_t_cmd();
		while (line_str[i] && !parse_pipe_and_semicolumn(line_str[i]))
		{
			if (data_create_node_cmd(line_str[i], &cmd_node_tmp, line_str))
			{
				(*t) = TYPE_CMD;
				(*node) = cmd_node_tmp;
			}
			i++;
		}
	}
	return;
}