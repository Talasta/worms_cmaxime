# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 12:25:05 by cmaxime           #+#    #+#              #
#    Updated: 2018/03/14 12:49:35 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = worms

FLAG = -Wall -Werror -Wextra
INC = ./include
FSC = ./src/
FSC_M = ./src/maping/
LIB = ./lib/

SRC = main.c \
			w_controls.c \
			w_perlin_noise.c \
			w_image_controller.c \
			circle.c \
			w_map_gen.c

SRC_M = generate_antialiasing.c \
				generate_erosion.c \
				generate_grass.c \
				generate_kernel.c \
				generate_map.c \
				generate_perlin.c \
				generate_texture.c \
				scale_map.c

OBJ_M = $(SRC_M:%.c=%.o)
OBJ = $(SRC:%.c=%.o)

DEP = ./Makefile \
		$(INC)/worms.h \
	  $(INC)/stc_worms.h

MLX = -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_M) $(DEP)
	$(MAKE) -C libft
	gcc $(OBJ) $(OBJ_M) -o $(NAME) -L $(LIB) -lft $(MLX) $(FLAG)
	@echo "./worms compiled ..."

%.o: $(FSC)%.c
	gcc -I $(INC) -c $< -o $@ $(FLAG)

%.o: $(FSC_M)%.c
	gcc -I $(INC) -c $< -o $@ $(FLAG)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ) $(OBJ_M)
	@echo "Objets removed ..."

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	@echo "./worms (exec) removed ..."

re: fclean all

.PHONY: re all clean fclean
