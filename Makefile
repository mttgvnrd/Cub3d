# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 12:05:42 by mgiovana          #+#    #+#              #
#    Updated: 2024/03/05 12:05:47 by mgiovana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

SRC = main.c init.c exit.c parse.c rgb.c square.c utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIE

LINK = ./minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm

LIBFT = ./src/libft/libft.a

all: lib $(NAME)

lib:
	make -s -C src/libft

$(NAME): $(OBJ)
	@echo "\033[32mCompiling $(NAME)"
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(LINK) -o $(NAME)
	@echo "Compiled\033[0;37m"

clean:
	@echo "\033[0;31mCleaning objects"
	@rm -rf $(OBJ)
	@make clean -s -C src/libft

fclean: clean
	@echo "\033[0;31mRemoving $(NAME)\033[0;37m"
	@rm -rf $(NAME)
	@make fclean -s -C src/libft

re: fclean all
