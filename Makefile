# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:05:19 by aglampor          #+#    #+#              #
#    Updated: 2024/08/23 18:03:21 by acoste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

NAME	= minishell

LDFLAGS = -lreadline -Llibft #-lft

SRC_DIR = src/

SRC_FILES = build_ft.c\
			env.c\
			exit.c\
			ft_split.c\
			split_ws.c\
			minishell.c\
			tokken.c\
			utils.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

GREEN = \033[92m
RESET = \033[0m

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	@$(MAKE) -sC libft
	@echo	"$(GREEN) Libft Compiled $(RESET)"

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -sC libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -sC libft fclean

re: fclean all
