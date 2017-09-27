/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:03:38 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/27 15:58:19 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_CMD(t_data *data, t_token_node *node, unsigned int fork_state)
{
    (void)data;
    (void)node;
    (void)fork_state; 
    ft_putendl("exec_cmd");
    return (0);
}