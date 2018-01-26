# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 12:37:43 by dmisnich          #+#    #+#              #
#    Updated: 2018/01/26 11:39:24 by dmisnich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes/

SRCS =	src/main.c \
		src/file.c \
		src/draw_line.c \
		src/exit.c \
		src/rotate.c \
		src/key_key.c \
		src/move_fdf.c \
		src/key_dup.c \
		src/error.c \
		./get_next_line/get_next_line.c \



OBJ = $(SRCS:.c=.o)

#libft
LFT_DIR = ./libft/
LFT_LNK = -L $(LFT_DIR) -lft

#minilibx
MLX_DIR = ./miniLibX/
MLX_LNK = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_LNK) $(LFT_LNK) $(OBJ) -o $(NAME)

clean:
	make -C $(LFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f src/*.o

fclean: clean
	make -C $(LFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

