/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:37:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/18 18:49:10 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"



int ft_token_redirection(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int size;
	int j;

	size = (*io);
	j = (*io);
	while (ft_isdigit(str[j]))
		j--;
	if (str[j] == '>' && str[j + 1] != '>')
	{
		(*type) = TYPE_REDIRECTION_LESSGREAT;
		j += 1;
	}	
	else if (str[j] == '<' && str[j + 1] != '<')
	{
		(*type) = TYPE_REDIRECTION_LESSGREAT;
		j += 1;
	}
	else if (str[j] == '>' && str[j + 1] == '&')
	{
		(*type) = TYPE_REDIRECTION_GREATAND;
		j += 2;
	}
	else if (str[j] == '<' && str[j + 1] == '&')
	{
		(*type) = TYPE_REDIRECTION_LESSAND;
		j += 2;
	}
	else if (str[j] == '>' && str[j + 1] == '>')
	{
		(*type) = TYPE_REDIRECTION_DGREAT;
		j += 2;
	}
	else if (str[j] == '<' && str[j + 1] == '<')
	{
		(*type) = TYPE_REDIRECTION_DLESS;
		j += 2;
	}
	else
		return (0);
	while (ft_isdigit(str[j]) || str[j] == '-')
		j++;
	data_check_is_token_operator(token_list, (*type), ft_strsub(str, size, j - size), j);
	(*io) = j;
	return (1);
}