/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:02:43 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/21 17:39:41 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int exec_redir_LESSGREAT_RIGHT(t_data *data, t_token_node *tleft, t_token_node *tright)
{
    
    (void)data;
    (void)tleft;
    (void)tright;
    ft_putendl("exec_redir_LESSGREAT_RIGHT");
    return (0);
}

int exec_redir_LESSGREAT_LEFT(t_data *data, t_token_node *tleft, t_token_node *tright)
{
    (void)data;
    (void)tleft;
    (void)tright;
    ft_putendl("exec_redir_LESSGREAT_LEFT");
    return (0);
}

int exec_redir_GREATAND(t_data *data, t_token_node *tleft, t_token_node *tright)
{
    (void)data;
    (void)tleft;
    (void)tright;
    ft_putendl("exec_redir_GREATAND");
    return (0);
}

int exec_redir_LESSAND(t_data *data, t_token_node *tleft, t_token_node *tright)
{
    (void)data;
    (void)tleft;
    (void)tright;
    ft_putendl("exec_redir_LESSAND");
    return (0);
}

int exec_redir_DGREAT(t_data *data, t_token_node *tleft, t_token_node *tright)
{
    (void)data;
    (void)tleft;
    (void)tright;
    ft_putendl("exec_redir_DGREAT");
    return (0);
}

int exec_redir_DLESS(t_data *data, t_token_node *tleft, t_token_node *tright)
{
    (void)data;
    (void)tleft;
    (void)tright;
    ft_putendl("exec_redir_DLESS");
    return (0);
}