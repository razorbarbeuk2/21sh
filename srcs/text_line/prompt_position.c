/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:55:24 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/18 19:24:22 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	ft_clean_buf_pos(t_data *data, char *buf)
{
	int 	i;
	int 	j;
	char	**tab_pos;

	i = 0;
	j = 0;
	tab_pos = NULL;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	tab_pos = ft_strsplit(&buf[i], ';');
	i = 0;
	while (tab_pos[i])
	{
		if (ft_strchr(tab_pos[i], 'R'))
		{
			while (ft_isdigit(tab_pos[i][j]))
				j++;
			tab_pos[i][j] = '\0';
		}
		data->sel->pos[i] = (ft_atoi(tab_pos[i]) - 1);
		i++;
	}
	ft_free_char_array(&tab_pos);
	tab_pos = NULL;
	return ;
}

int			get_pos_prompt(t_data *data)
{
	char	buf[10];

	ft_memset(buf, 0, 10);
	ft_bzero(buf, 10);
	ft_putstr_fd(POS, data->term->tty);
	read(data->term->tty, buf, 9);
	ft_clean_buf_pos(data, buf);
	ft_bzero(buf, 10);
	return (0);
}