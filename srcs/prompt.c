/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:30:48 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/12 14:17:39 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_print_tab(t_data *data, char **str_tab)
{
	int i;

	i = 0;
	while(str_tab[i])
	{
		ft_putstr_fd(str_tab[i], data->sel->tty);
		i++;
	}
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
}

static void		ft_init_get_prompt(char ***tmp_line, char ***tmp_clean, char **line)
{
	*line = NULL;
	*tmp_line = NULL;
	*tmp_clean = NULL;
}

void			ft_listen_cmd(t_data *data)
{
	char	**tmp_line;
	char	**tmp_clean;
	int		i;
	char	*line;


	ft_init_get_prompt(&tmp_line, &tmp_clean, &line);
	//signal(SIGINT, handler_1);
	
	while (get_next_line(data->sel->tty, &line))
	{
		i = 0;
		tmp_line = ft_strsplit(line, ';');
		while (tmp_line[i])
		{
			tmp_clean = ft_str_to_tab(tmp_line[i]);
			//ft_print_tab(data, data->cmd);
			//data->len_cmd = ft_strlen_each_cmd(data->cmd);
			parse_line_builtins(&data->env, tmp_clean);
			ft_free_char(tmp_clean);
			i++;
		}
		ft_free_char(tmp_line);
		ft_strdel(&line);
	}
}
