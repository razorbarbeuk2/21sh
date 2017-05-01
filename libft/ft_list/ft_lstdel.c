/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:11:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/01 12:12:15 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp_n;

	tmp = *alst;
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
