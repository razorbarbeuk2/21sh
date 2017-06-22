/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:46:52 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/22 14:46:26 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <term.h>

typedef enum		e_enum_exec
{
					TYPE_CMD = 1,
					TYPE_SEP = 2,
					PIPE_READ = 0,
					PIPE_WRITE = 1
}					t_enum_exec;

typedef enum		e_enum_cursor
{
					UP = 279165,
					DOWN =  279166,
					RIGHT = 279167,
					LEFT = 279168,
					SPACE = 32,
					ESC = 27,
					ENTER = 10,
					DEL = 127,
					HOME = 279172,
					END = 279170,
					ALT_UP = 27279165,
					ALT_DOWN = 27279166,
					ALT_RIGHT = 27279167,
					ALT_LEFT = 27279168,
					SHIFT_LEFT = -23279172,
					SHIFT_RIGHT = -23279173,
					CTRL_CPY_PASTE = 16,
					CTRL_CUT_PASTE = 12,
					SEARCH_HIST = 18, // CTRL + R
					RST = 14 // CTRL + N
					// ALT_RIGHT
					//HOME = 58,
					//END = 61,
}					t_enum_cursor;

typedef struct		s_entry
{
	t_list			*line;
	t_list			*cpy;
	t_list			*cut_line;
	size_t			len_line;
	size_t			size_line;
	char 			*line_str;
	char 			**line_str_double;
	int				nb_line;
}					t_entry;

typedef struct		s_select
{
	int				*pos;
	int				*pos_start;
	int				*pos_tmp;
	int				i_lst;
	int				i_lst_tmp;
	int				tty;
	int				width;
	int				height;
	int				_bottom;
	char			*prompt;
	size_t			len_prompt;
	struct termios	myterm;
}					t_select;

#endif