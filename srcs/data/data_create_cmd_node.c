/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:27:13 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/23 14:44:49 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		data_create_node_cmd(t_data *data, char *line_str, t_cmd **cmd_node, char **exec_cmd)
{
	t_cmd	*cmd_node_tmp;

	(void)data;
	cmd_node_tmp = (*cmd_node);
	if (line_str)
	{
		if (line_str && !cmd_node_tmp->_select_cmd)
		{
			cmd_node_tmp->cmd = ft_strdup(line_str);
			cmd_node_tmp->exec_cmd = exec_cmd;
			cmd_node_tmp->_select_cmd = 1;
			return (1);
		}
		else if (data_str_check_opt_cmd(cmd_node_tmp, line_str))
			return (1);
		else
			cmd_node_tmp->file = ft_strdup(line_str);
		return (1);
	}
	return (0);
}

int		data_create_node_separator(t_data *data, char *line_str, t_sep **sep)
{
	t_sep	*tmp_sep;

	(void)data;
	tmp_sep = (*sep);
	tmp_sep->separate = ft_strdup(line_str);
	return (1);
}

int 	parse_pipe_and_semicolumn(char *line_str)
{
	if ((ft_strcmp(line_str, "|") == 0) || (ft_strcmp(line_str, ";") == 0))
		return (1);
	return (0);
}

void		data_create_list_struct(t_data *data, char **line_str, void **node, int *t)
{
	t_cmd	*cmd_node_tmp;
	t_sep	*sep_node_tmp;
	int i;

	i = 0;
	cmd_node_tmp = NULL;
	sep_node_tmp = NULL;
	if (ft_strcmp(line_str[i], "|") == 0)
	{
		sep_node_tmp = init_t_sep();
		if (data_create_node_separator(data, line_str[i], &sep_node_tmp))
		{
			(*t) = TYPE_SEP;
			(*node) = sep_node_tmp;
			data->nb_pipe += 1;
		}
	}
	else
	{
		cmd_node_tmp = init_t_cmd();
		while (line_str[i] && !parse_pipe_and_semicolumn(line_str[i]))
		{
			if (data_create_node_cmd(data, line_str[i], &cmd_node_tmp, line_str))
			{
				(*t) = TYPE_CMD;
				(*node) = cmd_node_tmp;
			}
			i++;
		}
	}
}