/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:30:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/26 17:31:09 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char	*ft_cut_path(t_data *data)
{
	data->sel->prompt = NULL;
	data->sel->prompt = ft_memalloc(1024);
	if (data->env && data->sel->prompt && getcwd(data->sel->prompt, 1024))
	{
		if ((ft_strlen(data->sel->prompt) > ft_strlen(data->home)))
			return (data->sel->prompt);
		return (data->sel->prompt);
	}
	return ("no pwd");
}

int		get_reset_prompt(t_data *data)
{
	ft_putstr_fd("\n", data->sel->tty);
	if (data->sel)
		ft_free_select(data);
	if (data->entry)
		free_data_entry(data);
	if (data->cmd)
		ft_lstdel_cmd(&data->cmd);
	if (!init_pos(data))
		return (-1);
	listen_cursor(data, data->line);
	return (1);
}

void	get_super_prompt(t_data *data)
{
	ft_putstr_fd(ORANGE, data->sel->tty);
	if ((data->sel->prompt = ft_cut_path(data)))
	{
		if (data->home)
		{
			ft_putstr_fd(data->sel->prompt + ft_strlen(data->home), data->sel->tty);
			data->sel->len_prompt = (ft_strlen(data->sel->prompt) - ft_strlen(data->home) + 4);
		}
		else
		{
			ft_putstr_fd(data->sel->prompt, data->sel->tty);
			data->sel->len_prompt = (ft_strlen(data->sel->prompt) + 4);
		}
	}
	ft_putstr_fd(" $> ", data->sel->tty);
	ft_putstr_fd("\033[m", data->sel->tty);
	//printf("%zu%p\n", data->sel->len_prompt, &data->sel->len_prompt);
	//0x100003040
	return ;
}

void	get_hist_prompt(t_data *data)
{
	char 	*tmp;

	tmp = NULL;
	tmp = ft_strdup("SEARCH HISTORIC : ");
	ft_move_home(data);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
	tputs(tgoto(tgetstr("DO", NULL), 0, 0), 1, ft_putchar_select);
	tputs(tgoto(tgetstr("cr", NULL), 0, 0), 1, ft_putchar_select);
	ft_putstr_fd(SEARCH_COLOR, data->sel->tty);
	ft_putstr_fd(tmp, data->sel->tty);
	ft_putstr_fd("\033[m", data->sel->tty);
	data->set_historique = 1;
	data->nb_prompt_historique = ft_strlen(tmp);
	listen_cursor(data, data->historique);
	ft_strdel(&tmp);
	return ;
}