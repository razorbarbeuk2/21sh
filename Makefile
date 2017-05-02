# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/11 13:32:06 by RAZOR             #+#    #+#              #
#    Updated: 2017/05/02 16:38:27 by gbourson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		=	21sh
LIB			=	./libft/libft.a
SRC_NAME 	=	builtins/builtins_init.c \
				builtins/builtins_env.c \
				builtins/builtins_set_unset_env.c \
				builtins/builtins_cd.c \
				builtins/builtins_cd_move.c \
				builtins/builtins_echo.c \
				builtins/builtins_echo_opt.c \
				builtins/builtins_exit.c \
				env/init_env.c \
				env/iter_elem_env.c \
				env/del_elem_env.c \
				env/edit_elem_env.c \
				term/init_term.c \
				text_line/listen_cursor.c \
				text_line/motion_cursor_LR.c \
				text_line/motion_cursor_HE.c \
				text_line/motion_cursor_ALT_UD.c \
				text_line/motion_list.c \
				text_line/prompt_position.c \
				text_line/prompt_insert_caract.c \
				text_line/prompt_new_line_bottom.c \
				text_line/data_str_insert_caract.c \
				text_line/data_str_del_caract.c \
				fork/access.c \
				fork/fork.c \
				fork/get_exe_path.c \
				print/print_error.c \
				main.c \
				parse_options.c \
				prompt.c \
				search.c \
				tools_free.c \
				tools_list.c \
				tools_termcaps.c \

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
