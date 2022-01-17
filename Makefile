# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 19:52:35 by jhermon-          #+#    #+#              #
#    Updated: 2022/01/14 17:34:29 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c\
	  		open_map.c\
			check_map.c\
			check_map_utils.c\
			error.c\
	 	 	get_next_line.c\
		 	get_next_line_utils.c\
			window.c\
			print_map.c\
			ft_itoa.c\
			hooks.c\
			draw_player.c\

CC = gcc

NAME = so_long

OBJ = $(SRC:.c=.o)
	
FLAGS = -Wall -Wextra -Werror -Imlx

LIBX = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) 
	     $(CC) $(FLAGS) $(LIBX) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
		$(CC) $(FLAGS) -c $(SRC)

exe: all
		./$(NAME) maps/big_2.ber

norm: 
		norminette -d so_long.c open_map.c check_map.c check_map_utils.c error.c get_next_line.c get_next_line_utils.c window.c print_map.c ft_itoa.c hooks.c draw_player.c so_long.h gnl.h

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
