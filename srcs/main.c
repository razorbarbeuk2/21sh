/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:35:06 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/19 16:51:51 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void init_error(void)
{
	ft_print_error("INIT ERROR\n");
	exit(EXIT_FAILURE);
}

int	init_sh(t_data *data)
{
	if (!init_env_lst(data))
		return (-1);
	if (!init_paths_home_env(data))
		return (-1);
	if (!term_init(data->term))
		return (-1);
	if (!init_prompt(data, PROMPT))
		return (-1);
	if (!data_init_history_file(data))
		return (-1);
	if (!(data->line = init_data_entry()))
		return (-1);
	restor_data(data, SEND);
	listen_cursor(data, data->line);
	return (1);
}

int main(void)
{
	t_data	data;

	if (init_struct(&data) == -1)
		init_error();
	if (init_sh(&data) == -1)
		init_error();
	return (0);
}
