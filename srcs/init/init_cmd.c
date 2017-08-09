/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:21:07 by gbourson          #+#    #+#             */
/*   Updated: 2017/07/06 16:47:24 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_sep 		*init_t_sep()
{
	t_sep	*sep_tmp;

	sep_tmp = NULL;
	sep_tmp = (t_sep *)ft_memalloc(sizeof(t_sep));
	sep_tmp->separate = NULL;
	return (sep_tmp);
}

t_cmd 		*init_t_cmd()
{
	t_cmd	*cmd_tmp;

	cmd_tmp = NULL;
	cmd_tmp = (t_cmd *)ft_memalloc(sizeof(t_cmd));
	cmd_tmp->cmd = NULL;
	cmd_tmp->opt = NULL;
	cmd_tmp->files = NULL;
	cmd_tmp->_select_cmd = 0;
	cmd_tmp->fds.stdin = 0;
	cmd_tmp->fds.stdout = 1;
	cmd_tmp->fds.stderr = 2;
	return (cmd_tmp);
}