/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_elem_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/11 19:59:11 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int   ft_strlen_quote_type(char *cmd, unsigned int type)
{
    int i;

    i = 1;
    while (cmd[i])
    {
        if (data_check_quote_type(cmd[i]) == type)
            return (i);
        i++;
    }
    return (0);
}

char *ft_remove_quote(char *cmd)
{
    char            *new_str;
    unsigned int    type;
    int             i;
    int             len;

    i = 0;
    len = 0;
    type = 0;
    new_str = NULL;
    while (cmd[i])
    {
        if ((type = data_check_quote_type(cmd[i])) > 0)
        {
            len = ft_strlen_quote_type(&cmd[i], type);
            N;
            ft_putnbr(len);
            N;
            i += len;
            ft_putendl(&cmd[i]);
            type = 0;
            // N;
            //len = 0;
        }
        i++;
    }
    return (NULL);
}

int ft_parse_number_in_command_quote(char *cmd)
{
    int i;

    i = 0;
    while(cmd[i])
    {
        if (data_check_quote(cmd[i]))
            ft_remove_quote(cmd);
        i++;
    }
    return (i);
}

int ft_parse_number_in_command_count_next(char *cmd, int count)
{
    if (data_check_caract(*cmd) && !data_check_caract(*(cmd + 1)))
        count++;
    else if (!data_check_caract(*cmd) && *(cmd + 1) == '\0')
        count++;
    else if (data_check_caract(*cmd) && *(cmd + 1) == '\0')
        count++;
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
        {
            i += (ft_parse_number_in_command_quote(&cmd[i]) + 1);
            count++;
        }
        else
            count = ft_parse_number_in_command_count_next(&cmd[i], count);
        i++;
    }
    return (count);
}

int ft_strlen_split(char *cmd)
{
    int i;

    i = 0;
    cmd = ft_strtrim(cmd);
    while (cmd[i])
    {
        if (data_check_quote(cmd[i]))
            return (0);
        if ((!data_check_caract(cmd[i]) && data_check_caract(cmd[i + 1])) || (!data_check_caract(cmd[i]) && cmd[i + 1] == '\0'))
            return (i);
        i++;
    }
    return (0);
}

char **ft_split_in_command(t_data *data, char *cmd)
{
    char **tab_cmd;
    int count;
    int len;
    int i;

    (void)data;
    i = 0;
    len = 0;
    tab_cmd = NULL;
    count = ft_parse_number_in_command_count(cmd);
    tab_cmd = ft_memalloc((count + 1) * sizeof(char *));
    ft_remove_quote(cmd);
    //len = ft_strlen_split(cmd);
    // while (count--)
    // {
    //     len = 
    //     tab_cmd[i] = ft_strsub();
    // }
    return (NULL);
    // if (node_content)
    // {
    //     while (count--)
    //     {
    //         len =

    //         i++;
    //     }
    // }
}