/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:14:23 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/06 16:30:04 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static t_token_struct *build_token(void)
{
    static t_token_struct token_tab[] = {
        {TYPE_SEMICOLUMN, &is_token_semicolumn},
        {TYPE_PIPE, &is_token_pipe},
        {TYPE_AND, &is_token_and},
        {TYPE_OR, &is_token_or},
        {TYPE_FINISH, NULL},
    };

    return ((void *)token_tab);
}

int		token_drive(t_data *data)
{
	int		i;
    int     lenght;
	t_token_struct	*token_tab;

	i = 0;
    lenght = 0;
	token_tab = NULL;
	token_tab = build_token();
	while (token_tab[i].type != TYPE_FINISH)
    {
        lenght = 
    }
	return (0);
}

int     ft_check_quote_finish(char *str)
{
    int i;

    i = 0;
    while (data->entry->line_str[i])
    {
        if (data->entry->line_str[i] == '\'' || data->entry->line_str[i] == '"')
            return (i + 1);
        i++;
    }
    return (0);
}

int     main_token(t_data *data)
{
    int i;

    i = 0;
    while(data->entry->line_str[i])
    {
        while (data_check_caract(data->entry->line_str[i]))
            i++;
        if (data->entry->line_str[i] == '\'' || data->entry->line_str[i] == '"')
            i += ft_check_quote_finish(&data->entry->line_str[i]);
        i += ft_check_redir(data->entry->line_str);
        if ()
        {
            
        }
    }
    return (1);
}