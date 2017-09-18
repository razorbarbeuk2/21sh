/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:14:23 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/18 17:17:48 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

typedef int (*G_func)(char *str, int *io, unsigned int *type, t_list **token_list);

 G_func G[] = {
	ft_token_semi,
	ft_token_and_if,
	ft_token_or_if,
	ft_token_pipe,
	ft_token_redirection,
	NULL
};

int ft_token_str_pos(t_data *data, char *line_str, t_list **token_list)
{
	int *i;
	int j;
	unsigned int type;
	

	(void)data;
	type = 0;
	i = ft_memalloc(2 * sizeof(int));
	while (line_str[i[0]] && (i[0] < (int)ft_strlen(line_str)))
	{
		if (line_str[i[0]] && (line_str[i[0]] == '"' || line_str[i[0]] == '\''))
			i[0] += data_check_quote_caract(&line_str[i[0]], &i[1]);
		else if (line_str[i[0]] && (line_str[i[0]] == '&' || line_str[i[0]] == ';' || line_str[i[0]] == '|' || line_str[i[0]] == '>' || line_str[i[0]] == '<'))
		{
			j = 0;
			data_check_is_token_cmd(token_list, line_str, (i[0] - i[1]), i[1]);			
			while(G[j])
			{
				if(G[j](line_str, &i[0], &type, token_list) == -1)
					return (ft_error_token(type));
				else if (G[j](line_str, &i[0], &type, token_list))
					break ;
				j++;
			}
			i[1] = 0;
		}
		i[0]++;
		i[1]++;
	}
	data_check_is_token_cmd(token_list, line_str, (i[0] - i[1]), i[1]);
	return (1);
}