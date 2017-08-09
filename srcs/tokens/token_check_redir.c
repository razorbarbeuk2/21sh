/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:37:48 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/07 16:03:19 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int     ft_is_caract_redirection(char *str)
{
    int i;

    if (i == ft_check_redirect_simple_right(str))
        return (i);
    if (i == ft_check_redirect_simple_left(str))
        return (i);
    if (i == ft_check_redirect_double_right(str))
        return (i);
    return (0);
}

int     ft_check_redirect_double_right(char *str)
{
    int i;

    i = 0;
    while (ft_isdigit(str[i]))
        i++;
    if (str[i] == '>' && str[i + 1] == '>')
    {
        i += 2;
        if (str[i] == '&' && str[i + 1] == '-')
            return (i + 2);
        if (str[i] == '&')
        {
            i++;
            while (ft_isdigit(str[i]))
                i++;
        }
        return (i);
    }
    return (0);
}

int     ft_check_redirect_simple_right(char *str)
{
    int i;

    i = 0;
    while (ft_isdigit(str[i]))
        i++;
    if (str[i] == '>')
    {
        i++;
        if (str[i] == '&' && str[i + 1] == '-')
            return (i + 2);
        if (str[i] == '&')
        {
            i++;
            while (ft_isdigit(str[i]))
                i++;
        }
        return (i);
    }
    return (0);
}

int     ft_check_redirect_simple_left(char *str)
{
    int i;

    i = 0;
    while (ft_isdigit(str[i]))
        i++;
    if (str[i] == '<')
    {
        i++;
        if (str[i] == '&' && str[i + 1] == '-')
            return (i + 2);
        if (str[i] == '&')
        {
            i++;
            while (ft_isdigit(str[i]))
                i++;
        }
        return (i);
    }
    return (0);
}