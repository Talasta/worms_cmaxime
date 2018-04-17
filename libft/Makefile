# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:26:31 by blefeuvr          #+#    #+#              #
#    Updated: 2018/03/12 15:43:15 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
# Compiler #
CC = gcc
CPPFLAGS = -Iinclude
CFLAGS = -Werror -Wall -Wextra
OBJ_PATH = obj/
SRC_FT =\
	ft_abs.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_atoi_base_max.c\
	ft_bzero.c\
	ft_cinstr.c\
	ft_gnl.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lstadd.c\
	ft_lstaddend.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c\
	ft_lstsort.c\
	ft_max.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memclen.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memrealloc.c\
	ft_memset.c\
	ft_min.c\
	ft_pow.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_sqrt.c\
	ft_sqrtup.c\
	ft_strcat.c\
	ft_strccount.c\
	ft_strccpy.c\
	ft_realloc.c\
	ft_strchr.c\
	ft_strclen.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_strext.c\
	ft_strextend.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strndup.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strrepl.c\
	ft_strsplit.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_ulstadd_head.c\
	ft_ulstadd_tail.c\
	ft_ulstdel.c\
	ft_ulstdelone.c\
	ft_ulstnew.c\
	ft_ulstset_head.c\
	ft_ulstset_tail.c\
	ft_ulstsize.c\
	ft_ulsttsize.c
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
VPATH = ./src/conv/:./src/printf/types/:./src/is/:./src/list/:./src/math/:\
	./src/mem/:./src/printf/:./src/put/:./src/str/:./src/gnl/:\
	./src/printf/specs/:./src/printf/utils/
DEPS = include/*.h Makefile

.PHONY: all, clean, fclean, re

.SUFFIXES:

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	ar rc $@ $^
	ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
