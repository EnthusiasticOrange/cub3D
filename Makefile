# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexey <alexey@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 15:05:45 by mjuli             #+#    #+#              #
#    Updated: 2022/06/07 01:00:14 by alexey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
FLAGS = -Wall -Wextra -Werror
LIBFT = -I libft -L libft -lft
MLX = -I mlx -L mlx -lmlx -lm -framework OpenGL -framework AppKit
SRC = gnl/get_next_line.c gnl/get_next_line_utils.c \
	process_file.c process_elements.c process_map.c check_map.c \
	player.c visible_sprites.c dda.c draw_wall.c draw_sprites.c draw.c \
	key_hook.c util.c mlx_init.c clear_cub3d.c draw_bmp.c main.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

%.o: %.c cub3d.h
	gcc $(FLAGS) -c -o $@ $< -I libft -I mlx

$(NAME): $(OBJ)
	cd mlx && make
	cd libft && make
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
	cp mlx/libmlx.a .

clean:
	cd mlx && make clean
	cd libft && make clean
	rm -f $(OBJ)

fclean: clean
	cd libft && make fclean
	rm -f libmlx.a
	rm -f $(NAME)

bonus: $(NAME)

re: fclean all

