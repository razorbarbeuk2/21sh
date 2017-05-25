/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:27:13 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/25 21:00:16 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void 		ft_init_t_cmd(t_cmd	**cmd_node)
{
	t_cmd	*cmd_tmp;

	cmd_tmp = NULL;
	cmd_tmp = (*cmd_node);
	cmd_tmp->cmd = NULL;
	cmd_tmp->opt = NULL;
	cmd_tmp->file = NULL;
	cmd_tmp->_select_cmd = 0;
}

int		data_create_list_struct(t_data *data, char **line_str, t_cmd **cmd_node)
{
	t_cmd	*cmd_node_tmp;
	int 	i;

	i = 0;
	cmd_node_tmp = NULL;
	(void)data;
	if (!(cmd_node_tmp = (t_cmd *)malloc(sizeof(t_cmd))))
		return (0);
	ft_init_t_cmd(&cmd_node_tmp);
	while (line_str[i])
	{
		if ((ft_strcmp(line_str[i], "|") == 0) || (ft_strcmp(line_str[i], ";") == 0))
			
		else if (line_str[i] && !cmd_node_tmp->_select_cmd)
		{
			cmd_node_tmp->cmd = ft_strdup(line_str[i]);
			cmd_node_tmp->_select_cmd = 1;
		}
		else if (((line_str[i][0] == '-') || (line_str[i][0] == '-' && line_str[i][0] == '-')) && cmd_node_tmp->_select_cmd)
		{
			ft_putstr_fd("opt\n", data->sel->tty);
			cmd_node_tmp->opt = ft_strdup(line_str[i]);
		}
		else
			cmd_node_tmp->file = ft_strdup(line_str[i]);
		i++;
	}
	(*cmd_node) = cmd_node_tmp;
	ft_putstr_fd("exit\n", data->sel->tty);
	return (i);
}