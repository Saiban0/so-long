# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:10:26 by bchedru           #+#    #+#              #
#    Updated: 2024/04/18 15:28:57 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FILES =	 main get_next_line get_next_line_utils

SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -O0 -g

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES) $(CCFLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
