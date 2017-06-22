/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list_create_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:14:11 by RAZOR             #+#    #+#             */
/*   Updated: 2017/06/22 13:24:21 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_list	*ft_lstnew_node_type(void const *content, size_t content_size, int t)
{
	t_list *lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst)
	{
		lst->next = NULL;
		if (content == NULL)
		{
			lst->content = NULL;
			lst->content_size = 0;
			lst->type = 0;
			return (lst);
		}
		if ((lst->content = (void *)malloc(content_size)) != NULL)
		{
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
			lst->type = t;
			return (lst);
		}
	}
	return (NULL);
}