/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_io_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 19:48:36 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/16 17:39:25 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int ft_token_io_number(char *str, int *io, unsigned int *type, t_list **token_list)
{
    char *tmp;
	int size;
    int j;
    int p;

    tmp = NULL;
    size = (*io);
    j = (*io);
    p = 0;
    ft_putendl("\nTEST -------------");
    ft_putchar(str[j]);
    ft_putendl("\n--------------------");
    if (str[j])
    {
        while (str[j] && (ft_isdigit(str[j]) || str[j] == '-'))
            j++;
        if (j > size)
        {
            (*type) = TYPE_IO_NUMBER;
            tmp = ft_strsub(str, size, j - size);
            p = ft_strlen(tmp);
            data_check_is_token_operator(token_list, (*type), tmp, j);
            ft_strdel(&tmp);
            (*io) = j;
            return (p);
        }
    }
    return (0);
}