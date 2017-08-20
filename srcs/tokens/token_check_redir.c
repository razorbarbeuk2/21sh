/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:37:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/20 16:58:08 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_is_redirection(t_list **token_list, char *line_str, int i)
{
	int size;
	unsigned int type;

	size = i;
	while (ft_isdigit(line_str[i]))
		i++;
	if (line_str[i] == '>' && line_str[i] != '>')
		type = TYPE_REDIRECTION_LESSGREAT;
	else if (line_str[i] == '<' && line_str[i] != '<')
		type = TYPE_REDIRECTION_LESSGREAT;
	else if (line_str[i] == '>' && line_str[i + 1] == '&')
	{
		type = TYPE_REDIRECTION_GREATAND;
		i += 2;
	}
	else if (line_str[i] == '<' && line_str[i + 1] == '&')
	{
		type = TYPE_REDIRECTION_LESSAND;
		i += 2;
	}
	else if (line_str[i] == '>' && line_str[i + 1] == '>')
	{
		type = TYPE_REDIRECTION_DGREAT;
		i += 2;
	}
	else if (line_str[i] == '<' && line_str[i + 1] == '<')
	{
		type = TYPE_REDIRECTION_DLESS;
		i += 2;
	}
	while (ft_isdigit(line_str[i]) || line_str[i] == '-')
		i++;
	data_check_is_token_operator(token_list, type, ft_strsub(line_str, size, i - size), i);
	return (i);
}