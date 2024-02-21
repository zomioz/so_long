# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 19:30:29 by pirulenc          #+#    #+#              #
#    Updated: 2024/02/16 21:28:17 by pirulenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall \
			-Werror \
			-Wextra \
			-g

SOURCES = ./sources/main.c \
		./sources/ft_check.c \
		./sources/ft_create_map.c \
		./sources/ft_utils.c \
		./sources/ft_flood_file.c \
		./sources/ft_graphic.c \
		./sources/ft_init.c \
		./sources/ft_put_wall.c \
		./sources/ft_loop.c \
		./sources/ft_moove.c \
		./sources/ft_moove_bis.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@${MAKE} -j -C ./libft -s
	@echo LIBFT COMPILED : ✓
	@$(CC) $(CFLAGS) $(OBJECTS) ./libft/libft.a ./MacroLibX/libmlx.so -lSDL2 -o $(NAME)
	@echo SO_LONG COMPILED : ✓

clean:
	@${MAKE} -C ./libft clean -s
	@echo LIBFT CLEAN : ✓
	@rm -f $(OBJECTS)
	@echo SO_LONG CLEAN : ✓

fclean: clean
	@${MAKE} -C ./libft fclean -s
	@rm -f $(NAME)

re: fclean all

PHONY: all clean fclean re
