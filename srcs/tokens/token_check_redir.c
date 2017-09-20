/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:37:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/20 19:14:20 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int ft_token_redirection_LESSGREAT(char *j, unsigned int *type)
{

	if (!data_check_false_caract(j + 1))
	{
		if (*j == '>')
		{
			(*type) = TYPE_REDIRECTION_LESSGREAT_RIGHT;
			return (1);
		}
		else if (*j == '<')
		{
			(*type) = TYPE_REDIRECTION_LESSGREAT_LEFT;
			return (1);
		}
	}
	return (ft_token_redirection_ERROR(j));
}

static int ft_token_redirection_GREATAND_LESSAND(char *j, unsigned int *type)
{
	if (!data_check_false_caract(j + 2))
	{
		if (*j == '>' && (*(j + 1)) == '&')
		{
			(*type) = TYPE_REDIRECTION_GREATAND;
			return (1);
		}
		else if (*j == '<' && (*(j + 1)) == '&')
		{
			(*type) = TYPE_REDIRECTION_LESSAND;
			return (1);
		}
	}
	return (ft_token_redirection_ERROR_NEXT(j));
}

static int ft_token_redirection_DGREAT_DLESS(char *j, unsigned int *type)
{
	if (!data_check_false_caract(j + 2))
	{
		if (*j == '>' && (*(j + 1)) == '>')
		{
			(*type) = TYPE_REDIRECTION_DGREAT;
			return (1);
		}
		else if (*j == '<' && (*(j + 1)) == '<')
		{
			(*type) = TYPE_REDIRECTION_DLESS;
			return (1);
		}
	}
	return (ft_token_redirection_ERROR_NEXT(j));
}

static int ft_token_redirection_TYPE(char *str, unsigned int *type)
{
	if (ft_token_redirection_LESSGREAT(str, type))
		return (1);
	else if (ft_token_redirection_GREATAND_LESSAND(str, type))
		return (2);
	else if (ft_token_redirection_DGREAT_DLESS(str, type))
		return (2);
	else
		return (0);
}

int ft_token_redirection(char *str, int *io, unsigned int *type, t_list **token_list)
{
	int size;
	int j;

	size = (*io);
	j = (*io);
	while (ft_isdigit(str[j]))
		j--;
	j += ft_token_redirection_TYPE(&str[j], type);
	if (j > (*io))
	{
		while (ft_isdigit(str[j]) || str[j] == '-')
			j++;
		data_check_is_token_operator(token_list, (*type), ft_strsub(str, size, j - size), j);
		(*io) = j;
		return (1);
	}
	return (0);
}