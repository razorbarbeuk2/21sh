/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:30:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/30 19:46:48 by gbourson         ###   ########.fr       */
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
	//ft_putchar_fd('\n', data->term->tty);
	free_cursor(data);
	if (data->token_list)
	{
		ft_lstdel_token(&data->token_list);
		data->token_list = NULL;
	}
	if (!(data->sel = init_data_sel()))
		return (-1);
	if (!(data->line = init_data_entry()))
		return (-1);
	if (!(data->quotes = init_data_quotes()))
		return (-1);
	if (!init_prompt(data))
		return (-1);
	listen_cursor(data, data->line);
	return (1);
}

void	get_super_prompt(t_data *data)
{
	ft_putstr_fd(ORANGE, data->term->tty);
	if ((data->sel->prompt = ft_cut_path(data)) && data->home)
	{
		data->sel->offset = (ft_strlen(data->sel->prompt) - ft_strlen(data->home));
		if (data->sel->offset > 0)
		{
			ft_putstr_fd(data->sel->prompt + ft_strlen(data->home), data->term->tty);
			data->sel->len_prompt = (ft_strlen(data->sel->prompt) - ft_strlen(data->home) + 4);
		}
		else
		{
			ft_putstr_fd(data->sel->prompt, data->term->tty);
			data->sel->len_prompt = (ft_strlen(data->sel->prompt) + 4);
		}
	}
	ft_putstr_fd(" $> ", data->term->tty);
	ft_putstr_fd("\033[m", data->term->tty);
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
	ft_putstr_fd(SEARCH_COLOR, data->term->tty);
	ft_putstr_fd(tmp, data->term->tty);
	ft_putstr_fd("\033[m", data->term->tty);
	data->set_historique = ACTIVE;
	data->historic->nb_prompt_historique = ft_strlen(tmp);
	listen_cursor(data, data->historic->historique);
	ft_strdel(&tmp);
	return ;
}

void	get_quote_prompt(t_data *data)
{
	char 	*tmp;

	tmp = NULL;
	tmp = ft_strdup("quote> ");
	ft_move_home(data);
	tputs(tgoto(tgetstr("DO", NULL), 0, 0), 1, ft_putchar_select);
	tputs(tgoto(tgetstr("cr", NULL), 0, 0), 1, ft_putchar_select);
	ft_putstr_fd(tmp, data->term->tty);
	data->quotes->nb_prompt_quote = ft_strlen(tmp);
	ft_strdel(&tmp);
	return ;
}