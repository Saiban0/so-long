# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:10:26 by bchedru           #+#    #+#              #
#    Updated: 2024/06/14 19:09:56 by bchedru          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FILES =	 srcs/main srcs/parsing srcs/errors srcs/init_image srcs/player_movements srcs/game_loop srcs/utils

INC_FILES = -I libft
INC_ARCHIVES = lib/libft/libft.a lib/libmlx42.a

SRC = $(addsuffix .c,$(FILES))
OBJ = $(addsuffix .o,$(FILES))

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iincludes -g
LFLAGS = -Llib -lmlx42 -ldl -lglfw -lXext -lX11 -lm -lpthread

all: $(NAME)

$(NAME) : $(OBJ)
	make -C lib/libft/
	$(CC) -o $@ $(OBJ) $(INC_ARCHIVES) $(CCFLAGS) $(LFLAGS)

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
