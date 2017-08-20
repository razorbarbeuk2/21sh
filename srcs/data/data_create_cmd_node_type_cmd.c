/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_node_type_cmd.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 23:50:32 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/20 17:51:45 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// static char **data_add_files_full(t_cmd *cmd_node_tmp, char *str, char **tmp)
// {
// 	int i;

// 	i = 0;
// 	while (cmd_node_tmp->files[i])
// 	{
// 		tmp[i] = ft_strdup(cmd_node_tmp->files[i]);
// 		i++;
// 	}
// 	tmp[i] = ft_strdup(str);
// 	tmp[i + 1] = NULL;
// 	ft_free_char(cmd_node_tmp->files);
// 	cmd_node_tmp->files = NULL;
// 	return (tmp);
// }

// static char **data_add_files_empty(char *str, char **tmp)
// {
// 	tmp[0] = ft_strdup(str);
// 	tmp[1] = NULL;
// 	return (tmp);
// }

// static char **data_add_files(t_cmd *cmd_node_tmp, char *str)
// {
// 	char **tmp;

// 	tmp = NULL;
// 	if (str && !cmd_node_tmp->files)
// 	{
// 		tmp = (char **)ft_memalloc(2 * sizeof(char *));
// 		return (data_add_files_empty(str, tmp));
// 	}
// 	if (str && cmd_node_tmp->files)
// 	{
// 		tmp = (char **)ft_memalloc((ft_count_tab(cmd_node_tmp->files) + 2)*sizeof(char *));
// 		return (data_add_files_full(cmd_node_tmp, str, tmp));
// 	}
// 	return (NULL);
// }

// int data_create_node_cmd(char *line_str, t_cmd **cmd_node, char **exec_cmd)
// {
// 	t_cmd *cmd_node_tmp;

// 	cmd_node_tmp = NULL;
// 	cmd_node_tmp = (*cmd_node);
// 	if (line_str)
// 	{
// 		if (line_str && !cmd_node_tmp->_select_cmd)
// 		{
// 			cmd_node_tmp->cmd = ft_strdup(line_str);
// 			cmd_node_tmp->exec_cmd = exec_cmd;
// 			cmd_node_tmp->_select_cmd = 1;
// 			return (1);
// 		}
// 		if ((cmd_node_tmp->opt = data_str_check_opt_cmd(cmd_node_tmp, line_str)) && cmd_node_tmp->_select_cmd)
// 			return (1);
// 		else
// 		{
// 			cmd_node_tmp->files = data_add_files(cmd_node_tmp, line_str);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }