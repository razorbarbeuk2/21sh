/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:41:33 by gbourson          #+#    #+#             */
/*   Updated: 2017/08/21 15:42:42 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_free_token(t_token_struct *token)
{
	token->type = 0;
    ft_strdel(&token->token_name);
    token->token_name = NULL;
    token->pos = 0;
	return ;
}

void	ft_lstdel_token(t_list **token_list)
{
	t_list	        *lst;
    t_token_struct  *token;

	lst = (*token_list);
    token = NULL;
	while (lst)
	{
        token = (t_token_struct *)lst->content;
        if(token)
            ft_free_token(token);
        lst = lst->next;
        token = NULL;
	}
	return ;
}
