/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_redir_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:20:44 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/28 12:20:37 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int ft_token_redirection_ERROR_STRING(char j)
{
	char c[2];

	c[0] = j;
	c[1] = '\0';
	return (ft_print_parse_error(c));
}

static int ft_token_redirection_ERROR_SIMPLE_INT(char d)
{
	if (d == '>')
		return (1);
	if (d == '<')
		return (2);
	return (0);
}

int ft_token_redirection_ERROR_NEXT(char *d)
{
	if (data_check_false_caract(d + 2))
		return (ft_token_redirection_ERROR_STRING(*(d + 2)));
	return (0);
}

int ft_token_redirection_ERROR(char *d)
{
	if (data_check_false_caract(d + 1) && (*(d + 1)) != '>' && (*(d + 1)) != '&' && (ft_token_redirection_ERROR_SIMPLE_INT(*d) == 1))
		return (ft_token_redirection_ERROR_STRING((*(d + 1))));
	if (data_check_false_caract(d + 1) && (*(d + 1)) != '<' && (*(d + 1)) != '&' && (ft_token_redirection_ERROR_SIMPLE_INT(*d) == 2))
		return (ft_token_redirection_ERROR_STRING((*(d + 1))));
	return (0);
}