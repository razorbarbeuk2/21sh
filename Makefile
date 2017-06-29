# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/11 13:32:06 by RAZOR             #+#    #+#              #
#    Updated: 2017/06/29 16:31:42 by gbourson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		=	21sh
LIB			=	./libft/libft.a
SRC_NAME 	=	init/init_data.c \
				init/init_prompt.c \
				init/init_env.c \
				init/init_term.c \
				init/term_reset.c \
				init/init_cmd.c \
				builtins/builtins_init.c \
				builtins/builtins_env.c \
				builtins/builtins_set_unset_env.c \
				builtins/builtins_cd.c \
				builtins/builtins_cd_move.c \
				builtins/builtins_echo.c \
				builtins/builtins_echo_opt.c \
				builtins/builtins_exit.c \
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
				data/data_str_check_opt_cmd.c \
				data/data_str_clean_caract.c \
				data/data_str_insert_caract.c \
				data/data_str_del_caract.c \
				data/data_create_cmd_node.c \
				data/data_create_cmd_list.c \
				data/data_sep_is_caract.c \
				data/data_exec_cmd.c \
				data/data_exec_pipe.c \
				history/data_create_history_files.c \
				history/data_up_down_history.c \
				history/data_create_history_node_to_list.c \
				tools/tools_count_spec_caract.c \
				tools/tools_list_create_node.c \
				tools/tools_free.c \
				tools/tools_list.c \
				tools/tools_termcaps.c \
				tools/tools_print.c \
				tools/tools_count.c \
				fork/access.c \
				fork/fork.c \
				fork/get_exe_path.c \
				free/free_ft.c \
				free/free_struct.c \
				free/free_struct_cmd.c \
				print/print_error.c \
				main.c \
				parse_options.c \
				prompt.c \

				

SRC			=	$(addprefix srcs/, $(SRC_NAME))
INCLUDES	=	-I./libft/includes/ -I./includes
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-g -Werror -Wall -Wextra

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME) : $(OBJ)
	@make -C libft
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

.PHONY: all, clean, fclean, re
