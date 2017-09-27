/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:26:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/25 17:22:26 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	ft_opt_is_in(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_opt(char *str, char *opt)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_opt_is_in(opt, str[i]) && (str[i] != '-'))
		{
			print_error("Erreur Options");
			return (0);
		}
		i++;
	}
	return (1);
}

int			get_parse_opt(char **str, char *opt)
{
	int i;

	i = 1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i][0] == '-' && (ft_strcmp(str[i], "-") != 0) \
			&& (ft_strcmp(str[i], "--") != 0))
		{
			if (!ft_opt(str[i], opt))
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
