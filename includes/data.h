/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:55:36 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/20 16:26:46 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct		s_historic
{
	int				fd;
	int 			count_pos;
	int 			count_node;
	t_list			*list_historic;
	t_list			*rev_list_historic;
}					t_historic;

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
	t_historic		*historic;
	int 			set_historique;
	int 			nb_prompt_historique;
	int				nb_pipe;
	char			**paths;
}					t_data;

#endif