/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_check_opt_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:09:07 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/30 18:24:52 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		data_str_check_opt_cmd(t_cmd *cmd, char *line_str)
{
	if (((line_str[0] == '-') || (line_str[0] == '-' && line_str[1] == '-')) && cmd->_select_cmd)
	{
		if (cmd->opt)
		{
			if (line_str[0] == '-' && line_str[1] != '-')
				cmd->opt = ft_strjoin(cmd->opt, &line_str[1]);
			else if (line_str[0] == '-' && line_str[1] == '-')
				cmd->opt = ft_strjoin(cmd->opt, &line_str[2]);
			else
				return (0);
		}
		else
			cmd->opt = ft_strdup(line_str);
	}
	return (0);
}