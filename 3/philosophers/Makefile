# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihogben <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 14:53:59 by ihogben           #+#    #+#              #
#    Updated: 2023/09/26 14:54:00 by ihogben          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = philosophers

SOURCES_DIR = ./src/

SOURCES_LIST =	*
				
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

CFILES	= $(SOURCES:%=%.c)

OFILES	= $(SOURCES:%=%.o)

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L./libft

LLIBS = -lft

LIBFT = libft/libft.a

LIBFTMAKE = $(MAKE) -C libft

all: $(NAME)

$(NAME): $(CFILES) $(LIBFT)
	gcc $(CFILES) -o $(NAME) $(FLAGS) $(LFLAGS) $(LLIBS)

%.o: %.c
	gcc -c $< -o $@ $(FLAGS) $(LINKS)

$(LIBFT):
	$(LIBFTMAKE)

clean:
	rm -f $(OFILES)
	$(LIBFTMAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFTMAKE) fclean

re: fclean all

.PHONY: all clean fclean re
