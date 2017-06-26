/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_insert_caract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:47:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/26 16:16:21 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char 	*ft_dup_char(char result)
{
	char *str;

	str = NULL;
	if (!(str = (char *)malloc(2*sizeof(char))))
		return (NULL);
	str[0] = result;
	str[1] = '\0';
	return (str);
}

int		ft_add_print_caract(t_data *data, char result)
{
	t_list	*tmp_lst;
	t_list	*tmp_st;
	t_list	*tmp_swap;
	char 	*str_clean;

	str_clean = NULL;
	tmp_st = NULL;
	tmp_swap = NULL;
	tmp_lst = NULL;
	tmp_lst = data->entry->line;
	data->entry->cut_line = NULL;
	tmp_st = tmp_lst;
	str_clean = ft_dup_char(result);
	if (str_clean)
	{
		if (!data->sel->i_lst)
			ft_lstadd(&tmp_lst, ft_lstnew(str_clean, ft_strlen(str_clean) + 1));
		else if ((data->sel->i_lst < (int)data->entry->len_line) && data->sel->i_lst > 0)
		{
			tmp_lst = ft_move_at_list(data, &data->entry->line, data->sel->i_lst);
			tmp_swap = tmp_lst->next;
			tmp_lst->next = NULL;
			ft_lstadd_back(&tmp_lst, ft_lstnew(str_clean, ft_strlen(str_clean) + 1));
			tmp_lst->next->next = tmp_swap;
			data->entry->cut_line = tmp_swap;
			tmp_lst = tmp_st;
		}
		else
			ft_lstadd_back(&tmp_lst, ft_lstnew(str_clean, ft_strlen(str_clean) + 1));
		data->entry->line = tmp_lst;
		data->entry->len_line++;
		ft_strdel(&str_clean);
		tmp_swap = NULL;
		tmp_lst = NULL;
		tmp_st = NULL;
	}
	return (1);
}
