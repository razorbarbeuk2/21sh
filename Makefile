# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/11 13:32:06 by RAZOR             #+#    #+#              #
#    Updated: 2017/10/06 19:45:19 by gbourson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		=	21sh
LIB			=	./libft/libft.a ./log/liblogger.a
SRC_NAME 	=	init/init_data.c \
				init/init_prompt.c \
				init/init_env.c \
				init/init_env_list.c \
				init/init_term.c \
				init/term_reset.c \
				env/iter_elem_env.c \
				env/del_elem_env.c \
				env/edit_elem_env.c \
				env/env_elem_search.c \
				text_line/listen_cursor.c \
				text_line/motion_cursor_ADD.c \
				text_line/motion_cursor_DEL.c \
				text_line/motion_cursor_LR.c \
				text_line/motion_cursor_HE.c \
				text_line/motion_cursor_ALT_UD.c \
				text_line/motion_cursor_ALT_W_LR.c \
				text_line/motion_cursor_CPY.c \
				text_line/motion_cursor_RST.c \
				text_line/motion_list.c \
				text_line/prompt_position.c \
				tokens/token_check_init.c \
				tokens/token_check_redir.c \
				tokens/token_check_redir_error.c \
				tokens/token_create_data_type.c \
				tokens/token_and_if.c \
				tokens/token_or_if.c \
				tokens/token_pipe.c \
				tokens/token_semicol.c \
				data/data_str_check_quote_cmd.c \
				data/data_str_clean_caract.c \
				data/data_lst_to_tab.c \
				data/data_str_insert_caract.c \
				data/data_str_del_caract.c \
				data/data_str_cpy.c \
				data/data_create_cmd_list.c \
				data/data_sep_is_caract.c \
				data/data_exec_cmd.c \
				data/data_create_ast.c \
				exec/exec_and_if.c \
				exec/exec_cmd.c \
				exec/exec_dsemi.c \
				exec/exec_or_if.c \
				exec/exec_pipe.c \
				exec/exec_redir.c \
				exec/exec.c \
				exec/exec_parse_line_builtins.c \
				exec/exec_get_access.c \
				exec/exec_get_path.c \
				builtins/builtins_check_args.c \
				builtins/builtins_env.c \
				builtins/builtins_envcpy.c \
				builtins/builtins_set_unset_env.c \
				builtins/builtins_cd.c \
				builtins/builtins_cd_init.c \
				builtins/builtins_cd_check_caract.c \
				builtins/builtins_cd_move.c \
				builtins/builtins_echo.c \
				builtins/builtins_echo_opt.c \
				builtins/builtins_exit.c \
				builtins/options/parse_option.c \
				history/data_create_history_files.c \
				history/data_up_down_history.c \
				history/data_create_history_node_to_list.c \
				history/data_update_history_cmd.c \
				tools/tools_count_spec_caract.c \
				tools/tools_list_create_node.c \
				tools/tools_free.c \
				tools/tools_list.c \
				tools/tools_termcaps.c \
				tools/tools_print.c \
				tools/tools_count.c \
				free/free_ft.c \
				free/free_struct.c \
				free/free_struct_cmd.c \
				print/print_error.c \
				main.c \
				parse_options.c \
				prompt.c \

				

SRC			=	$(addprefix srcs/, $(SRC_NAME))
INCLUDES	=	-I./libft/includes/ -I./includes -I ./log/incs
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-g -Werror -Wall -Wextra

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME) : $(OBJ)
	@make -C libft
	@make -C log
	@gcc $(CFLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME) -ltermcap
	@echo "Tu as compilé"

clean :
	@make -C libft clean
	@rm -f $(OBJ)
	@rm -fr ./libft/bin
	@echo "Tu as clean!"

fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "C'est encore plus propre..."

re : 	fclean all

leaks1 :
	while true ; do leaks 21sh ; sleep 3 ; clear ; done

.PHONY: all, clean, fclean, re
