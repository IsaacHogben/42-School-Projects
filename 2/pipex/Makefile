# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihogben <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 14:53:59 by ihogben           #+#    #+#              #
#    Updated: 2023/08/21 14:54:00 by ihogben          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = pipex

SOURCES_DIR = ./src/

SOURCES_LIST =	*
				
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

CFILES	= $(SOURCES:%=%.c)

OFILES	= $(SOURCES:%=%.o)

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L./ft_printf -L./libft

LLIBS = -lprintf -lft

PRINTF = ft_printf/libprintf.a

PRINTFMAKE = $(MAKE) -C ft_printf

LIBFT = libft/libft.a

LIBFTMAKE = $(MAKE) -C libft

all: $(NAME)

$(NAME): $(CFILES) $(PRINTF) $(LIBFT)
	gcc $(CFILES) -o $(NAME) $(FLAGS) $(LFLAGS) $(LLIBS)

%.o: %.c
	gcc -c $< -o $@ $(FLAGS) $(LINKS)

$(PRINTF):
	$(PRINTFMAKE)

$(LIBFT):
	$(LIBFTMAKE)

clean:
	rm -f $(OFILES)
	$(PRINTFMAKE) clean
	$(LIBFTMAKE) clean

fclean: clean
	rm -f $(NAME)
	$(PRINTFMAKE) fclean
	$(LIBFTMAKE) fclean

re: fclean all

.PHONY: all clean fclean re
