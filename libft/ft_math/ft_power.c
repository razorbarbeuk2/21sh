/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:33:31 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 15:58:50 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_power(int n, unsigned int pow)
{
	int tmp;

	if (pow == 0)
		return (1);
	tmp = ft_power(n, pow / 2);
	if (pow % 2 == 0)
		return (tmp * tmp);
	else
		return (n * tmp * tmp);
}
