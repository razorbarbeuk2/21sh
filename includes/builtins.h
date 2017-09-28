/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:20:22 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/28 18:36:22 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define OPT_ENV "i"

typedef	int			(*t_func)(t_data *data, char **line);
typedef	void		(*t_option)(t_data *data, char **line);
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

typedef struct		s_buil
{
	char			*name;
	t_func			f;
}					t_buil;

/*BUILTINS DRIVE*/
int					buil_drive(t_data *data, t_list **env_lst, char **line);
/*BUILTINS*/
int					parse_line_builtins(t_data *data, t_list **env_lst, char **line);
int 				builtins_check_args(char **line, int num);
/*BUILTINS ENV*/
int					builtin_env(t_data *data, char **line);
t_list				*env_cpy(t_data *data);
int					builtin_unsetenv(t_data *data, char **line);
int					builtin_setenv(t_data *data, char **line);
/*BUILTINS CD*/
int					builtin_cd(t_data *data, char **line);
int					builtin_cd_special_caract_home(t_data *data, char **line);
char 				*builtin_cd_special_caract_slash(t_data *data, char *str);
char 				*builtin_cd_special_caract_return(t_data *data, char *str);
int					ft_check_move(char *path);
/*BUILTINS ECHO*/
int					builtin_echo(t_data *data, char **line);
void				builtin_echo_use_e(t_data *data, char **line);
void				builtin_echo_use_n(t_data *data, char **line);
void				builtin_echo_quote(t_data *data, char **line);
/*BUILTINS EXIT*/
int					builtin_exit(t_data *data, char **line);

#endif