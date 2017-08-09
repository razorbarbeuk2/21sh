# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:48:45 by gbourson          #+#    #+#              #
#    Updated: 2017/07/06 17:03:02 by RAZOR            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#Define FT_COUNT
_FT_COUNT_SRC		=	ft_count_number.c ft_count_tab.c ft_count_word.c

FT_COUNT_SRC		=	$(addprefix ft_count/,$(_FT_COUNT_SRC))
_FT_COUNT_SRC_O		=	$(patsubst %.c,%.o, $(_FT_COUNT_SRC))
FT_COUNT_SRC_O		=	$(addprefix bin/,$(_FT_COUNT_SRC_O))

#Define FT_GET
_FT_GET_SRC			=	get_next_line.c

FT_GET_SRC			=	$(addprefix ft_get/,$(_FT_GET_SRC))
_FT_GET_SRC_O		=	$(patsubst %.c,%.o, $(_FT_GET_SRC))
FT_GET_SRC_O		=	$(addprefix bin/,$(_FT_GET_SRC_O))

#Define FT_IS
_FT_IS_SRC			=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
						ft_isprint.c

FT_IS_SRC			=	$(addprefix ft_is/,$(_FT_IS_SRC))
_FT_IS_SRC_O		=	$(patsubst %.c,%.o, $(_FT_IS_SRC))
FT_IS_SRC_O			=	$(addprefix bin/,$(_FT_IS_SRC_O))

#Define FT_LIST
_FT_LIST_SRC		=	ft_lst_count.c ft_lstadd.c ft_lstadd_back.c ft_lstdel.c\
						ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lst_swap_content.c

FT_LIST_SRC			=	$(addprefix ft_list/,$(_FT_LIST_SRC))
_FT_LIST_SRC_O		=	$(patsubst %.c,%.o, $(_FT_LIST_SRC))
FT_LIST_SRC_O		=	$(addprefix bin/,$(_FT_LIST_SRC_O))

#Define FT_MATH
_FT_MATH_SRC		=	ft_atoi.c ft_itoa.c ft_power.c\

FT_MATH_SRC			=	$(addprefix ft_math/,$(_FT_MATH_SRC))
_FT_MATH_SRC_O		=	$(patsubst %.c,%.o, $(_FT_MATH_SRC))
FT_MATH_SRC_O		=	$(addprefix bin/,$(_FT_MATH_SRC_O))

#Define FT_MEM
_FT_MEM_SRC			=	ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
						ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c

FT_MEM_SRC			=	$(addprefix ft_mem/,$(_FT_MEM_SRC))
_FT_MEM_SRC_O		=	$(patsubst %.c,%.o, $(_FT_MEM_SRC))
FT_MEM_SRC_O		=	$(addprefix bin/,$(_FT_MEM_SRC_O))

#Define FT_PUT
_FT_PUT_SRC			=	ft_putchar.c ft_putchar_fd.c ft_putendl.c\
						ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c

FT_PUT_SRC			=	$(addprefix ft_put/,$(_FT_PUT_SRC))
_FT_PUT_SRC_O		=	$(patsubst %.c,%.o, $(_FT_PUT_SRC))
FT_PUT_SRC_O		=	$(addprefix bin/,$(_FT_PUT_SRC_O))

#Define FT_STR
_FT_STR_SRC			=	ft_str_to_tab.c ft_strcat.c ft_strchr.c ft_strclr.c\
						ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
						ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
						ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
						ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
						ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c

FT_STR_SRC			=	$(addprefix ft_str/,$(_FT_STR_SRC))
_FT_STR_SRC_O		=	$(patsubst %.c,%.o, $(_FT_STR_SRC))
FT_STR_SRC_O		=	$(addprefix bin/,$(_FT_STR_SRC_O))

#Define FT_TO
_FT_TO_SRC			=	ft_tolower.c ft_tolower_verif.c ft_toupper.c ft_toupper_verif.c\

FT_TO_SRC			=	$(addprefix ft_to/,$(_FT_TO_SRC))
_FT_TO_SRC_O		=	$(patsubst %.c,%.o, $(_FT_TO_SRC))
FT_TO_SRC_O			=	$(addprefix bin/,$(_FT_TO_SRC_O))

#Define FT_ERR
_FT_ERR_SRC			=	ft_print_err.c\

FT_ERR_SRC			=	$(addprefix ft_err/,$(_FT_ERR_SRC))
_FT_ERR_SRC_O		=	$(patsubst %.c,%.o, $(_FT_ERR_SRC))
FT_ERR_SRC_O		=	$(addprefix bin/,$(_FT_ERR_SRC_O))

#Define Global LIBFT files
LIBFT_SRC			=	$(FT_COUNT_SRC) $(FT_GET_SRC) $(FT_IS_SRC) $(FT_LIST_SRC)\
						$(FT_MATH_SRC) $(FT_MEM_SRC) $(FT_PUT_SRC) $(FT_STR_SRC)\
						$(FT_TO_SRC) $(FT_ERR_SRC)
_LIBFT_O_FILES		=	$(_FT_COUNT_SRC_O) $(_FT_GET_SRC_O) $(_FT_IS_SRC_O) $(_FT_LIST_SRC_O)\
						$(_FT_MATH_SRC_O) $(_FT_MEM_SRC_O) $(_FT_PUT_SRC_O) $(_FT_STR_SRC_O)\
						$(_FT_TO_SRC_O) $(_FT_ERR_SRC_O)
LIBFT_O_FILES		=	$(FT_COUNT_SRC_O) $(FT_GET_SRC_O) $(FT_IS_SRC_O) $(FT_LIST_SRC_O)\
						$(FT_MATH_SRC_O) $(FT_MEM_SRC_O) $(FT_PUT_SRC_O) $(FT_STR_SRC_O)\
						$(FT_TO_SRC_O) $(FT_ERR_SRC_O)
CFLAGS				=	-Wall -Wextra -Werror -ggdb -g

all : $(NAME)

$(NAME) :
		@mkdir bin
		@gcc -c $(CFLAGS) $(LIBFT_SRC)
		@ar rc $(NAME) $(_LIBFT_O_FILES)
		@ranlib $(NAME)
		@mv $(_LIBFT_O_FILES) bin/
		@echo "Libft"

clean :
	@rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)
	@rm -f $(NAME)

re : fclean all
