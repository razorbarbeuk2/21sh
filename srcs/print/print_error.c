/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:07:53 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/20 16:05:00 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int 	ft_print_error_option(char c, char *usage, char *builtins)
{
	ERROR;
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
	ERROR;
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\e[0m", STDERR_FILENO);
	return (-1);
}

int		ft_print_error_access(char *str)
{
	ERROR;
	ft_putstr_fd("21sh: ", STDERR_FILENO);
	ft_putstr_fd(" permission denied: ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (-1);
}

int		ft_print_error(char *str)
{
	ERROR;
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\e[0m", STDERR_FILENO);
	return (-1);
}

int		ft_print_cmd_not_found(char *str)
{
	ERROR;
	ft_putstr_fd("21sh: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(" command not found\n", STDERR_FILENO);
	return (-1);
}

int		ft_print_parse_error(char *str)
{
	ERROR;
	ft_print_error("21sh: ");
	ft_print_error(" parse error near '");
	ft_print_error(str);
	ft_print_error("'\n");
	return (-1);
}

int		ft_print_parse_near_token(char *str)
{
	ERROR;
	ft_print_error("21sh: ");
	ft_print_error("syntax error near unexpected token `");
	ft_print_error(str);
	ft_print_error("'\n");
	return (-1);
}

int		ft_print_ambiguous_redirect(char *str)
{
	ERROR;
	ft_print_error("21sh: ");
	ft_print_error(str);
	ft_print_error(": ambiguous redirect");
	ft_print_error("\n");
	return (-1);
}