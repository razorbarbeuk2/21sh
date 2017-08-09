/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:45:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/07/06 17:49:37 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = NULL;
	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->type = 0;
		lst->next = NULL;
		lst->prev = NULL;
		if (content)
		{
			lst->content = (void *)ft_memalloc(content_size);			
			ft_bzero(lst->content, content_size);
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
			return (lst);
		}
	}
	return (NULL);
}
