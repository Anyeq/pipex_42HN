# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 11:03:25 by asando            #+#    #+#              #
#    Updated: 2025/09/05 14:28:09 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= cc
DEBUG ?= 0

HEADER = includes
LIBFT_HEADER = ./lib/libft/include

CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -I$(LIBFT_HEADER)

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
endif

SRC_DIR = src
SRCS = pipex.c pipex_utils.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = pipex

all: $(NAME)
	@echo "Program is compiled"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Program deleted"
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re:
	@$(MAKE) fclean
	@$(MAKE) all

debug:
	@$(MAKE) DEBUG=1 re

.PHONY: all clean fclean re debug
