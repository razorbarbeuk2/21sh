/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:09:57 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/20 17:09:39 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_join_free(char *str, char *buf)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (str);
}

char	*ft_next(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	i = ft_strchr(str, '\n') - str;
	*line = ft_strsub(str, 0, i);
	tmp = str;
	str = ft_strsub(tmp, i + 1, ft_strlen(tmp) - i);
	ft_strdel(&tmp);
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str;

	ret = 0;
	while ((str == NULL) || (ft_strchr(str, '\n') == NULL))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if ((ret < 0) || (line == NULL))
			return (-1);
		if (ret == 0 && str != NULL)
		{
			(*line) = ft_strdup(str);
			ft_strdel(&str);
			return ((ft_strcmp((*line), "")) != 0);
		}
		if (str == NULL)
			str = ft_strdup(buf);
		else
			str = ft_join_free(str, buf);
	}
	str = ft_next(str, line);
	return (1);
}
