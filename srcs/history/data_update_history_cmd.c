/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_update_history_cmd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 16:09:10 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/21 12:31:44 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void write_sentence_in_historic_file(t_data *data, char *cmd, int *nb_line, int opt)
{
    if (cmd)
    {
        if (opt && nb_line)
        {
            ft_putnbr_fd(((*nb_line) + 1), data->historic->fd);
            write(data->historic->fd, " ", 1);
        }
		ft_putstr_fd(cmd, data->historic->fd);
		write(data->historic->fd, "\n", 1);
    }
    return ;
}

int add_sentence_historic_list_to_file(t_data *data)
{
    char 	*line;
    int     count;
    t_list  *tmp;

    count = 0;
	line = NULL;
    tmp = data->historic->list_historic;
	if (!(data->historic->fd = open("/tmp/log_21sh_history", (O_RDWR | O_CREAT), S_IRWXU | S_IRWXG | S_IRWXO)))
		return (-1);
	if (data->historic->fd && tmp)
    {
        // while ((get_next_line(data->historic->fd, &line)) != 0)
        //     count++;
        while (tmp)
        {
            write_sentence_in_historic_file(data, (char *)tmp->content, NULL, INACTIVE);
            tmp = tmp->next;
        }
        close(data->historic->fd);
        return (1);
    }
    return (0);
}