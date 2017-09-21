/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dsemi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:57:51 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/21 17:43:46 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_DSEMI(t_data *data, t_token_node *tleft, t_token_node *tright)
{
    exec(data, tleft);
    exec(data, tright);
    return (0);
}