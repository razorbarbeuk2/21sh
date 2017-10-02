/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_insert_caract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:47:09 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/02 13:27:47 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// char *ft_dup_char(char result)
// {
// 	char *str;

// 	str = NULL;
// 	if (!(str = (char *)malloc(2 * sizeof(char))))
// 		return (NULL);
// 	str[0] = result;
// 	str[1] = '\0';
// 	return (str);
// }

t_list *ft_add_print_new_node(char result)
{
	t_list *lst;

	lst = NULL;
	lst = ft_memalloc(sizeof(t_list));
	if (lst)
	{
		lst->content = NULL;
		lst->content = ft_memalloc(2 * sizeof(char));
		((char *)lst->content)[0] = result;
		((char *)lst->content)[1] = '\0';
		lst->content_size = 0;
		lst->type = 0;
		lst->next = NULL;
		lst->prev = NULL;
		lst->content_size = ft_strlen(((char *)lst->content)) + 1;
	}
	return (lst);
}

int ft_add_print_caract(t_data *data, char result)
{
	t_list *tmp_lst;
	t_list *tmp_st;
	t_list *tmp_swap;

	tmp_st = NULL;
	tmp_swap = NULL;
	tmp_lst = NULL;
	tmp_lst = data->entry->line;
	data->entry->cut_line = NULL;
	tmp_st = tmp_lst;
	if (!data->sel->i_lst)
		ft_lstadd(&tmp_lst, ft_add_print_new_node(result));
	else if (data->sel->i_lst < (int)data->entry->len_line)
	{
		tmp_lst = ft_move_at_list(data, &data->entry->line, (data->sel->i_lst - 1));
		tmp_swap = tmp_lst->next;
		tmp_lst->next = NULL;
		ft_lstadd_back(&tmp_lst, ft_add_print_new_node(result));
		tmp_lst->next->next = tmp_swap;
		data->entry->cut_line = tmp_swap;
		tmp_lst = tmp_st;
	}
	else
		ft_lstadd_back(&tmp_lst, ft_add_print_new_node(result));
	data->entry->line = tmp_lst;
	data->entry->len_line++;
	tmp_swap = NULL;
	tmp_lst = NULL;
	tmp_st = NULL;
	return (1);
}
