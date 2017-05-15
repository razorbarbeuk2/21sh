/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str_clean_caract.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:06:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/15 17:37:15 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int 		data_check_caract(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		return (1);
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