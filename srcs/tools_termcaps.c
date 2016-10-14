/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:44:29 by RAZOR             #+#    #+#             */
/*   Updated: 2016/10/13 18:01:50 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int	ft_putchar_select(int c)
{
	return (write(0, &c, 1));
}

int ft_concat_int(char *buf)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (buf[i])
	{
		result = result*100 + buf[i];
		i++;
	}
	return (result);
}
