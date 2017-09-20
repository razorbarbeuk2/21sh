/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:07:53 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/20 14:41:30 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	print_error(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
}

void	print_cmd_not_found(char *str)
{
	print_error("21sh: ");
	print_error(str);
	print_error(" command not found");
	print_error("\n");
}

int		print_parse_error(char *str)
{
	print_error("21sh: ");
	print_error(" parse error near '");
	print_error(str);
	print_error("'");
	print_error("\n");
	return (-1);
}