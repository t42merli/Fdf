# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 16:12:14 by tmerli            #+#    #+#              #
#    Updated: 2017/12/18 17:09:49 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRC =	ft_display.c ft_free.c ft_map.c \
		ft_image.c ft_movement.c calc.c \
		fdf.c get_next_line.c \

HEAD = fdf.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(HEAD) $(SRC)
	make -C libft
	make -C minilibx_macos
	gcc $(FLAGS) -o $(NAME) $(SRC) libft/libft.a -Lminilibx_macos -lmlx -framework OpenGL -framework Appkit

clean :
	make clean -C libft
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re : fclean all
