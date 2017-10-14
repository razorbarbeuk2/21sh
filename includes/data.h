/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:55:36 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/14 16:40:23 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct		s_quote
{
	int 			nb_prompt_quote;
}					t_quote;

typedef struct		s_historic
{
	int				fd;
	int 			count_pos;
	int 			count_node;
	int 			nb_prompt_historique;
	t_list			*list_historic;
	t_list			*rev_list_historic;/*PEUT ETRE A VIRER*/
	t_entry			*historique;
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
	t_list			*token_list;
	t_entry			*entry;
	t_entry			*line;
	t_select		*sel;
	t_historic		*historic;
	t_quote			*quotes;
	t_term			*term;
	pid_t	        pid;
	int 			set_historique;
	int 			set_quotes;
	int				nb_pipe;
	int 			fork;
	char			*home;
	char			**paths;
}					t_data;

#endif