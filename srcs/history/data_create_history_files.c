/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_history_files.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:35:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/21 15:29:35 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		data_uptdate_count_history_file(t_data *data)
{
	data->historic->count_node = ft_lst_count(data->historic->list_historic);
	data->historic->count_pos = (data->historic->count_node);
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
			ft_lstadd(&data->historic->list_historic, ft_lstnew(line, ft_strlen(line) + 1));
			ft_strdel(&line);
			line = NULL;
		}
		close(data->historic->fd);
	}
	data_uptdate_count_history_file(data);
	return (1);
}

int			data_check_and_create_history_cmd(t_data *data, char *cmd)
{
	char 	*line;
	int 	nb_line;

	line = NULL;
	nb_line = 0;
	if (!(data->historic->fd = open("/tmp/log_21sh_history", O_RDWR)))
		return (-1);
	if (data->historic->fd && cmd)
	{
		while ((get_next_line(data->historic->fd, &line) != 0))
		{
			nb_line++;
			ft_strdel(&line);
			line = NULL;
		}
		ft_putnbr_fd((nb_line + 1), data->historic->fd);
		write(data->historic->fd, " ", 1);
		ft_putstr_fd(cmd, data->historic->fd);
		write(data->historic->fd, "\n", 1);
		close(data->historic->fd);
	}
	ft_lstdel(&data->historic->list_historic, &ft_free_node);
	data_init_history_file(data);
	return (1);
}

// int			data_search_in_history_file(t_data *data, char *search_cmd)
// {
// 	int		fd;
// 	char 	*line;
// 	int		nb_line;

// 	(void)data;
// 	fd = 0;
// 	nb_line = 0;
// 	line = NULL;
// 	fd = data_open_history_file(2);
// 	if (fd)
// 	{
// 		while (get_next_line(fd, &line))
// 		{
// 			if (ft_strcmp(line, search_cmd) == 0)
// 				break ;
// 			else
// 				print_error("No result\n");
// 			nb_line++;
// 		}
// 		close(fd);
// 	}
// 	return (1);
// }
