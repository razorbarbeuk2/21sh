/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:26:37 by gbourson          #+#    #+#             */
/*   Updated: 2016/10/11 16:06:13 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				ft_wordlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int				ft_wordcount(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		ft_next(char const *s, int opt, int n, char c)
{
	if (opt)
	{
		while (s[n] == c && s[n] != '\0')
			n++;
	}
	else
	{
		while (s[n] != c && s[n] != '\0')
			n++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbword;
	int		i;
	int		n;

	tab = NULL;
	nbword = 0;
	if (s == NULL)
		return (NULL);
	nbword = ft_wordcount((char const *)s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (nbword + 1))) == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (nbword--)
	{
		n = ft_next(s, 1, n, c);
		tab[i] = ft_strsub(&s[n], 0, ft_wordlen(&s[n], c));
		n = ft_next(s, 0, n, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
