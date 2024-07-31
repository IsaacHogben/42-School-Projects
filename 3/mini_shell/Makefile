# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmount <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 14:38:07 by rmount            #+#    #+#              #
#    Updated: 2023/12/03 21:10:25 by rmount           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBRARY = -lft -lreadline

SRCS = 	./srcs/main.c \
		./srcs/execute.c \
		./srcs/command.c \
		./srcs/command_list.c \
		./srcs/arguments/args_utils.c \
		./srcs/arguments/args_utils2.c \
		./srcs/arguments/args_utils3.c \
		./srcs/arguments/split_args.c \
		./srcs/builtins/builtin_cd.c \
		./srcs/builtins/builtins_check.c \
		./srcs/builtins/builtins.c \
		./srcs/environment/convert_envp.c \
		./srcs/environment/env_free.c \
		./srcs/environment/env_list.c \
		./srcs/environment/env_utils.c \
		./srcs/environment/expand_env.c \
		./srcs/error/error_handling.c \
		./srcs/initialise/initialise.c \
		./srcs/prompt/prompt_utils.c \
		./srcs/prompt/prompt.c \
		./srcs/redirects/remove_redir.c \
		./srcs/redirects/std_in_out.c \
		./srcs/redirects/std_sort.c \
		./srcs/signals/sig_handling_utils.c \
		./srcs/signals/sig_handling.c \
		./srcs/utils/array_utils.c \
		./srcs/utils/free_utils.c \
		./srcs/utils/realloc_utils.c

INCS = ./includes
READLINE_INCS = /usr/local/opt/readline/include

ROOT_DIR = ${shell pwd}
LIBFT_DIR = ${ROOT_DIR}/libft
READLINE_DIR = /usr/local/opt/readline/lib

#  for Rikki's comp
READLINE_DIR_M1 = /opt/homebrew/Cellar/readline/8.2.1/lib
READLINE_INCS_M1 = /opt/homebrew/Cellar/readline/8.2.1/include

${NAME}: all

all:
	@echo "Compiling libft"
	@make bonus -C ${LIBFT_DIR}
	@${CC} ${CFLAGS} -I ${INCS} -I ${READLINE_INCS} ${SRCS} -o ${NAME} -L ${LIBFT_DIR} -L ${READLINE_DIR} ${LIBRARY}
	@echo "./${NAME} compiled successfully."

m1:
	@echo "Compiling libft"
	@make bonus -C ${LIBFT_DIR}
	@${CC} ${CFLAGS} -I ${INCS} -I ${READLINE_INCS_M1} ${SRCS} -o ${NAME} -L ${LIBFT_DIR} -L ${READLINE_DIR_M1} ${LIBRARY}
	@echo "./${NAME} compiled successfully."

clean:
	@echo "Removing .o files"
	@${RM} ${LIBFT_DIR}/*.o
	@echo "Rub a dub dub"

fclean: clean
	@echo "Removing .a files"
	@${RM} ${LIBFT_DIR}/*.a 
	@${RM} ${NAME}
	@echo "Shiny!"

re: fclean all

rem1: fclean m1

.PHONY: all m1 clean fclean re rem1
