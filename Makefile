# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 11:40:32 by lgosselk          #+#    #+#              #
#    Updated: 2024/01/19 13:08:30 by lgosselk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m

SRCS	=	src/main.c src/game_map.c src/game_free.c src/game_init.c \
			src/game_utils.c src/game_errors.c src/game_utils_2.c src/game_sprites.c \
			src/game_movement.c src/game_resolver.c src/game_sprites_2.c \
			src/game_map_utils.c src/game_enem_move.c src/game_init_utils.c \
			src/game_init_utils_3.c src/game_init_utils_2.c src/game_movement_utils.c \
			src/game_enem_move_utils.c src/game_enem_move_utils_3.c src/game_enem_move_utils_2.c \

OBJS = $(SRCS:.c=.o)

INC_DIR	= ./includes

CC = gcc

MF = Makefile

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

LIBFT_PATH = ./libft/libft.a

HEADER_FILE = $(INC_DIR)/so_long.h

GFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

GPATH = ./minilibx

MLX_PATH = $(GPATH)/libmlx.a

all : _libft _mlx $(NAME)

$(NAME) : $(MF) $(OBJS) $(LIBFT_PATH) $(MLX_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(MLX_PATH) $(GFLAGS) -o $(NAME) 
	@echo "\n${GREEN} Compilation of so_long success ${END}"

%.o : %.c $(HEADER_FILE) $(MF)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

clean :
	@make clean -C ./libft
	@make clean -C $(GPATH)
	@rm -f $(OBJS)
	@echo "${YELLOW} All objects files of so_long have been deleted ${END}"

fclean : clean
	@make fclean -C ./libft
	@make clean -C $(GPATH)
	@rm -f $(NAME)
	@echo "${YELLOW} Cleaning of so_long has been done ${END}"

re: fclean all

_libft :
	@make -C ./libft

_mlx :
	@make -C $(GPATH)

.PHONY:	all clean fclean re