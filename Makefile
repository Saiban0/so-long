# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:10:26 by bchedru           #+#    #+#              #
#    Updated: 2024/05/23 14:56:59 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FILES =	 main

INC_FILES = -I libft
INC_ARCHIVES = lib/libft/libft.a

SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME) : $(OBJ)
	make -C lib/libft/
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES) $(CCFLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean :
	make -C lib/libft/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C lib/libft/ fclean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
