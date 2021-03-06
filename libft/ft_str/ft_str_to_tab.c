/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:47:18 by qdequele          #+#    #+#             */
/*   Updated: 2016/10/11 16:00:42 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t		ft_count_words(const char *s)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t') &&
			s[i] != ' ' && s[i] != '\t')
			words++;
		i++;
	}
	return (words);
}

static size_t		ft_word_len(char const *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			s++;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

char				**ft_str_to_tab(char const *s)
{
	char	**word_tab;
	size_t	nb_words;
	size_t	word_len;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	nb_words = ft_count_words(s);
	word_tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
	while (n < nb_words && word_tab)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		word_len = ft_word_len(&s[i]);
		word_tab[n] = malloc(sizeof(**word_tab) * (word_len + 1));
		ft_strncpy(word_tab[n], &s[i], word_len);
		word_tab[n][word_len] = '\0';
		while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
			i++;
		n++;
	}
	word_tab[n] = NULL;
	return (word_tab);
}
