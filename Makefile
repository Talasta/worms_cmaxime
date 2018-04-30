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
FSC_C = ./src/controls/
FSC_MS = ./src/mlx_str/
FSC_P = ./src/physics/
FSC_A = ./src/actions/

LIB = ./lib/

SRC = main.c \
			w_controls.c \
			w_perlin_noise.c \
			w_image_controller.c \
			circle.c \
			explode_map.c \
			free_object.c \
			jump_controls.c \
			move_controls.c \
			scope_controls.c \
			shoot_grenade.c \
			timer_update.c \
			actions.c \
			refresh.c \
			turn_timer.c \
			collision_mask.c \
			collision_recalculate_pos.c \
			physics_update.c \
			w_map_gen.c \
			generate_antialiasing.c \
			generate_erosion.c \
			generate_grass.c \
			generate_kernel.c \
			generate_map.c \
			generate_perlin.c \
			generate_texture.c \
			scale_map.c

OBJ = $(SRC:%.c=%.o)

VPATH = ./src/:./src/maping/:./src/controls/:./src/mlx_str/\
			:./src/physics/:./src/actions/:

DEP = ./Makefile \
		$(INC)/worms.h \
	  $(INC)/stc_worms.h

MLX = -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(DEP)
	$(MAKE) -C libft
	gcc $(OBJ) $(OBJ_M) -o $(NAME) -L $(LIB) -lft $(MLX) $(FLAG)
	@echo "./worms compiled ..."

%.o: %.c
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
