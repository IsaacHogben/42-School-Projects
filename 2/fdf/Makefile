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
NAME = fdf

SOURCES_DIR = ./src/

SOURCES_LIST =	main.c\
				color.c\
				input.c\
				draw.c\
				structs.c\
				data.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				view.c
				
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L./libft -L./minilibx

LLIBS = -lmlx -lft -framework OpenGL -framework Appkit

LIBFT = libft/libft.a

LIBFTMAKE = $(MAKE) -C libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	gcc $(OBJECTS) -o $(NAME) $(FLAGS) $(LFLAGS) $(LLIBS)

%.o: %.c
	gcc -c $< -o $@ $(FLAGS) $(LINKS)

libft/libft.a:
	$(LIBFTMAKE)
	
clean:
	rm -f $(OBJECTS)
	$(LIBFTMAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFTMAKE) fclean

re: fclean all

.PHONY: all clean fclean re
