# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:40:21 by hcharia           #+#    #+#              #
#    Updated: 2023/03/02 16:39:02 by hcharia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
ARGS = -Iinclude -lglfw -L"/goinfre/hcharia/.brew/Cellar/glfw/3.3.8/lib"
libftdir = ./libft/
libft = $(libftdir)libft.a

MLX42_DIRECTORY = /Users/hcharia/MLX42/
MLX42 = $(MLX42_DIRECTORY)build/libmlx42.a
MLX42_HEADERS = $(MLX42_DIRECTORY)include/

CFILES =	so_long.c\
			get_next_line.c\
			get_next_line_utils.c\
			check_utils1.c\
			check_utils2.c\
			check_utils3.c\
			moveup.c\
			printingmap.c\
			positions.c\
			coinpostion.c\
			free.c\

OBJECTS=$(CFILES:.c=.o)
all : $(NAME)

%o:%c
	@$(CC) $(CFLAGS) -c $< -o $@

$(libft) :
	@$(MAKE) -sC $(libftdir)
	@$(MAKE) -sC $(libftdir) clean

$(NAME): $(libft) $(OBJECTS) 
	@$(CC) $(CFLAGS) $(OBJECTS) $(libft) $(MLX42) $(ARGS) -o so_long

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
