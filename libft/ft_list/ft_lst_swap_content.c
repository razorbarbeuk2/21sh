/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:55:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/20 15:31:26 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_lst_swap_content(t_list **lst)
{
	void  	*tmp;
	t_list	*st;

	st = (*lst);
	while (st->next)
	{
		tmp = st->content;
		st->content = st->next->content;
		st->next->content = tmp;
		st = st->next;
	}
	st->next = NULL;
	return ((*lst));
}