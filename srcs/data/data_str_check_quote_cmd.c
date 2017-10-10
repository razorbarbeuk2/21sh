/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_check_quote_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:12:28 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/10 18:30:32 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int check_quote_and_double_quote_result(char s)
{
    if (s == '\'')
        return (QUOTE_SIMPLE);
    if (s == '"')
        return (QUOTE_DOUBLE);
    return (0);
}

int check_quote_and_double_quote(t_list *line, int set_quote)
{
    char         c;
    
    while (line)
    {
        c = ((char *)line->content)[0]; 
        if (check_quote_and_double_quote_result(c) == set_quote)
            return (1);
        line = line->next;
    }
    return (0);
}

int parse_quote_and_double_quote(t_data *data, t_list *line)
{
    int          set_quote;
    char         c;

    set_quote = 0;
    if (line)
    {
        while (line)
        {
            c = ((char *)line->content)[0];
            if ((set_quote = check_quote_and_double_quote_result(c)) != 0)
            {
                if (check_quote_and_double_quote(line->next, set_quote))
                {
                    data->quotes = free_data_quotes(data->quotes);
                    data->set_quotes = INACTIVE;
                    set_quote = 0;
                }
                else
                {
                    data->set_quotes = ACTIVE;
                    data->quotes = init_data_quotes();
                    get_quote_prompt(data);
                    listen_cursor(data, data->line);
                }
            }
            line = line->next;
        }
    }
    return (0);
}