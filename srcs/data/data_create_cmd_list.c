/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_cmd_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:53:58 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/23 18:07:50 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_list		*data_check_str_list_struct_node(t_data *data, void *node, int type)
{
	t_list *lst;

	lst = NULL;
	(void)data;
	if (type == TYPE_CMD)
		lst = ft_lstnew_node_type(((t_cmd *)node), sizeof(t_cmd), type);
	if (type == TYPE_SEP)
		lst = ft_lstnew_node_type(((t_sep *)node), sizeof(t_sep), type);
	return (lst);
}

void		data_check_str_list_struct_cmd_loop(t_data *data, char **line_str, int i, int size)
{
	char	**tmp;
	char	caract;
	int		type;
	void	*node;

	tmp = NULL;
	node = NULL;
	if (i == size)
		return ;
	if (i < size)
	{
		if (ft_is_caract_(line_str[i], &caract) && ft_strlen(line_str[i]) > 1)
		{
			tmp = data_split_to_tab(line_str[i], caract);
			i++;
			data_check_str_list_struct_cmd_loop(data, tmp, 0, ft_count_tab(tmp));
		}
		else
		{
			tmp = data_clean_to_tab(data, line_str[i]);
			data_create_list_struct(data, tmp, &node, &type);
			ft_lstadd_back(&data->cmd, data_check_str_list_struct_node(data, node, type));
			ft_memdel(&node);
			data_check_str_list_struct_cmd_loop(data, line_str, i + 1, size);
		}
	}
}