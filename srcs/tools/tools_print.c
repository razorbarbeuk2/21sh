/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:44 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/19 11:47:50 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void print_env(t_list *lst)
{
	t_list	*tmp;
	t_env	*env;

	tmp = lst;
	if(!lst)
		ft_putendl_fd("FUCK 21SH", STDOUT_FILENO);
	while (tmp)
	{
		env = NULL;
		env = (t_env *)tmp->content;
		ft_putstr_fd(env->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putendl_fd(env->infos, STDOUT_FILENO);
		tmp = tmp->next;
	}
	tmp = NULL;
	return ;
}

int ft_print_token_test(t_list *token_lst)
{
	t_token_struct *token;

	while (token_lst)
	{
		token = (t_token_struct *)token_lst->content;
		ft_putendl(token->token_name_str);
		token_lst = token_lst->next;
	}
	return (0);
}

int ft_print_token(t_data *data, t_list **token_lst)
{
	t_list *lst;
	t_token_struct *token;

	lst = NULL;
	lst = (*token_lst);
	token = NULL;
	write(1, "\n", 1);
	while (lst)
	{
		token = (t_token_struct *)lst->content;
		if (token)
		{
			if (token->type == TYPE_DSEMI)
				ft_putendl("TYPE DSEMI---------------");
			else if (token->type == TYPE_AND_IF)
				ft_putendl("TYPE_AND_IF---------------");
			else if (token->type == TYPE_OR_IF)
				ft_putendl("TYPE_OR_IF---------------");
			else if (token->type == TYPE_PIPE)
				ft_putendl("TYPE_PIPE---------------");
			else if (token->type == TYPE_REDIRECTION_LESSGREAT_RIGHT)
				ft_putendl("TYPE_REDIRECTION_LESSGREAT_RIGHT---------------");
			else if (token->type == TYPE_REDIRECTION_LESSGREAT_LEFT)
				ft_putendl("TYPE_REDIRECTION_LESSGREAT_LEFT---------------");
			else if (token->type == TYPE_REDIRECTION_GREATAND)
				ft_putendl("TYPE_REDIRECTION_GREATAND---------------");
			else if (token->type == TYPE_REDIRECTION_LESSAND)
				ft_putendl("TYPE_REDIRECTION_LESSAND---------------");
			else if (token->type == TYPE_REDIRECTION_DGREAT)
				ft_putendl("TYPE_REDIRECTION_DGREAT---------------");
			else if (token->type == TYPE_REDIRECTION_DLESS)
				ft_putendl("TYPE_REDIRECTION_DLESS---------------");
			else if (token->type == TYPE_IO_NUMBER)
				ft_putendl("TYPE_IO_NUMBER---------------");
			else if (token->type == TYPE_CMD)
				ft_putendl("TYPE_CMD---------------");
			else if (token->type == TYPE_IO_NUMBER)
				ft_putendl("TYPE_IO_NUMBER---------------");
			print_tab(data, token->token_name_tab);
			ft_putendl("END TOKEN---------------");
		}
		else
			ft_putendl("FUCK TOKEN---------------");
		lst = lst->next;
		token = NULL;
	}
	return (0);
}

void print_tab(t_data *data, char **str_tab)
{
	int i;

	i = 0;
	while (str_tab[i])
	{
		ft_putstr_fd(str_tab[i], data->term->tty);
		ft_putstr(" ");
		i++;
	}
	N;
}

void count_list_cmd(t_data *data, t_list *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	ft_putnbr_fd(count, data->term->tty);
	return;
}

// void print_list_node_cmd(t_data *data, t_list *lst)
// {
// 	t_cmd *cmd_lst;
// 	int i;

// 	i = 0;
// 	cmd_lst = NULL;
// 	cmd_lst = (t_cmd *)lst->content;
// 	if (!cmd_lst)
// 		ft_putstr_fd("FUCK", data->term->tty);
// 	if (cmd_lst->cmd)
// 	{
// 		ft_putstr_fd("cmd :", data->term->tty);
// 		ft_putstr_fd(cmd_lst->cmd, data->term->tty);
// 		write(1, "\n", 1);
// 	}
// 	if (cmd_lst->opt)
// 	{
// 		ft_putstr_fd("opt :", data->term->tty);
// 		ft_putstr_fd(cmd_lst->opt, data->term->tty);
// 		write(1, "\n", 1);
// 	}
// 	if (cmd_lst->files)
// 	{
// 		while (cmd_lst->files[i])
// 		{
// 			ft_putstr_fd("file :", data->term->tty);
// 			ft_putstr_fd(cmd_lst->files[i], data->term->tty);
// 			write(1, "\n", 1);
// 			i++;
// 		}
// 	}
// }

// void print_list_node_sep(t_data *data, t_list *lst)
// {
// 	t_sep *sep;

// 	sep = NULL;
// 	sep = (t_sep *)lst->content;
// 	if (!sep->separate)
// 		ft_putstr_fd("FUCK", data->term->tty);
// 	if (sep->separate)
// 	{
// 		ft_putstr_fd("sep :", data->term->tty);
// 		ft_putstr_fd(sep->separate, data->term->tty);
// 		write(1, "\n", 1);
// 	}
// }

// void print_list_cmd(t_data *data, t_list *lst)
// {
// 	write(1, "\n", 1);
// 	while (lst)
// 	{
// 		if (lst->type == TYPE_CMD)
// 		{
// 			ft_putstr_fd("TYPE_CMD : ", data->term->tty);
// 			ft_putnbr_fd(TYPE_CMD, data->term->tty);
// 			write(1, "\n", 1);
// 			print_list_node_cmd(data, lst);
// 		}
// 		if (lst->type == TYPE_PIPE)
// 		{
// 			ft_putstr_fd("TYPE_PIPE : ", data->term->tty);
// 			ft_putnbr_fd(TYPE_PIPE, data->term->tty);
// 			write(1, "\n", 1);
// 			print_list_node_sep(data, lst);
// 		}
// 		lst = lst->next;
// 	}
// }

/*FAIRE ATTENTION*/

void print_lst_line_end_pos_cursor(t_data *data, t_list *lst)
{
	(void)data;
	while (lst)
	{
		ft_putstr_fd((char *)lst->content, STDOUT_FILENO);
		lst->set_select = 0;
		lst = lst->next;
	}
	return ;
}

void print_lst_line(t_data *data, t_list *lst)
{
	(void)data;
	if (lst)
	{
		tputs(tgetstr("sc", NULL), 1, ft_putchar_select);
		// if (data->sel->pos[1] == (data->term->width - 1))
		// 	ft_move_cursor(data, LEFT, MOVE_LST);
		while (lst)
		{
			ft_putstr_fd((char *)lst->content, STDOUT_FILENO);
			lst->set_select = 0;
			lst = lst->next;
		}
		tputs(tgetstr("rc", NULL), 1, ft_putchar_select);
	}
	return;
}

void print_lst_line_tools(t_data *data, t_list *lst)
{
	(void)data;
	if (!lst)
		ft_putstr_fd("FUCK", STDOUT_FILENO);
	while (lst)
	{
		ft_putendl_fd((char *)lst->content, STDOUT_FILENO);
		lst = lst->next;
	}
	return;
}