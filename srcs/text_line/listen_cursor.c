/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:43:20 by RAZOR             #+#    #+#             */
/*   Updated: 2017/10/04 21:23:19 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_move_cursor(t_data *data, int result, int state)
{
	if (result == LEFT)
		ft_move_left(data, state);
	else if (result == RIGHT)
		ft_move_right(data, state);
	else if (result == HOME)
		ft_move_home(data);
	else if (result == END)
		ft_move_end(data);
	else if (result == UP || result == DOWN)
		ft_move_up_down_historic(data, result);
	else
		return ;
}

void		ft_cmd_cursor(t_data *data, int result)
{
	if (result == ALT_DOWN)
		ft_move_down(data);
	else if (result == ALT_UP)
		ft_move_up(data);
	else if (result == ALT_LEFT)
		ft_move_word_left(data);
	else if (result == ALT_RIGHT)
		ft_move_word_right(data);
	else if (result == SHIFT_LEFT)
		ft_cpy_word_left(data);
	else if (result == SHIFT_RIGHT)
		ft_cpy_word_right(data);
	else if (result == CTRL_CPY_PASTE)
		ft_paste_word_cpy(data);
	else if (result == CTRL_CUT_PASTE)
		ft_paste_word_cut(data);
	else if (result == ENTER)
		exec_cmd_character(data);
	else if (result == DEL)
		del_one_character(data, result);
	else if (result == ESC)
		reset_line(data);
	else if (result == SEARCH_HIST)
		get_hist_prompt(data);
	else
		return ;
}

void 		listen_cursor_check_module_active(t_data *data)
{
	if (data->set_quotes && !data->set_historique)
	{
		get_pos_prompt(data);
		data->sel->len_prompt = data->quotes->nb_prompt_quote;
		data->sel->pos_start[0] = data->sel->pos[0];
		data->sel->pos_start[1] = data->sel->pos[1];
		motion_list(data, 'E');
		ft_add_print_caract(data, '\n');
		motion_list(data, 'E');
	}
	if (data->set_historique && !data->set_quotes)
	{
		get_pos_prompt(data);
		data->sel->len_prompt = data->historic->nb_prompt_historique;
		data->sel->pos_start[0] = data->sel->pos[0];
		data->sel->pos_start[1] = data->sel->pos[1];
	}
}

/*Faire la suite quote prompt - push ENTER*/

int			listen_cursor(t_data *data, t_entry *entry)
{
	char	buf[8];
	int		result;

	result = 0;
	data->entry = NULL;
	data->entry = entry;
	ft_memset(buf, 0, 8);
	listen_cursor_check_module_active(data);
	data->entry->size_line = data->sel->len_prompt;
	while(read(0, buf, 8))
	{
		result = ft_concat_int(buf);
		if (result == LEFT || result == RIGHT || result == HOME || result == END || result == UP || result == DOWN)
			ft_move_cursor(data, result, MOVE_LST);
		ft_cmd_cursor(data, result);
		if ((result >= 32 && result <= 126) && result != HOME && result != END)//Enlever HOME et END dans cette condition Num de touche à changer
			print_character(data, result);	
		get_pos_prompt(data);
		ft_bzero(buf, 8);
	}
	return (0);
}
