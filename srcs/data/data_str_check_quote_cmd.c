/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_check_quote_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:12:28 by RAZOR             #+#    #+#             */
/*   Updated: 2017/07/18 18:41:14 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int check_quote_and_doucle_quote(char s)
{
    if (s == '\'')
        return (QUOTE_SIMPLE);
    if (s == '"')
        return (QUOTE_DOUBLE);
    return (0);
}

int parse_quote_and_double_quote_set(t_data *data, t_list *lst)
{
    char c;
    int count;

    count = 0;
    while (lst)
    {
        c = ((char *)lst->content)[0];
        if ((data->quotes->quote_pos[0] = check_quote_and_doucle_quote(c)) && !data->quotes->quote_pos[1])
            data->quotes->quote_pos[1] = count;
        else if (check_quote_and_doucle_quote(c) && (count > data->quotes->quote_pos[1]))
        {
            data->quotes->quote_pos[2] = count;
            data->set_quotes = INACTIVE;
            return (1);
        }
        count++;
        lst = lst->next;
    }
    if (data->quotes->quote_pos[1] && !data->quotes->quote_pos[2])
    {
        data->set_quotes = ACTIVE;
        get_quote_prompt(data);
        listen_cursor(data, data->line);
        
    }
    return (1);
}

int parse_quote_and_double_quote(t_data *data)
{
    t_list *lst;
    
    lst = NULL;
    lst = data->entry->line;
    if (data->entry->len_line)
        parse_quote_and_double_quote_set(data, lst);
    return (0);
}