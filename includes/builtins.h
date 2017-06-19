/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:20:22 by gbourson          #+#    #+#             */
/*   Updated: 2017/06/15 16:29:37 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define OPT_ENV "i"
# define BUILD_FIND 0
# define BUILD_EXE 1

typedef	int			(*t_func)(t_data *data, t_list **env_lst, char **line);
typedef	void		(*t_option)(t_list *env_lst, char **line);

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

/*BUILTINS DRIVE*/
int					buil_drive(t_data *data, t_list **env_lst, char **line, int opt);
/*BUILTINS*/
void				parse_line_builtins(t_data *data, t_list **env_lst, char **line);
/*BUILTINS ENV*/
int					builtin_env(t_data *data, t_list **env_lst, char **line);
int					builtin_unsetenv(t_data *data, t_list **env_lst, char **line);
int					builtin_setenv(t_data *data, t_list **env_lst, char **line);
/*BUILTINS CD*/
int					builtin_cd(t_data *data, t_list **env_lst, char **line);
char				*builtin_cd_special_caract(t_list **env_lst, char **line);
char				*builtin_cd_special_caract_home(t_list **env_lst, char **line);
char				*builtin_cd_special_caract_home_noline(t_list **env_lst, char **line);
int					ft_check_move(char *path);
/*BUILTINS ECHO*/
int					builtin_echo(t_data *data, t_list **env_lst, char **line);
void				builtin_echo_use_e(t_list *env_lst, char **line);
void				builtin_echo_use_n(t_list *env_lst, char **line);
void				builtin_echo_quote(t_list *env_lst, char **line);
/*BUILTINS EXIT*/
int					builtin_exit(t_data *data, t_list **env_lst, char **line);

#endif