/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_elem_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:36:04 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/01 20:55:40 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			iter_elem_env(char **tab_line, t_list **env_lst, int (*f)(char **t, t_list **e, t_list **s))
{
	t_list	*cpy;

	cpy = NULL;
	cpy = (*env_lst);
	if (!cpy && tab_line)
	{
		f(tab_line, env_lst, env_lst);
		return (1);
	}
	while (cpy)
	{
		if (f(tab_line, &cpy, env_lst))
			return (1);
		cpy = cpy->next;
	}
	return (0);
}
