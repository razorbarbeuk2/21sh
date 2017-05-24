/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2017/05/24 14:31:14 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <ncurses.h>
# include <term.h>
#include  <fcntl.h>
# include "../libft/libft.h"
# include "./prompt.h"
# include "./data.h"
# include "./builtins.h"

# define RED "\e[31m"
# define ORANGE "\033[38;2;255;189;0m"
# define POS "\033[6n"
# define DEBUG ft_putstr("FUCK");

typedef	int			(*t_parse)(t_data *data);

typedef struct		s_lex
{
	char			*c;
	t_parse			p;
}					t_lex;

typedef struct		s_cmd
{
	char 			*cmd;
	char 			*opt;
	char 			*file;
	int 			_select_cmd;
}					t_cmd;

typedef struct		s_caract
{
	char 			*caract;
}					s_caract;


/*TOOLS*/
int					get_tab_to_lst(t_list **data_env, char **environ);
char				**get_lst_to_tab(t_list *env_lst);
void				print_lst(t_list *lst);
void 				print_lst_line_tools(t_data *data, t_list *lst);
void				print_pos_cursor(t_data *data);
/*TOOLS FREE*/
void				ft_free_char(char **tmp);
void				free_env(void *tmp, size_t tmp_size);
void				ft_free_tab_path(char **oldpath, char **path);
char				*ft_cut_path(t_list *env_lst, char *line);
/*TOOLS TERMCAPS*/
int					ft_concat_int(char *buf);
int					ft_putchar_select(int c);
/*TOOLS COUNT*/
int 				len_word(char *str);
int 				ft_count_word_caract(char *str);
int 				data_check_caract(char c);
char 				*trim_str(char *str);
char				*ft_strcpy_data(char *dst, const char *str);
int					ft_count_word_spec_caract(char *line_str, char *caract);
int					len_word_caract(char *line_str, char *caract);
/*PROMPT*/
void				ft_listen_cmd(t_data *data);
/*SEARCH*/
char				*get_search_infos(t_list *env, char *str);
/*ENV*/
void				init_env(t_list **env_lst);
int					iter_elem_env(char **tab_line, t_list **env_lst, int (*f)(char **t, t_list **e, t_list **s));
int					modif_elem(char **tab_line, t_list **env_lst, t_list **start);
int					del_elem(char **tab_line, t_list **env_lst, t_list **start);
/*OPTIONS*/
int					get_parse_opt(char **str, char *opt);
/*EXE*/
void				get_exe_path(t_data *data, char **line);
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
void				ft_move_word_left(t_data *data);
void				ft_move_word_right(t_data *data);
void				ft_cpy_word_left(t_data *data);
void				ft_cpy_word_right(t_data *data);
void				ft_paste_word_cpy(t_data *data);
void				ft_paste_word_cut(t_data *data);
void				ft_move_home(t_data *data);
void				ft_move_end(t_data *data);
void				ft_move_cursor(t_data *data, int result);
void 				ft_move(t_data *data, int x, int y);
void				reset_line(t_data *data);
void				print_character(t_data *data, char result);
void				del_one_character(t_data *data, char result);
void				exec_cmd_character(t_data *data);
void				motion_list(t_data *data, char opt);
/*ADD_DEL_CPY_PRINT_CHARACT*/
int					ft_add_print_caract(t_data *data, char result); /*data_str_insert_caract.c*/
int					ft_del_print_caract(t_data *data, char result); /*data_str_insert.c*/
void				ft_add_at(t_list **lst, char result);
/*DATA*/
char 				**data_clean_to_tab(t_data *data, char *str);
char 				*convert_data_lst_tab(t_data *data);
int 				data_check_caract(char c);
int 				data_check_spec_caract(char c, char *caract);
/*TOOLS*/
t_list				*ft_move_at_list(t_data *data, t_list **lst, int pos);
void				print_lst_line(t_data *data, t_list *lst);


/*CLEAN CARACT*/
char 				**data_split_to_tab(char *line_str, char *caract);























#endif
