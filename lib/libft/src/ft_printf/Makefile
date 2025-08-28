# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 22:07:48 by asando            #+#    #+#              #
#    Updated: 2025/08/10 15:43:58 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP = cc

HEADER = ../../include

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

SRCS = ft_count_digit_utils.c ft_parse.c ft_printf.c ft_putchar.c ft_putint.c \
	   ft_putnum_base.c ft_putptr.c ft_putstr.c ft_putunint.c \
	   ft_width_precision_utils.c ft_write_arg.c ft_printchar.c

DIROBJ = ../../obj/ft_printf

OBJS = $(SRCS:%.c=$(DIROBJ)/%.o)

NAME = libftprintf.a

LIBFT = ../../libft.a

all: $(NAME)
	@echo "ft_printf Build Completed"

bonus: all

$(NAME): $(OBJS) $(LIBFT)
	@ar crs $@ $^

$(DIROBJ)/%.o: %.c | $(DIROBJ)
	@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(DIROBJ):
	@mkdir -p $(DIROBJ)

.PHONY: all bonus
