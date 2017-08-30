/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2017/08/30 16:55:53 by gbourson         ###   ########.fr       */
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
# include  <fcntl.h>
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

/*TOOLS*/
int							get_tab_to_lst(t_list **data_env, char **environ);
char						**get_lst_to_tab(t_list *env_lst);
void						print_lst(t_list *lst);
void 						print_lst_line_tools(t_data *data, t_list *lst);
void						print_pos_cursor(t_data *data);
/*TOOLS FREE*/
void						ft_free_char(char **tmp);
void						ft_free_env(void *tmp, size_t tmp_size);
void						ft_free_tab_path(char **oldpath, char **path);
void						ft_free_node(void *tmp, size_t tmp_size);
void						ft_free_cmd(void *tmp, size_t tmp_size);
void						ft_lstdel_token(t_list **token_list);
int     					free_cursor(t_data *data);
int 						free_destruction_final(t_data *data);
void 						ft_free_pos(t_select *sel);
void						ft_free_token(t_token_struct *token);
t_select					*free_data_select(t_select *sel);
t_entry						*free_data_entry(t_entry *entry);
t_historic					*free_data_historic(t_historic *historic);
t_quote 					*free_data_quotes(t_quote *quotes);

/*TOOLS TERMCAPS*/
int							ft_concat_int(char *buf);
int							ft_putchar_select(int c);
/*TOOLS COUNT*/
int 						len_word(char *str);
int							len_word_caract(char *line_str, char *caract);
int 						ft_count_word_caract(t_data *data, char *str);
int 						data_check_caract(char c);
char 						*trim_str(char *str);
char						*ft_strcpy_data(char *dst, const char *str);
int							ft_count_word_spec_caract(char *line_str, char *caract);
int 						ft_count_enum(unsigned int START, unsigned int END);
/*INIT*/
void						init_env(t_list **env_lst);
int							init_paths_home_env(t_data *data);
int							init_struct(t_data *data);
int 						init_prompt(t_data *data);
t_select 					*init_data_sel();
t_entry 					*init_data_entry();
t_historic 					*init_data_hist();
t_quote 					*init_data_quotes();
/*ENV*/
char						*get_search_infos(t_list *env, char *str);
int							iter_elem_env(char **tab_line, t_list **env_lst, int (*f)(char **t, t_list **e, t_list **s));
int							modif_elem(char **tab_line, t_list **env_lst, t_list **start);
int							del_elem(char **tab_line, t_list **env_lst, t_list **start);
/*OPTIONS*/
int							get_parse_opt(char **str, char *opt);
/*EXE*/
int							get_exe_path(t_data *data, char **line);
int							ft_get_access(t_data *data, char **line, char *result);
int							ft_no_paths(t_data *data, char **line);
int							get_exe_cmd(t_data *data, char **path, char **cmd, t_list *env_lst);
/*PRINT*/
void						print_error(char *str);
void						print_cmd_not_found(char *str);
void						print_list_cmd(t_data *data, t_list *lst);
int							print_parse_error(char *str);
/*TERM*/
int							term_init(t_term *term);
void						termios_init(struct	termios *term);
void						ft_term_reset(t_term *term);
/*PROMPT*/
char						*ft_cut_path(t_data *data);
int							get_reset_prompt(t_data *data);
void						get_super_prompt(t_data *data);
void						get_quote_prompt(t_data *data);
void						get_hist_prompt(t_data *data);
int							get_pos_prompt(t_data *data);
void						ft_listen_cmd(t_data *data);
/*MOTION_CURSOR*/
int							listen_cursor(t_data *data, t_entry *entry);
void						ft_move_left(t_data *data);
void						ft_move_right(t_data *data);
void						ft_move_up(t_data *data);
void						ft_move_down(t_data *data);
void						ft_move_word_left(t_data *data);
void						ft_move_word_right(t_data *data);
void						ft_cpy_word_left(t_data *data);
void						ft_cpy_word_right(t_data *data);
void						ft_paste_word_cpy(t_data *data);
void						ft_paste_word_cut(t_data *data);
void						ft_move_home(t_data *data);
void						ft_move_end(t_data *data);
void						ft_move_cursor(t_data *data, int result);
void 						ft_move(t_data *data, int x, int y);
void						reset_line(t_data *data);
void						print_character(t_data *data, char result);
void						del_one_character(t_data *data, int result);
void						exec_cmd_character(t_data *data);
void						motion_list(t_data *data, char opt);
/*ADD_DEL_CPY_PRINT_CHARACT*/
int							ft_add_print_caract(t_data *data, char result); /*data_str_insert_caract.c*/
int							ft_del_print_caract(t_data *data, char result); /*data_str_insert.c*/
void						ft_add_at(t_list **lst, char result);
/*DATA*/
char 						**data_clean_to_tab(t_data *data, char *str);
char 						*convert_data_lst_tab(t_data *data);
int 						data_check_str_list_struct_cmd_loop(t_data *data, char *line_str);
/*IS CARACT*/
int							data_check_quote_caract(char *str, int *d);
int 						data_check_quote(char c);
int 						data_check_caract(char c);
int 						data_check_spec_caract(char c, char *caract);
void						data_create_list_struct(t_data *data, char **line_str, void **node, int *t);
int 						ft_is_caract_(char *str, char *c);
/*HISTORY*/
int							data_init_history_file(t_data *data);
int							data_check_and_create_history_cmd(t_data *data, char *cmd);
int							data_search_in_history_file(t_data *data, char *search_cmd);
void						data_uptdate_count_history_file(t_data *data);
int 						add_sentence_historic_node_to_list(t_data *data);
int 						add_sentence_historic_list_to_file(t_data *data);
void 						write_sentence_in_historic_file(t_data *data, char *cmd, int *nb_line, int opt);
int							ft_move_up_down_historic(t_data *data, int result);
/*LEXER*/
int 						ft_token_str_pos(t_data *data, char *line_str, t_list **token_list);
int 						ft_token_and_if(char *str, int *io, unsigned int *type, t_list **token_list);
int 						ft_token_or_if(char *str, int *io, unsigned int *type, t_list **token_list);
int 						ft_token_pipe(char *str, int *io, unsigned int *type, t_list **token_list);
int 						ft_token_semi(char *str, int *io, unsigned int *type, t_list **token_list);
int 						ft_token_redirection(char *str, int *io, unsigned int *type, t_list **token_list);
void 						data_check_is_token_cmd(t_list **token_list, char *line_str, int start, int size);
int 						data_check_is_token_operator(t_list **token_list, unsigned int type, char *line_str, int pos);
int 						parse_quote_and_double_quote(t_data *data);
int 						ft_is_redirection(t_list **token_list, char *line_str, int i, unsigned int *type);
void 						data_check_is_token_cmd(t_list **token_list, char *line_str, int start, int size);
int 						ft_error_token(unsigned int type);
struct s_token_priority		**data_construct_token_priority_tab(t_data *data);
/*EXEC*/
int							exec_cmd_node_pipe(t_data *data, t_list *prev, t_list *next, int *pfd);
int							exec_cmd_node(t_data *data, t_list *cur);
/*TOOLS*/
t_list						*ft_move_at_list(t_data *data, t_list **lst, int pos);
void						print_lst_line(t_data *data, t_list *lst);
void 						print_list_node_cmd(t_data *data, t_list *lst);
void 						print_tab(t_data *data, char **str_tab);
void 						count_list_cmd(t_data *data, t_list *lst);
int 						ft_print_token(t_list **token_lst);
/*CLEAN CARACT*/
char 						**data_split_to_tab(t_data *data, char *line_str, char *caract);
//char 				**data_split_to_tab(char *line_str, char *caract);
























#endif
