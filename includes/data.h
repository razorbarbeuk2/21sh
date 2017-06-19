/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:55:36 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/19 18:04:11 by gbourson         ###   ########.fr       */
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
	t_entry			*historique;
	t_entry			*line;
	t_select		*sel;
	int 			set_historique;
	int 			nb_prompt_historique;
	int				nb_pipe;
	char			**paths;
}					t_data;

#endif