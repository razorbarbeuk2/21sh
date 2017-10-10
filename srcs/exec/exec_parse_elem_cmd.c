/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_elem_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:10:35 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/10 17:07:31 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char *ft_parse_number_in_command_remove_quote(char *cmd)
{
    char *str;
    int i;

    i = 0;
    str = NULL;
    if (data_check_quote(cmd[i]))
    {
        i++;
        while (cmd[i] && !data_check_quote(cmd[i]))
            i++;
        str = ft_strsub(cmd, 1, i - 1);
    }
    return (str);
}

int ft_parse_number_in_command_quote(char *cmd)
{
    int i;
    int set_quote;
    char *str;
    unsigned int QUOTE_TYPE;

    str = NULL;
    i = 0;
    QUOTE_TYPE = 0;
    set_quote = 0;
    if (cmd[i] && (QUOTE_TYPE = data_check_quote_type(cmd[i])))
    {
        i++;
        while (cmd[i] && (data_check_quote_type(cmd[i]) != QUOTE_TYPE))
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
    //tab_cmd = ft_memalloc((count + 1) * sizeof(char *));
    ft_putendl("TEST ==============");
    ft_putnbr(count);
    ft_putendl("\n===================");
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