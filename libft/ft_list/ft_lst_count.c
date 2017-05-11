/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:45:25 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/11 16:21:27 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_lst_count(t_list *lst)
{
	t_list	*tmp;
	int 	count;

	count = 0;
	tmp = NULL;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
