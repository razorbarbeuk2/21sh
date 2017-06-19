/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_history_files.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:35:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/16 18:54:00 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			data_open_history_file(int opt)
{
	int		fd;

	fd = 0;
	if (!(fd = open("/tmp/log_21sh_history", (O_RDWR | O_CREAT), S_IRWXU | S_IRWXG | S_IRWXO)))
		return (-1);
	return (fd);
}

int			data_check_and_create_history_file(t_data *data, char *cmd)
{
	
	char 	*line;
	int		nb_line;

	(void)data;
	
	nb_line = 0;
	line = NULL;
	
	if (fd)
	{
		while ((get_next_line(fd, &line) != 0))
			nb_line++;
		ft_putstr_fd(cmd, fd);
		write(fd, "\n", 1);
		close(fd);
	}
	return (1);
}

int			data_search_in_history_file(t_data *data, char *search_cmd)
{
	int		fd;
	char 	*line;
	int		nb_line;

	(void)data;
	fd = 0;
	nb_line = 0;
	line = NULL;
	if (!(fd = open("/tmp/log_21sh_history", (O_RDWR))))
		return (-1);
	if (fd)
	{
		while (get_next_line(fd, &line))
		{
			if (ft_strcmp(line, search_cmd) == 0)
				break ;
			else
				ft_putstr_fd("No result\n");
			nb_line++;
		}
		close(fd);
	}
	return (1);
}

