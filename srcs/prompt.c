/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:30:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/21 15:47:47 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	get_reset_prompt(t_data *data)
{
	ft_putstr_fd("\n", data->sel->tty);
	init_pos(data);
	return ;
}

void	get_super_prompt(t_data *data, char *line)
{
	char *tmp;

	tmp = NULL;
	ft_putstr_fd(ORANGE, data->sel->tty);
	if (data->env && get_search_infos(data->env, "PWD"))
		data->sel->prompt = ft_cut_path(data->env, line);
	else
		data->sel->prompt = ft_strdup("no pwd");
	tmp = ft_strjoin(data->sel->prompt, " $> ");
	ft_putstr_fd(tmp, data->sel->tty);
	ft_putstr_fd("\033[m", data->sel->tty);
	data->sel->len_prompt = ft_strlen(tmp);
	ft_strdel(&tmp);
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
	//tputs(tgetstr("al", NULL), 1, ft_putchar_select);

	// while (data->sel->pos[0] != data->sel->pos_start[0])
	// {
	// 	get_pos_prompt(data);
	// 	tputs(tgetstr("al", NULL), 1, ft_putchar_select);
	// 	ft_move_up(data);
	// }

	// ft_putnbr_fd(data->sel->pos[1], data->sel->tty);
	// ft_putchar_fd(':', data->sel->tty);
	// ft_putnbr_fd(data->sel->pos_start[1], data->sel->tty);

}

// static void		ft_init_get_prompt(char ***tmp_line, char ***tmp_clean, char **line)
// {
// 	*line = NULL;
// 	*tmp_line = NULL;
// 	*tmp_clean = NULL;
// }

// void			ft_listen_cmd(t_data *data)
// {
// 	char	**tmp_line;
// 	char	**tmp_clean;
// 	int		i;
// 	char	*line;


// 	ft_init_get_prompt(&tmp_line, &tmp_clean, &line);
// 	//signal(SIGINT, handler_1);
	
// 	while (get_next_line(data->sel->tty, &line))
// 	{
// 		i = 0;
// 		tmp_line = ft_strsplit(line, ';');
// 		while (tmp_line[i])
// 		{
// 			tmp_clean = ft_str_to_tab(tmp_line[i]);
// 			//ft_print_tab(data, data->cmd);
// 			//data->len_cmd = ft_strlen_each_cmd(data->cmd);
// 			parse_line_builtins(data, &data->env, tmp_clean);
// 			ft_free_char(tmp_clean);
// 			i++;
// 		}
// 		ft_free_char(tmp_line);
// 		ft_strdel(&line);
// 	}
// }
