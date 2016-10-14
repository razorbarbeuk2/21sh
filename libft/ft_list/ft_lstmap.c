/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:25:45 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 15:58:14 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *tmp_newlst;
	t_list *start;

	tmp_newlst = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!tmp_newlst)
		{
			tmp_newlst = tmp;
			start = tmp_newlst;
			tmp_newlst->next = NULL;
		}
		else
		{
			tmp_newlst->next = tmp;
			tmp_newlst = tmp_newlst->next;
		}
		lst = lst->next;
	}
	return (start);
}
