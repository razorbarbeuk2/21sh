/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_insert_caract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:47:09 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/12 18:04:16 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_del_print_caract(t_data *data, char result)
{
	(void)result;
	(void)data;
	return (1);
}

void	ft_add_at(t_list **lst, char result)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(&result);
	tmp[1] = '\0';
	ft_lstadd_back(lst, ft_lstnew(tmp, sizeof(char *)));
	ft_strdel(&tmp);
}

int		ft_add_print_caract(t_data *data, char result)
{
	int		pos;
	int		count;
	t_list	*tmp_swap;
	t_list	*tmp_lst;
	t_list	*tmp_st;

	count = 0;
	tmp_swap = NULL;
	tmp_st = NULL;
	tmp_lst = data->entry->line;
	pos = ((data->sel->pos[1] - (int)data->sel->len_prompt));
	if (result)
	{
		if (data->sel->pos[1] < ((int)data->sel->len_prompt + (int)data->entry->len_line))
		{
			tmp_swap = tmp_lst;
			while (tmp_swap && ++count < pos)
				tmp_swap = tmp_swap->next;
			tmp_st = tmp_swap->next;
			tmp_swap->next = NULL;
			ft_add_at(&tmp_swap, result);
			tmp_swap->next->next = tmp_st;
		}
		else
			ft_add_at(&tmp_lst, result);
		data->entry->line = tmp_lst;
		data->entry->len_line += 1;
	}
	return (1);
}