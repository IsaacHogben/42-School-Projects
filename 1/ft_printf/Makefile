# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihogben <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 12:26:28 by ihogben           #+#    #+#              #
#    Updated: 2023/07/20 12:26:54 by ihogben          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

files 	   = *

Compiler	= gcc

CFlags	= -Wall -Wextra -Werror

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

NAME	= libftprintf.a

all: $(NAME)

$(NAME):
	$(Compiler) $(CFlags) -c $(CFILES) -I./
	ar -rc $(NAME) $(OFILES)

# %.o: $(CFILES)
# 		$(Compiler) $(CFlags) -c -o $@ $<

clean:
	# rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
