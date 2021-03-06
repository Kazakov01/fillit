# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquincy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 00:18:01 by jquincy           #+#    #+#              #
#    Updated: 2019/11/21 18:19:33 by jquincy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit 

# directories
SRC_DIR	:= ./src
INC_DIR	:= ./inc
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft

SRC		:= main.c \
		   read.c \
		   solve.c \
		   map.c \
		   tetr.c
OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror #-pedantic -std=c99
#OFLAGS	:= -pipe -flto
#CFLAGS	+= $(OFLAGS)

L_FT	:= $(LIB_DIR)/libft

include $(L_FT)/libft.mk

.PHONY: all clean fclean re

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(L_FT) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(L_FT) re --no-print-directory
	@$(MAKE) re --no-print-directory
