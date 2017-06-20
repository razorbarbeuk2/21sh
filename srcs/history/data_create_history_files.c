/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_history_files.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:35:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/20 17:32:36 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			data_init_history_file(t_data *data)
{
	char 	*line;

	line = NULL;
	if (!(data->historic->fd = open("/tmp/log_21sh_history", (O_RDWR | O_CREAT), S_IRWXU | S_IRWXG | S_IRWXO)))
		return (-1);
	if (data->historic->fd)
	{
		while ((get_next_line(data->historic->fd, &line)))
		{
			ft_lstadd(&data->historic->list_historic, ft_lstnew(line, ft_strlen(line) + 1));
			ft_strdel(&line);
			line = NULL;
		}
		close(data->historic->fd);
	}
	data->historic->count_node = ft_lst_count(data->historic->list_historic);
	return (1);
}

// int			data_check_and_create_history_file(t_data *data, char *cmd)
// {
// 	char 	*line;

// 	fd = data_open_history_file(1);
// 	if (fd && cmd)
// 	{
// 		while ((get_next_line(fd, &line) != 0))
// 			nb_line++;
// 		ft_putnbr_fd(nb_line + 1, fd);
// 		write(fd, " ", 1);
// 		ft_putstr_fd(cmd, fd);
// 		write(fd, "\n", 1);
// 		close(fd);
// 	}
// 	return (1);
// }

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
