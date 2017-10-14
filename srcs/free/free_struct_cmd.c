/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:41:33 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 16:48:08 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_lstdel_token(t_list **token_list)
{
    t_list	        *tmp;
    t_token_struct  *token;

    token = NULL;
	while ((*token_list))
	{
        tmp = (*token_list);
        (*token_list) = (*token_list)->next;
        token = ((t_token_struct *)tmp->content);
        ft_strdel(&token->token_name_str);
        ft_free_char_array(&token->token_name_tab);
        ft_memdel((void **)&token);
        ft_memdel((void **)&tmp);
	}
	return ;
}