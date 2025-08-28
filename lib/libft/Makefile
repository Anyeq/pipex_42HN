# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 14:20:33 by asando            #+#    #+#              #
#    Updated: 2025/08/10 14:43:14 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

HEADER = include

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

DIRSRC = src

SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
	   ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c \
	   ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c ft_strnstr.c \
	   ft_tolower.c ft_bzero.c   ft_isascii.c ft_striteri.c \
	   ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
	   ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
	   ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c

BONUS = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
		ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c

SRC_FILES = $(addprefix $(DIRSRC)/, $(SRCS))

BONUS_FILES = $(addprefix $(DIRSRC)/, $(BONUS))

DIROBJ = obj

SRC_OBJS = $(SRCS:%.c=$(DIROBJ)/%.o)

BONUS_OBJS = $(BONUS:%.c=$(DIROBJ)/%.o)

DIR_FT_PRINTF = $(DIRSRC)/ft_printf

FT_PRINTF_NAME = $(DIR_FT_PRINTF)/libftprintf.a

NAME = libft.a

all: $(NAME) $(FT_PRINTF_NAME)
	@echo "Libft Build Completed"

$(NAME): $(SRC_OBJS)
	@echo "All object file successfully compiled"
	@ar crs $@ $(SRC_OBJS)

$(DIROBJ)/%.o: $(DIRSRC)/%.c | $(DIROBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIROBJ):
	@mkdir -p $(DIROBJ)
	@echo "Obj folder created"

$(FT_PRINTF_NAME):
	@$(MAKE) -C $(DIR_FT_PRINTF)

clean:
	@rm -rf $(DIROBJ)
	@echo "Obj folder deleted"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(FT_PRINTF_NAME)
	@echo "libft.a deleted"
	@echo "libftprintf.a deleted"

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

bonus: $(SRC_OBJS) $(BONUS_OBJS)
	@echo "All bonus object file is succesfully compiled"
	@ar crs $(NAME) $(SRC_OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
