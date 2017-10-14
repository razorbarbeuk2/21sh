/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_elem_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 19:26:02 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char *ft_str_remove_quote(char *cmd, char *dest)
{
    unsigned int type;
    int i;
    int j;

    i = 0;
    j = 0;
    type = 0;

    while (cmd[i])
    {
        if ((type = data_check_quote_type(cmd[i])) > 0)
        {
            i++;
            while (cmd[i] && (data_check_quote_type(cmd[i]) != type))
            {
                dest[j] = cmd[i];
                i++;
                j++;
            }
            if (cmd[i] && (!cmd[i + 1] || data_check_caract(cmd[i + 1])))
                cmd[i] = '\0';
            else
                i++;
        }
        dest[j] = cmd[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char *ft_str_remove_detect(char *cmd, int size, int status)
{
    char    *str;
    int     i;

    i = 0;
    str = NULL;
    while (cmd[i] && status)
    {
        if (data_check_quote(cmd[i]))
        {
            str = ft_memalloc((ft_strlen(cmd) - 1) * sizeof(char *));
            str = ft_str_remove_quote(cmd, str);
            return (str);
        }
        i++;
    }
    return (ft_strsub(cmd, 0, size));
}

int ft_len(char *cmd, int *status)
{
    int i;

    i = 0;
    while (cmd[i] && !data_check_caract(cmd[i]))
    {
        if (data_check_quote(cmd[i]))
        {
            i += (ft_parse_number_in_command_quote(&cmd[i]));
            *status = 1;
        }
        i++;
    }
    return (i);
}

char **ft_split_in_command(char *cmd)
{
    char **tab_cmd;
    int status;
    int count;
    int len;
    int i;

    i = 0;
    len = 0;
    status = 0;
    tab_cmd = NULL;
    count = ft_parse_number_in_command_count(cmd);
    tab_cmd = ft_memalloc((count + 1) * sizeof(char *));
    while (count--)
    {
        len = ft_len(cmd, &status);
        tab_cmd[i] = ft_str_remove_detect(cmd, len, status);
        cmd = (cmd + len + 1);
        status = 0;
        i++;
    }
    tab_cmd[i] = NULL;
    return (tab_cmd);
}