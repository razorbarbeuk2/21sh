/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:07:53 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/03 16:51:28 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int 	ft_print_error_option(char c, char *usage, char *builtins)
{
	ft_putstr_fd(builtins, STDERR_FILENO);
	ft_putstr_fd(": illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putstr_fd("\nusage: ", STDERR_FILENO);
	ft_putstr_fd(" [-", STDERR_FILENO);
	ft_putstr_fd(usage, STDERR_FILENO);
	ft_putstr_fd("]\n", STDERR_FILENO);
	return (-1);
}

int		ft_print_move_error(char *str, char *error)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\e[0m", STDERR_FILENO);
	return (-1);
}

int		ft_print_error(char *str)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\e[0m", STDERR_FILENO);
	return (-1);
}

int		ft_print_cmd_not_found(char *str)
{
	ft_print_error("21sh: ");
	ft_print_error(str);
	ft_print_error(" command not found\n");
	return (-1);
}

int		ft_print_parse_error(char *str)
{
	ft_print_error("21sh: ");
	ft_print_error(" parse error near '");
	ft_print_error(str);
	ft_print_error("'\n");
	return (-1);
}