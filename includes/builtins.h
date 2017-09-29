/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:20:22 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/29 17:42:10 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef	void		(*t_option)(t_data *data, char **line);
typedef int 		(*t_function_opt)(t_data *data, char *line);
//typedef	int			(*token_func)(char *str, int *io, unsigned int *type, t_list **token_list);

typedef struct		s_char
{
	char			l;
	int				g;
}					t_char;

typedef struct		s_opt
{
	char			*opt;
	t_option		f;
}					t_opt;

struct 	s_option
{
	char 			*option;
	t_function_opt 	f;	
};

#endif