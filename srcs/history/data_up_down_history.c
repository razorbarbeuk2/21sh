/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_up_down_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:17:19 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/21 16:21:46 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char			*ft_search_up_down_historic(t_data *data, int count_pos)
{
	char 		*tmp;
	t_list		*lst;

	tmp = NULL;
	lst = NULL;
	lst = data->historic->list_historic;
	while (lst)
	{
		tmp = (char *)lst->content;
		if (ft_atoi(&tmp[0]) == count_pos)
			return (ft_strchr(tmp, ' ') + 1);
		lst = lst->next;
		tmp = NULL;
	}
	return (NULL);
}

void			ft_insert_cmd_to_prompt(t_data *data, char *s)
{
	int i;

	i = 0;
	reset_line(data);
	while (s[i])
	{
		print_character(data, s[i]);
		i++;
	}
	return ;
}

int				ft_move_up_down_historic(t_data *data, int result)
{
	char  		*tmp;
	
	tmp = NULL;
	if (data->historic->list_historic)
	{
		ft_move_home(data);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_select);
		if (result == DOWN && data->historic->count_pos < data->historic->count_node)
			data->historic->count_pos++;
		tmp = ft_search_up_down_historic(data, data->historic->count_pos);
		if (tmp)
			ft_insert_cmd_to_prompt(data, tmp);
		if (result == UP && data->historic->count_pos > 0)
			data->historic->count_pos--;
	}
	return (0);
}

