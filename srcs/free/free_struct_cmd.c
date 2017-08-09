/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:41:33 by gbourson          #+#    #+#             */
/*   Updated: 2017/08/04 14:39:53 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// Quand il y a plusieurs arguments le maillon efface et remplace dans cmd->file
// test arg1 arg2 alors cmd->file = arg 1 ensuite cmd->file = arg 2 donc leaks sur arg1

void		ft_free_sep(void *tmp, size_t tmp_size)
{
	t_sep	*sep;

	sep = NULL;
	if (tmp)
	{
		sep = ((t_sep *)tmp);
		ft_strdel(&sep->separate);
		sep = NULL;
		tmp_size = 0;
	}
	return ;
}

void		ft_free_cmd(void *tmp, size_t tmp_size)
{
	t_cmd	*cmd_tmp;

	cmd_tmp = NULL;
	if (tmp)
	{
		cmd_tmp = ((t_cmd *)tmp);
		ft_strdel(&cmd_tmp->cmd);
		cmd_tmp->cmd = NULL;
		ft_strdel(&cmd_tmp->opt);
		cmd_tmp->opt = NULL;
		ft_free_char(cmd_tmp->files);
		cmd_tmp->files = NULL;
		if (cmd_tmp->exec_cmd)
		{
			ft_free_char(cmd_tmp->exec_cmd);
			cmd_tmp->exec_cmd = NULL;
		}
		cmd_tmp->_select_cmd = 0;
		tmp = NULL;
		tmp_size = 0;
	}
	free(cmd_tmp);
	cmd_tmp = NULL;
	
	return ;
}

void	ft_lstdel_cmd(t_list **alst)
{
	t_list	*tmp;
	t_list	*tmp_n;

	tmp = (*alst);
	tmp_n = NULL;
	while (tmp)
	{
		tmp_n = tmp->next;
		if (tmp->type == TYPE_CMD)
			ft_free_cmd(tmp->content, tmp->content_size);
		if (tmp->type == TYPE_PIPE)
			ft_free_sep(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp_n;
	}
	tmp = NULL;
	tmp_n = NULL;
	return ;
}
