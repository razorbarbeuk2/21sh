/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/08/23 18:10:07 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

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

void data_construct_token_tree_node(t_data *data, t_list *lst_node, t_list *left_node, t_list *right_node)
{
	t_token_node *node_tree;

	(void)data;
	node_tree = NULL;
	node_tree = init_node(lst_node);
	if (node_tree)
	{
		if (left_node)
			node_tree->tleft = init_node(left_node);
		if (right_node)
			node_tree->tright = init_node(right_node);
		if (node_tree->tleft)
			node_tree->tleft->tparent = node_tree;
		if (node_tree->tright)
			node_tree->tright->tparent = node_tree;
		return;
	}
	return;
}

void check_construct_token_tree(t_data *data, struct s_token_priority **tab_priority, int i)
{
	t_list *token_list_tmp;
	t_token_struct *tmp_t_token_struct;
	t_list *prev;
	t_list *next;

	tmp_t_token_struct = NULL;
	token_list_tmp = data->token_list;
	if (tab_priority[i]->token == TYPE_FINISH)
		return;
	if (token_list_tmp && tab_priority[i]->token != TYPE_FINISH)
	{
		while (token_list_tmp && token_list_tmp->next)
		{
			prev = token_list_tmp;
			tmp_t_token_struct = ((t_token_struct *)token_list_tmp->next->content);
			if (token_list_tmp->next && (tmp_t_token_struct->type == tab_priority[i]->token))
			{
				next = (token_list_tmp->next->next) ? token_list_tmp->next->next : NULL;
				data_construct_token_tree_node(data, token_list_tmp->next, prev, next);
			}
			token_list_tmp = token_list_tmp->next;
			tmp_t_token_struct = NULL;
			prev = NULL;
		}
		check_construct_token_tree(data, tab_priority, i + 1);
	}
	return;
}

void data_construct_token_tree(t_data *data, struct s_token_priority **tab_priority)
{
	t_token_tree *tree_struct;
	t_list *token_list_tmp;

	tree_struct = NULL;
	token_list_tmp = data->token_list;
	tree_struct = ft_memalloc(sizeof(t_token_tree));
	if (token_list_tmp && tab_priority)
	{
		check_construct_token_tree(data, tab_priority, 0);
		return;
	}
	return;
}

void exec_cmd_character(t_data *data)
{
	struct s_token_priority **tab_priority;

	tab_priority = NULL;
	parse_quote_and_double_quote(data);
	data->entry->line_str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		if (!add_sentence_historic_node_to_list(data))
			print_error("historic error\n");
		if (data_check_str_list_struct_cmd_loop(data, data->entry->line_str))
		{
			tab_priority = data_construct_token_priority_tab(data);
			ft_print_token(&data->token_list);
			data_construct_token_tree(data, tab_priority);
		}
		else
		{
			if (!get_reset_prompt(data))
				print_error("Prompt error\n");
		}
		//data_exec_cmd(data);
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