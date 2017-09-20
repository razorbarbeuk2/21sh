/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create_ast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:44:26 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/19 21:45:06 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void print_node_val(t_token_node *node_tree)
{
	t_token_struct *tmp_t_token_struct;

	tmp_t_token_struct = NULL;
	if (node_tree->node)
	{
		tmp_t_token_struct = ((t_token_struct *)node_tree->node->content);
		ft_putstr(tmp_t_token_struct->token_name);
		tmp_t_token_struct = NULL;
	}
	return;
}

static t_token_node *init_node(t_list *val)
{
	t_token_node *node_tree;

	node_tree = NULL;
	node_tree = ft_memalloc(sizeof(t_token_node));
	if (node_tree && val)
	{
		node_tree->node = val;
		node_tree->tleft = NULL;
		node_tree->tright = NULL;
		return (node_tree);
	}
	return (NULL);
}

t_token_node *check_construct_token_tree(t_list *token_list, t_list *cmp, int value, t_token_node *st_node)
{
	t_list *lst;
	t_list *tmp;
	t_token_struct *tmp_struct;

	tmp = NULL;
	lst = token_list;
	tmp_struct = NULL;
	if(value ==  6 || !token_list)
		return (NULL);
	while (lst && lst != cmp)
	{
		tmp_struct = (t_token_struct *)lst->content;
		if(tmp_struct->value == value)
			tmp = lst;
		lst = lst->next;
	}
	if(!tmp)
		return(check_construct_token_tree(token_list, cmp, value + 1, st_node));
	st_node = init_node(tmp);
	st_node->tleft = check_construct_token_tree(token_list, tmp, value, st_node->tleft);
	st_node->tright = check_construct_token_tree(tmp->next, cmp, value + 1, st_node->tright);
	return (st_node);
}