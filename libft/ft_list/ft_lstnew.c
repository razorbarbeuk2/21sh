/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:45:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/01 13:40:59 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *str;

	str = (t_list *)malloc(sizeof(t_list));
	if (str)
	{
		str->next = NULL;
		if (content == NULL)
		{
			str->content = NULL;
			str->content_size = 0;
			return (str);
		}
		if ((str->content = (void *)malloc(content_size)) != NULL)
		{
			ft_memcpy(str->content, content, content_size);
			str->content_size = content_size;
			return (str);
		}
	}
	return (NULL);
}
