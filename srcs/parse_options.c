/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:26:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/29 11:38:17 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

// static int	ft_opt_is_in(char *str, char c)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int 	get_parse_opt_next(char *str, char *opt)
// {
// 	int i;
// 	int o;

// 	i = 0;
// 	while (*str == '-')
// 		str++;
// 	while (str[i] && ft_opt_is_in(str[i], opt[i]))
// 	{
// 		i++;
// 	}
// 	return (ft_print_error("Erreur Options\n"));
// }

// int			env_parse_opt(char **str, char *opt)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((str[i][0] == '-') || (str[i][0] == '-' && str[i][1] == '-'))
// 			return (ft_opt_is_in(str[i], opt));
// 		i++;
// 	}
// 	return (0);
// }
