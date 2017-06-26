/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/26 17:26:43 by gbourson         ###   ########.fr       */
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
# define SEARCH_COLOR "\033[38;2;22;193;213m"
# define POS "\033[6n"
# define DEBUG ft_putstr("FUCK");

typedef struct		s_fd
{
	int				stdin;
	int				stdout;
	int				stderr;
}					t_fd;

typedef struct		s_sep
{
	char 			*separate;
}					t_sep;

typedef struct		s_cmd
{
	char 			*cmd;
	char 			*opt;
	char 			*file;
	int 			_select_cmd;
	char			**exec_cmd;
	t_fd			fds;
}					t_cmd;

/*TOOLS*/
int					get_tab_to_lst(t_list **data_env, char **environ);
char				**get_lst_to_tab(t_list *env_lst);
void				print_lst(t_list *lst);
void 				print_lst_line_tools(t_data *data, t_list *lst);
void				print_pos_cursor(t_data *data);
/*TOOLS FREE*/
void				ft_free_char(char **tmp);
void				ft_free_env(void *tmp, size_t tmp_size);
void				ft_free_tab_path(char **oldpath, char **path);
void				ft_free_node(void *tmp, size_t tmp_size);
void				ft_free_select(t_data *data);
void				ft_free_cmd(void *tmp, size_t tmp_size);
void				ft_lstdel_cmd(t_list **alst);
void				free_data_entry(t_data *data);
char				*ft_cut_path(t_data *data);

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
/*TOOLS LIST CREATE NODE*/
t_list				*ft_lstnew_node_type(void const *content, size_t content_size, int t);
/*INIT*/
void				init_env(t_list **env_lst);
int					init_paths_home_env(t_data *data);
int					init_struct(t_data *data);
int 				init_pos(t_data *data);
t_entry 			*init_data_entry();
t_cmd 				*init_t_cmd();
t_sep 				*init_t_sep();
/*ENV*/
char				*get_search_infos(t_list *env, char *str);
int					iter_elem_env(char **tab_line, t_list **env_lst, int (*f)(char **t, t_list **e, t_list **s));
int					modif_elem(char **tab_line, t_list **env_lst, t_list **start);
int					del_elem(char **tab_line, t_list **env_lst, t_list **start);
/*OPTIONS*/
int					get_parse_opt(char **str, char *opt);
/*EXE*/
int					get_exe_path(t_data *data, char **line);
int					ft_get_access(t_list *env, char **line, char **paths, char *result);
int					ft_no_paths(t_list *env, char **line, char ***paths, char **result);
int					get_exe_cmd(char **path, char **cmd, t_list *env_lst);
/*PRINT*/
void				print_error(char *str);
void				print_cmd_not_found(char *str);
void				print_list_cmd(t_data *data, t_list *lst);
/*TERM*/
int					term_init(t_select *sel);
void				termios_init(struct	termios *term);
/*PROMPT*/
int					get_reset_prompt(t_data *data);
void				get_super_prompt(t_data *data);
int					get_pos_prompt(t_data *data);
void				ft_listen_cmd(t_data *data);
/*MOTION_CURSOR*/
int					listen_cursor(t_data *data, t_entry *entry);
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
void				del_one_character(t_data *data, int result);
void				exec_cmd_character(t_data *data);
void				motion_list(t_data *data, char opt);
/*ADD_DEL_CPY_PRINT_CHARACT*/
int					ft_add_print_caract(t_data *data, char result); /*data_str_insert_caract.c*/
int					ft_del_print_caract(t_data *data, char result); /*data_str_insert.c*/
void				ft_add_at(t_list **lst, char result);
/*DATA*/
char 				**data_clean_to_tab(t_data *data, char *str);
char 				*convert_data_lst_tab(t_data *data);
void				data_check_str_list_struct_cmd_loop(t_data *data, char **line_str, int i, int size);
int 				data_check_caract(char c);
int 				data_check_spec_caract(char c, char *caract);
void				data_create_list_struct(t_data *data, char **line_str, void **node, int *t);
int					data_str_check_opt_cmd(t_cmd *cmd, char *line_str);
int 				ft_is_caract_(char *str, char *c);
/*HISTORY*/
void				get_hist_prompt(t_data *data);
int					data_init_history_file(t_data *data);
int					data_check_and_create_history_cmd(t_data *data, char *cmd);
int					data_search_in_history_file(t_data *data, char *search_cmd);
int					ft_move_up_down_historic(t_data *data, int result);
/*EXEC*/
int					exec_cmd_node_pipe(t_data *data, t_list *prev, t_list *next);
int					exec_cmd_node(t_data *data, t_list *current);
/*TOOLS*/
t_list				*ft_move_at_list(t_data *data, t_list **lst, int pos);
void				print_lst_line(t_data *data, t_list *lst);
void 				count_list_cmd(t_data *data, t_list *lst);
/*CLEAN CARACT*/
char 				**data_split_to_tab(char *line_str, char caract);
//char 				**data_split_to_tab(char *line_str, char *caract);
























#endif
