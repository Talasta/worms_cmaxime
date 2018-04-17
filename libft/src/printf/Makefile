# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:26:31 by blefeuvr          #+#    #+#              #
#    Updated: 2018/01/30 15:31:50 by blefeuvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.c
OBJ_PATH = obj/
CPPFLAGS = -Iinclude
CC = gcc
FLAGS = -Werror -Wall -Wextra
SRC_PF = \
	ft_printf.c
SRC_UTILS = \
	pf_itoa.c\
	pf_itoa_base.c
SRC_TYPES = \
	d.c\
	o.c\
	x.c\
	p.c\
	c.c\
	s.c\
	def.c\
	u.c
SRC_SPECS = \
	minus.c\
	plus.c\
	percent.c\
	space.c\
	htag.c\
	num.c\
	point.c\
	flag.c
SRC_NAME = $(SRC_PF) $(SRC_SPECS) $(SRC_UTILS) $(SRC_FT) $(SRC_TYPES)
SRC = $(addprefix /,$(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
VPATH = ./src/:./libft/:./src/specs/:./src/types/:./src/utils/
DEPS = include/* Makefile

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	@$(call color_exec,$(CLINK_T),$(CLINK),"Creating libftprintf.a lib",\
		ar rc $@ $^)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: %.c Makefile
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(call color_exec,$(COBJ_T),$(COBJ),"Object: $@",\
		$(CC) $(FLAGS) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<)

clean:
	@$(call color_exec,$(CCLEAN_T),$(CCLEAN),"Clean:",\
		$(RM) $(OBJ))
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@$(call color_exec,$(CCLEAN_T),$(CCLEAN),"Fclean:",\
		$(RM) $(NAME))

re: fclean all
