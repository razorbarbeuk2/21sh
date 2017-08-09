/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_history_files.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:35:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/07/20 17:29:58 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		data_uptdate_count_history_file(t_data *data)
{
	data->historic->count_node = ft_lst_count(data->historic->list_historic);
	data->historic->count_pos = data->historic->count_node;
}

int			data_init_history_file(t_data *data)
{
	char 	*line;

	line = NULL;
	if (!(data->historic->fd = open("/tmp/log_21sh_history", (O_RDWR | O_CREAT), S_IRWXU | S_IRWXG | S_IRWXO)))
		return (-1);
	if (data->historic->fd)
	{
		while ((get_next_line(data->historic->fd, &line)) != 0)
		{	
			ft_lstadd_back(&data->historic->list_historic, ft_lstnew(line, ft_strlen(line) + 1));
			ft_strdel(&line);
			line = NULL;
		}
		close(data->historic->fd);
	}
	ft_strdel(&line);
	data_uptdate_count_history_file(data);
	return (1);
}
