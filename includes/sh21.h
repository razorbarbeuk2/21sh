/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2017/04/21 11:14:40 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <ncurses.h>
# include <term.h>
#include  <fcntl.h>


# define OPT_ENV "i"
# define BUILD_FIND 0
# define BUILD_EXE 1
# define RED "\e[31m"
# define ORANGE "\033[38;2;255;189;0m"
# define POS "\033[6n"
# define DEBUG ft_putstr("FUCK");

typedef	int			(*t_func)(t_list **env_lst, char **line);
typedef	void		(*t_option)(t_list *env_lst, char **line);

typedef enum		e_enum
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
					//HOME = 58,
					//END = 61,
}					t_enum;

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

typedef struct		s_buil
{
	char			*name;
	t_func			f;
}					t_buil;

typedef struct		s_entry
{
	t_list			*line;
	t_list			*cut_line;
	size_t			len_line;
	size_t			size_line;
	int				nb_line;
}					t_entry;

typedef struct		s_select
{
	char			**path_arg;
	char			**arg;
	char			*termcapbuf;
	int				*pos;
	int				*pos_start;
	int				i_lst;
	int				tty;
	int				width;
	int				height;
	char			*prompt;
	size_t			len_prompt;
	struct termios	myterm;
}					t_select;

typedef struct		s_env
{
	char			*key;
	char			*infos;
}					t_env;

typedef struct		s_data
{
	t_list			*env;
	t_entry			*entry;
	t_select		*sel;
}					t_data;

/*TOOLS*/
int					get_tab_to_lst(t_list **data_env, char **environ);
char				**get_lst_to_tab(t_list *env_lst);
void				print_lst(t_list *lst);
void				print_pos_cursor(t_data *data);
/*TOOLS FREE*/
void				ft_free_char(char **tmp);
void				free_env(void *tmp, size_t tmp_size);
void				ft_free_tab_path(char **oldpath, char **path);
char				*ft_cut_path(t_list *env_lst, char *line);
/*TOOLS TERMCAPS*/
int					ft_concat_int(char *buf);
int					ft_putchar_select(int c);
/*PROMPT*/
void				ft_listen_cmd(t_data *data);
/*SEARCH*/
char				*get_search_infos(t_list *env, char *str);
/*BUILTINS DRIVE*/
int					buil_drive(t_list **env_lst, char **line, int opt);
/*BUILTINS*/
void				parse_line_builtins(t_list **env, char **line);
int					builtin_env(t_list **env_lst, char **line);
int					builtin_unsetenv(t_list **env_lst, char **line);
int					builtin_setenv(t_list **env_lst, char **line);
int					builtin_cd(t_list **env_lst, char **line);
char				*builtin_cd_special_caract(t_list **env_lst, char **line);
char				*builtin_cd_special_caract_home(t_list **env_lst, char **line);
char				*builtin_cd_special_caract_home_noline(t_list **env_lst, char **line);
int					ft_check_move(char *path);
int					builtin_echo(t_list **env_lst, char **line);
void				builtin_echo_use_e(t_list *env_lst, char **line);
void				builtin_echo_use_n(t_list *env_lst, char **line);
void				builtin_echo_quote(t_list *env_lst, char **line);
int					builtin_exit(t_list **env_lst, char **line);
/*ENV*/
void				init_env(t_list **env_lst);
int					iter_elem_env(char **tab_line, t_list **env_lst, int (*f)(char **t, t_list **e, t_list **s));
int					modif_elem(char **tab_line, t_list **env_lst, t_list **start);
int					del_elem(char **tab_line, t_list **env_lst, t_list **start);
/*OPTIONS*/
int					get_parse_opt(char **str, char *opt);
/*EXE*/
void				get_exe_path(t_list *env, char **line);
int					ft_get_access(t_list *env, char **line, char **paths, char *result);
int					ft_no_paths(t_list *env, char **line, char ***paths, char **result);
void				get_exe_cmd(char **path, char **cmd, t_list *env_lst);
/*PRINT*/
void				print_error(char *str);
void				print_cmd_not_found(char *str);
/*TERM*/
int					term_init(t_select *sel);
void				termios_init(struct	termios *term);
/*PROMPT*/
void				get_super_prompt(t_data *data, char *line);
int					get_pos_prompt(t_data *data);
/*MOTION_CURSOR*/
int					listen_cursor(t_data *data);
void				ft_move_left(t_data *data);
void				ft_move_right(t_data *data);
void				ft_move_up(t_data *data);
void				ft_move_down(t_data *data);
void				ft_move_home(t_data *data);
void				ft_move_end(t_data *data);
void				ft_move_cursor(t_data *data, int result);
void				print_character(t_data *data, char result);
void				del_one_character(t_data *data, char result);
void				exec_cmd_character(t_data *data, char result);
void				motion_list(t_data *data, char opt);
/*PRINT_CHARACT*/
int					ft_add_print_caract(t_data *data, char result);
int					ft_del_print_caract(t_data *data, char result);
/*TOOLS*/
void				print_lst_line(t_data *data, t_list *lst);

#endif
