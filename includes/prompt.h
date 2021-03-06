/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:46:52 by gbourson          #+#    #+#             */
/*   Updated: 2017/10/17 17:58:39 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

typedef enum			e_enum_quote
{
						QUOTE_SIMPLE = 1,
						QUOTE_DOUBLE = 2
}						t_enum_quote;

enum					e_enum_exec
{
						TYPE_DSEMI,
						TYPE_AND_IF,
						TYPE_OR_IF,
						TYPE_PIPE,
						TYPE_REDIRECTION_LESSGREAT_RIGHT,
						TYPE_REDIRECTION_LESSGREAT_LEFT,
						TYPE_REDIRECTION_GREATAND,
						TYPE_REDIRECTION_LESSAND,
						TYPE_REDIRECTION_DGREAT,
						TYPE_REDIRECTION_DLESS,
						TYPE_IO_NUMBER,
						TYPE_CMD,
						TYPE_FINISH,
						TYPE_NEAR_RETURN,
						TYPE_ERROR_PARSE
};

typedef struct 			s_token_node
{
	t_list				*node;
	struct s_token_node	*tleft;
	struct s_token_node	*tright;
}						t_token_node;

typedef struct 			s_token_struct
{
	unsigned int		type;
	int					value;
	int 				len;
	char 				*token_name_str;
	char 				**token_name_tab;
	char 				error;
}  			 			t_token_struct;

struct 					s_token_priority
{
	unsigned int 		token;
	int 				priority;
};

typedef enum			e_enum_cursor
{
						ACTIVE = 1,
						INACTIVE = 0,
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
						CTRL_CPY_PASTE = 16, // CTRL + P
						CTRL_CUT_PASTE = 12, // CTRL + L
						SEARCH_HIST = 18,
						// HOME = 58,
						// END = 61,
}						t_enum_cursor;

typedef struct			s_entry
{
	t_list				*line;
	t_list				*cpy;
	t_list				*cut_line;
	char 				*line_str;
	char 				**line_str_double;
	int					nb_line;
	int 				offset_line;
	size_t				len_line;
	size_t				size_line;
}						t_entry;

typedef struct			s_select
{
	int					*pos;
	int					*pos_start;
	int					*pos_tmp;
	int					i_lst;
	int					i_lst_tmp;
	int					_bottom;
	char				*prompt;
	int 				offset;
	size_t				len_prompt;
}						t_select;

typedef struct			s_term
{
	int					tty;
	int					width;
	int					height;
	struct termios		myterm;
}						t_term;


#endif