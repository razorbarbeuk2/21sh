/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:45:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/26 13:38:58 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = NULL;
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->type = 0;
		lst->next = NULL;
		lst->prev = NULL;
		if (content)
		{
			if (!(lst->content = (void *)malloc(content_size)))
				return (NULL);
			ft_bzero(lst->content, content_size);
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
			return (lst);
		}
	}
	return (NULL);
}
