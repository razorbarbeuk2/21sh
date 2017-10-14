/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_elem_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:00:37 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 12:49:07 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_parse_number_in_command_quote(char *cmd)
{
    unsigned int type;
    int i;

    i = 1;
    type = data_check_quote_type(cmd[0]);
    while(cmd[i] && (data_check_quote_type(cmd[i]) != type))   
        i++;
    return (i);
}

int ft_parse_number_in_command_count_next(char *cmd, int count)
{
    if (cmd)
    {
        if (data_check_caract(*cmd) && !data_check_caract(*(cmd + 1)))
            count++;
        else if (!data_check_caract(*cmd) && *(cmd + 1) == '\0')
            count++;
        else if (data_check_caract(*cmd) && *(cmd + 1) == '\0')
            count++;
    }
    return (count);
}

int ft_parse_number_in_command_count(char *cmd)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (cmd[i])
    {
        if (data_check_quote(cmd[i]))
            i += (ft_parse_number_in_command_quote(&cmd[i]));
        count = ft_parse_number_in_command_count_next(&cmd[i], count);
        i++;
    }
    return (count);
}