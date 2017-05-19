/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_clean_caract.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:06:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/19 17:19:13 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int 		data_check_caract(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

int 		data_check_spec_caract(char c, char *caract)
{
	if (c == caract[0])
		return (1);
	return (0);
}


int			ft_count_word_spec_caract(char *line_str, char *caract)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line_str[i])
	{
		if (!data_check_spec_caract(line_str[i], caract) && data_check_spec_caract(line_str[i + 1], caract))
			count++;
		else if (data_check_spec_caract(line_str[i], caract))
			count++;
		else if ((!data_check_spec_caract(line_str[i], caract)) && line_str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

int			len_word_caract(char *line_str, char *caract)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (line_str[0] == caract[0])
	{
		while(line_str[i] == caract[0])
			i++;
		return (i);
	}
	else
	{
		while (line_str[i] && (line_str[i] != caract[0]))
			i++;
		return (i);
	}
	return (0);
}

char 		*convert_data_lst_tab(t_data *data)
{
	char 	*str;
	t_list	*lst;
	int 	i;

	i = 0;
	lst = NULL;
	lst = data->entry->line;
	if (!(str = (char *)malloc((data->entry->len_line + 1)*sizeof(char))))
		return (NULL);
	while(lst)
	{
		str[i] = ((char *)lst->content)[0];
		lst = lst->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char 		**data_clean_to_tab(t_data *data, char *str)
{
	char 	**tab_tmp;
	char 	**st_tmp;
	int		count_word;
	int		i;

	i = 0;
	(void)data;
	tab_tmp = NULL;
	st_tmp = NULL;
	str = trim_str(str);
	count_word = ft_count_word_caract(str);
	if (!(tab_tmp = (char **)malloc((count_word + 1)*sizeof(char *))))
		return (NULL);
	st_tmp = tab_tmp;
	while(count_word--)
	{
		while(data_check_caract(str[i]) && str[i])
			i++;
		if (!(*tab_tmp = (char *)malloc((len_word(&str[i]) + 1)*sizeof(char))))
			return (NULL);
		*tab_tmp = ft_strcpy_data(*tab_tmp, &str[i]);
		str = str + len_word(&str[i]);
		tab_tmp++;
	}
	*tab_tmp = NULL;
	tab_tmp = st_tmp;
	return (tab_tmp);
}

char 		**data_split_to_tab(char *line_str, char *caract)
{
	char 	**tab_tmp;
	char 	**st;
	int		count_word;
	int		i;

	tab_tmp = NULL;
	st = NULL;
	i = 0;
	count_word = 0;
	count_word = ft_count_word_spec_caract(line_str, caract);
	if (!(tab_tmp = (char **)malloc((count_word + 1)*sizeof(char *))))
		return (NULL);
	st = tab_tmp;
	while (count_word--)
	{
		if (!data_check_spec_caract(line_str[i], caract))
		{
			while(line_str[i] && !data_check_spec_caract(line_str[i], caract))
				i++;
		}
		else if (data_check_spec_caract(line_str[i], caract))
		{
			while(line_str[i] && data_check_spec_caract(line_str[i], caract))
				i++;
		}
		if (!(*tab_tmp = (char *)malloc((i + 1)*sizeof(char))))
			return (NULL);
		*tab_tmp = ft_strncpy(*tab_tmp, &line_str[i], i);
		line_str = line_str + i;
		tab_tmp++;
	}
	*tab_tmp = NULL;
	tab_tmp = st;
	i = 0;
	while (tab_tmp[i])
	{
		ft_putstr(tab_tmp[i]);
		write(1, " ", 1);
		i++;
	}
	return (tab_tmp);
}