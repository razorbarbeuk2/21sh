/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:34:08 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/28 12:05:24 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int builtins_check_args(char **line, int num)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    if (i > num)
        return (ft_print_error("Too many arguments."));
    return (1);
}