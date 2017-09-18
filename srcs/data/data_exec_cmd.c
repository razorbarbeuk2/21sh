/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/09/18 09:13:19 by RAZOR            ###   ########.fr       */
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

void tree_print(t_token_node *node_tree)
{
	if (node_tree == NULL)
		return;
	if (node_tree->tparent != NULL)
	{
		print_node_val(node_tree->tparent);
		ft_putstr(" -> ");
		print_node_val(node_tree);
		ft_putstr("\n");
	}
	else
		print_node_val(node_tree);
	if (node_tree->tleft)
		tree_print(node_tree->tleft);
	if (node_tree->tright)
		tree_print(node_tree->tright);
	return;
}

t_token_node *init_node(t_list *val)
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

t_token_node *data_construct_token_tree_node(t_data *data, t_list *lst_node, t_token_node *left_node, t_token_node *right_node)
{
	t_token_node *node_tree;

	(void)data;
	node_tree = NULL;
	node_tree = init_node(lst_node);
	node_tree->tleft = left_node;
	node_tree->tright = right_node;
	if (left_node)
		left_node->tparent = node_tree;
	if (right_node)
		right_node->tparent = node_tree;
	return (node_tree);
}

void 		check_construct_token_tree(t_data *data, struct s_token_priority **tab_priority, int i, t_token_node **st_node)
{
	t_list 			*token_list_tmp;
	t_token_node 	*st_node_tmp;
	t_token_struct 	*tmp_t_token_struct;
	t_list 			*prev;
	t_list 			*next;

	st_node_tmp = *st_node;
	tmp_t_token_struct = NULL;
	token_list_tmp = data->token_list;
	if (tab_priority[i]->token == TYPE_FINISH)
		return ;
	if (token_list_tmp && tab_priority[i]->token != TYPE_FINISH)
	{
		while (token_list_tmp && token_list_tmp->next)
		{
			prev = token_list_tmp;
			tmp_t_token_struct = ((t_token_struct *)token_list_tmp->next->content);
			if (token_list_tmp->next && (tmp_t_token_struct->type == tab_priority[i]->token))
			{
				next = (token_list_tmp->next->next) ? token_list_tmp->next->next : NULL;
				st_node_tmp = data_construct_token_tree_node(data, token_list_tmp->next, init_node(prev), init_node(next));
			}
			token_list_tmp = token_list_tmp->next;
			tmp_t_token_struct = NULL;
			prev = NULL;
		}
		check_construct_token_tree(data, tab_priority, i + 1, st_node);
	}
	return ;
}

void data_construct_token_tree(t_data *data, struct s_token_priority **tab_priority)
{
	t_token_node 	*node_tree;
	t_list 			*token_list_tmp;

	node_tree = NULL;
	token_list_tmp = data->token_list;
	if (token_list_tmp && tab_priority)
	{
		check_construct_token_tree(data, tab_priority, 0, &node_tree);
		if (!node_tree)
			ft_putstr("NO NODE");
		tree_print(node_tree);
		return;
	}
	return;
}

void exec_cmd_character(t_data *data)
{
	struct s_token_priority **tab_priority;

	tab_priority = NULL;
	write(1, "\n", 1);
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			print_error("historic error\n");
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str))
		{
			tab_priority = data_construct_token_priority_tab(data);
			data_construct_token_tree(data, tab_priority);
		}
		else
		{
			if (!get_reset_prompt(data))
				print_error("Prompt error\n");
		}
	}
	if (!get_reset_prompt(data))
		print_error("Prompt error\n");
	return;
}

// int dup_it_child(t_data *data, t_list *lst, int *save_fd, int p[2])
// {
// 	(void)save_fd;
// 	close(1);
// 	close(p[1]);
// 	dup2(p[0], STDIN_FILENO);
// 	close(p[0]);
// 	return (exec_cmd_node(data, lst));
// }

// int dup_it_dad(t_data *data, t_list *lst, int *save_fd, int p[2])
// {
// 	(void)save_fd;
// 	close(0);
// 	close(p[0]);
// 	dup2(p[1], STDOUT_FILENO);
// 	close(p[1]);
// 	return (exec_cmd_node(data, lst));
// }

// int 	data_exec_cmd(t_data *data)
// {
// 	t_list *lst;

// 	lst = NULL;
// 	lst = data->token_list;
// 	while (lst)
// 	{
// 		// if (lst->type == TYPE_CMD)
// 		// 	ft_putendl((char *)(t_cmd *)lst->content->cmd);
// 		// if (lst->type == TYPE_PIPE)
// 		// 	ft_putendl((t_cmd *)lst->content->separate);
// 		lst = lst->next;
// 	}
// 	return (1);
// }

// ft_putendl("NEXT ---------------------");
// ft_putendl(((t_cmd *)lst->next->content)->exec_cmd[0]);
// ft_putendl("--------------------------");

// ft_putendl("FD -------------------");
// ft_putnbr(pid);
// write(1, " - ", 1);
// ft_putnbr(pfd[1]);
// write(1, " ", 1);
// ft_putnbr(pfd[0]);
// ft_putendl("\n--------------------");

// int data_exec_cmd(t_data *data)
// {
// 	t_list *prev;
// 	t_list *lst;
// 	int save_fd;
// 	int pfd[2];
// 	char **exec_line;
// 	pid_t pid;

// 	save_fd = 0;
// 	lst = NULL;
// 	lst = data->cmd;
// 	exec_line = NULL;
// 	print_list_cmd(data, data->cmd);
// 	while (lst)
// 	{
// 		ft_putendl("\nNEXT >>>>>>>>>>>>");
// 		pid = fork();
// 		if ((lst->type == TYPE_SEP) && lst->next)
// 		{
// 			pipe(pfd);
// 			if (pid == 0)
// 				dup_it_child(data, lst->next, &save_fd, pfd);
// 			else
// 				dup_it_dad(data, prev, &save_fd, pfd);
// 			save_fd = pfd[0];
// 		}
// 		if(lst->type == TYPE_CMD)
// 			prev = lst;
// 		lst = lst->next;
// 	}
// 	return (1);
// }

/*DEBUG*******************************************/
// ft_putstr("\n[-]\n");
// ft_putnbr_fd(data->sel->pos[0], data->term->tty);
// write(1, " ", 1);
// ft_putnbr_fd(data->sel->pos[1], data->term->tty);
// ft_putstr("[-]\n");
// ft_putnbr_fd(data->sel->pos_start[0], data->term->tty);
// write(1, " ", 1);
// ft_putnbr_fd(data->sel->pos_start[1], data->term->tty);
// ft_putstr("[-]\n");
/************************************************/