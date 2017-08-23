/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_define_priority_tab.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:22:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/08/23 16:53:29 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

struct s_token_priority *data_construct_token_priority_content(struct s_token_priority *tp, unsigned int tok, int num)
{
	if(tp)
	{
		tp->token = tok;
		tp->priority = num;
	}
	return (tp);
}

struct s_token_priority *data_construct_token_priority_node(struct s_token_priority **tp, unsigned int tok)
{
	if (tok == TYPE_FINISH)
		return (data_construct_token_priority_content(*tp, tok, 0));
	if (tok == TYPE_DSEMI)
		return (data_construct_token_priority_content(*tp, tok, 1));
	else if (tok == TYPE_AND_IF || tok == TYPE_OR_IF)
		return (data_construct_token_priority_content(*tp, tok, 2));
	else if (tok == TYPE_PIPE)
		return (data_construct_token_priority_content(*tp, tok, 3));
	else if (tok == TYPE_REDIRECTION_LESSGREAT || tok == TYPE_REDIRECTION_GREATAND || \
		tok == TYPE_REDIRECTION_LESSAND || tok == TYPE_REDIRECTION_DGREAT || tok == TYPE_REDIRECTION_DLESS)
		return (data_construct_token_priority_content(*tp, tok, 4));
	else if (tok == TYPE_CMD)
		return (data_construct_token_priority_content(*tp, tok, 5));
	return (NULL);
}

struct s_token_priority **data_construct_token_priority_tab(t_data *data)
{
	(void)data;
	enum e_enum_exec tok;
	struct s_token_priority **tab_priority;
	int count;
	int i;

	i = 0;
	count = 0;
	tok = TYPE_DSEMI;
	count = (int)ft_count_enum(TYPE_DSEMI, TYPE_FINISH + 1);
	tab_priority = (struct s_token_priority **)ft_memalloc((count + 1) * sizeof(struct s_token_priority *));
	while (i < count)
	{
		tab_priority[i] = (struct s_token_priority *)ft_memalloc(sizeof(struct s_token_priority));
		data_construct_token_priority_node(&tab_priority[i], tok);
		i++;
		tok++;
	}
	tab_priority[i] = NULL;
	return (tab_priority);
}