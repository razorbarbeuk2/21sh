/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:43:20 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/18 14:53:58 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_move_cursor(t_data *data, int result)
{
	if (result == LEFT)
		ft_move_left(data);
	else if (result == RIGHT)
		ft_move_right(data);
	else if (result == HOME)
		ft_move_home(data);
	else if (result == END)
		ft_move_end(data);
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
	else if (result == RST)
		reset_line(data);
	else
		return ;
}

int			listen_cursor(t_data *data)
{
	char	buf[8];
	int		result;

	result = 0;
	ft_bzero(buf, 8);
	get_super_prompt(data, NULL);
	data->sel->pos = ft_memalloc(2*sizeof(int));
	data->sel->pos_start = ft_memalloc(2*sizeof(int));
	data->sel->pos_tmp = ft_memalloc(2*sizeof(int));
	get_pos_prompt(data);
	data->entry->size_line = data->sel->len_prompt;
	data->sel->pos_start[0] = data->sel->pos[0];
	data->sel->pos_start[1] = data->sel->pos[1];
	if (data->sel->pos_start[0] == (data->sel->height - 1))
		data->sel->_bottom = 1;
	while(read(0, buf, 8))
	{
		result = ft_concat_int(buf);
		if (result == DEL || result == ENTER)
			ft_cmd_cursor(data, result);
		else if (result == ALT_UP || result == ALT_DOWN || result == ALT_LEFT || result == ALT_RIGHT)
			ft_cmd_cursor(data, result);
		else if (result == SHIFT_LEFT || result == SHIFT_RIGHT)
			ft_cmd_cursor(data, result);
		else if (result == RST || result == CTRL_CPY_PASTE || result == CTRL_CUT_PASTE)
			ft_cmd_cursor(data, result);
		else if (result == HOME || result == END)
			ft_move_cursor(data, result);
		else if ((result >= 32 && result <= 126) && result != HOME && result != END) //Enlever HOME et END dans cette condition Num de touche à changer
			print_character(data, result);
		else if (result >= UP && result <= LEFT)
			ft_move_cursor(data, result);
		get_pos_prompt(data);
		ft_bzero(buf, 8);
	}
	return (0);
}
