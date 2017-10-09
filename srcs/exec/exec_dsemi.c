/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dsemi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:57:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/09 19:11:25 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_DSEMI(t_data *data, t_token_node *node, unsigned int fork_state)
{
    exec_cmd_type(data, node->tleft, fork_state);
    exec_cmd_type(data, node->tright, fork_state);
    return (0);
}