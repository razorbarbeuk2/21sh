/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:21:07 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/20 12:24:52 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_sep 		*init_t_sep()
{
	t_sep	*sep_tmp;

	sep_tmp = NULL;
	if (!(sep_tmp = (t_sep *)malloc(sizeof(t_sep))))
		return (NULL);
	sep_tmp->separate = NULL;
	return (sep_tmp);
}

t_cmd 		*init_t_cmd()
{
	t_cmd	*cmd_tmp;

	cmd_tmp = NULL;
	if (!(cmd_tmp = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	cmd_tmp->cmd = NULL;
	cmd_tmp->opt = NULL;
	cmd_tmp->file = NULL;
	cmd_tmp->_select_cmd = 0;
	cmd_tmp->fds.stdin = 0;
	cmd_tmp->fds.stdout = 1;
	cmd_tmp->fds.stderr = 2;
	return (cmd_tmp);
}