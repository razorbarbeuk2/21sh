/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:11:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/02 21:00:26 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp_n;

	tmp = NULL;
	tmp = (*alst);
	if (tmp)
	{
		while (tmp)
		{
			tmp_n = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = tmp_n;
		}
		*alst = NULL;
		tmp = NULL;
		tmp_n = NULL;
	}
	return ;
}
