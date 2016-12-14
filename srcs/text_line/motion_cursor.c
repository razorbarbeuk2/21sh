/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:41:40 by RAZOR             #+#    #+#             */
/*   Updated: 2016/12/13 17:11:47 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void ft_move_left(t_select *sel)
{
	if (sel->pos[1] > (int)sel->len_prompt && sel->pos[0] == sel->pos_start[0])
		sel->pos[1] -= 1;
	else if (sel->pos[0] != sel->pos_start[0] && sel->pos[1] > 0)
		sel->pos[1] -= 1;
	else if (sel->pos[1] == 0)
	{
		sel->pos[1] = (sel->width - 1);
		sel->pos[0] -= 1;
	}
	else
		return ;
}

void ft_move_right(t_select *sel)
{
	if (sel->pos[1] < sel->width )
		sel->pos[1] += 1;
	else
		return ;
}