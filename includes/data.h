/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:55:36 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/12 23:17:46 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct		s_env
{
	char			*key;
	char			*infos;
}					t_env;

typedef struct		s_data
{
	t_list			*env;
	t_list			*env_cpy;
	t_list			*cmd;
	t_entry			*entry;
	t_select		*sel;
	int				nb_pipe;
	char			**paths;
}					t_data;

#endif