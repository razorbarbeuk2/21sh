/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_check_opt_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:09:07 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/20 17:51:13 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// char	*data_str_check_opt_cmd(t_cmd *cmd, char *line_str)
// {
// 	char *opt;

// 	opt = NULL;
// 	if (((line_str[0] == '-') || (line_str[0] == '-' && line_str[1] == '-')) && cmd->_select_cmd)
// 	{
// 		if (cmd->opt)
// 		{
// 			if (line_str[0] == '-' && line_str[1] != '-')
// 				opt = ft_strjoin(cmd->opt, &line_str[1]);
// 			else if (line_str[0] == '-' && line_str[1] == '-')
// 				opt = ft_strjoin(cmd->opt, &line_str[2]);
// 		}
// 		else
// 			opt = ft_strdup(line_str);
// 		ft_strdel((char **)&cmd->opt);
// 		return (opt);
// 	}
// 	return (0);
// }