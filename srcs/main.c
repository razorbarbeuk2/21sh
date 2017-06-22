/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:35:06 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/22 14:05:16 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int	init_sh(t_data *data, char **env)
{

	if (!get_tab_to_lst(&data->env, env))
		return (-1);
	if (!init_paths_home_env(data))
		return (-1);
	if (!term_init(data->sel))
		return (-1);
	if (!init_pos(data))
		return (-1);
	if (!data_init_history_file(data))
		return (-1);
	listen_cursor(data, data->line);
	return (1);
	// if (!init_env(&data->env))
	// 	return (0);
}

int main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	if (!(init_struct(&data)))
	{
		print_error("21 is Dead\n");
		return (0);
	}
	if (!init_sh(&data, env))
	{
		print_error("21 is Dead\n");
		return (0);
	}
	return (0);
}
