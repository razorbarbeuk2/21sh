/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_clean_caract.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:06:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/08/07 16:08:34 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int ft_wordlen_clean(t_data *data, char const *s)
{
	int i;
	int c;

	i = 0;
	c = (data->quotes->quote_pos[2] - data->quotes->quote_pos[1]);
	while (s[i] && !data_check_caract(s[i]))
	{
		if (s[i] == '"' || s[i] == '\'')
			return (i += (c - 1));
		i++;
	}
	return (i);
}

static int ft_next_clean(t_data *data, char const *s, int opt, int n)
{
	int c;

	if (opt)
	{
		while (data_check_caract(s[n]) && s[n] != '\0')
			n++;
	}
	else
	{
		c = (data->quotes->quote_pos[2] - data->quotes->quote_pos[1]);
		while (s[n] && !data_check_caract(s[n]))
		{
			if (data->quotes->quote_pos[0] && (n == (data->quotes->quote_pos[1] - 1)))
				return (n += (c - 1));
			n++;
		}
	}
	return (n);
}

char **data_clean_to_tab(t_data *data, char *s)
{
	char **tab_tmp;
	int count_word;
	int i;
	int n;

	tab_tmp = NULL;
	count_word = ft_count_word_caract(data, s);
	tab_tmp = (char **)ft_memalloc((count_word + 1) * sizeof(char *));
	i = 0;
	n = 0;
	while (count_word--)
	{
		n = ft_next_clean(data, s, 1, n);
		tab_tmp[i] = ft_strsub(&s[n], data_check_quote(s[n]), ft_wordlen_clean(data, &s[n]));
		n = ft_next_clean(data, s, 0, n);
		i++;
	}
	tab_tmp[i] = NULL;
	return (tab_tmp);
}

char **data_split_to_tab(t_data *data, char *s, char *caract)
{
	char **tab_tmp;
	int count_word;
	int count;
	int len;
	int i;
	

	len = 0;
	tab_tmp = NULL;
	(void)data;
	count_word = ft_count_word_spec_caract(s, caract);
	tab_tmp = (char **)ft_memalloc((count_word + 1) * sizeof(char *));
	i = 0;
	count = 0;
	while (count_word--)
	{
		
		count = len_word_caract(s, caract);
		tab_tmp[i] = (char *)ft_memalloc((count + 1) * sizeof(char));
		tab_tmp[i] = ft_strncpy(tab_tmp[i], s, count);
		s = s + count;
		i++;
	}
	tab_tmp[i] = NULL;
	return (tab_tmp);
}