# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 11:03:25 by asando            #+#    #+#              #
#    Updated: 2025/09/11 18:11:58 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= cc
DEBUG ?= 0
BONUS ?= 0

HEADER = includes
LIBFT_HEADER = ./lib/libft/include
GET_NEXT_LINE_HEADER = ./lib/get_next_line/include

CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -I$(LIBFT_HEADER) \
		 -I$(GET_NEXT_LINE_HEADER)

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
endif

SRC_DIR = src
SRCS = pipex.c pipex_utils.c
ifeq ($(BONUS), 1)
	SRCS = pipex_bonus.c pipex_bonus_utils.c child_process_utils_bonus.c \
		   pipex_utils.c
endif

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
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

bonus:
	@$(MAKE) --no-print-directory BONUS=1 fclean
	@$(MAKE) --no-print-directory BONUS=1 all
	@echo "Bonus version compiled to pipex"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Program deleted"
	@rm -rf $(NAME)
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all

debug:
	@$(MAKE) --no-print-directory DEBUG=1 BONUS=1 re

.PHONY: all clean fclean re debug bonus
