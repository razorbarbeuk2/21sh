/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:36:51 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 15:58:44 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_countnumber(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_sign(int n)
{
	if (n <= 0)
		return (1);
	return (0);
}

static int	ft_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;
	int		r;

	i = ft_countnumber(n);
	sign = ft_sign(n);
	r = i + sign;
	if (!(str = (char *)malloc((r + 1) * sizeof(char))))
		return (NULL);
	if (str)
	{
		str[r--] = '\0';
		if (n == 0)
			str[r--] = '0';
		if (n < 0)
			str[0] = '-';
		while (n != 0)
		{
			str[r--] = ft_val(n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}
