# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 19:08:52 by ialvarez          #+#    #+#              #
#    Updated: 2022/07/05 20:01:52 by vifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = minishell

SRCS = main.c \
	   pwd.c \

#	echo.c \
		#pwd.c \
		main.c \

OBJECTS = $(SRCS:.c=.o)
LIBFT_DIR = libft/
LIB_NAME = $(LIBFT_DIR)libft.a
INCLUDES = -I. -I$(LIBFT_DIR)
FSANITIZE = -g3 -fsanitize=address
READLINE = -L ~/.brew/opt/readline/lib -lreadline
CFLAGS = -Wall -Werror -Wextra -I ~/.brew/opt/readline/include -g3 $(INCLUDES)

all: $(NAME)

BCyan = \033[1;36m
GREEN = \033[0;32m
Yellow = \033[0;33m
Red = \033[0;31m
NO_COLOR = \033[0m

$(NAME): $(OBJECTS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(READLINE) $(CFLAGS) $(OBJECTS) ./libft/libft.a -o $(NAME)

debug: $(OBJECTS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(FSANITIZE) $^ -L ./libft/ -l ft -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

test: all
	@echo "$(GREEN)[RESULTS]$(NO_COLOR)"
	@./minishell

re: fclean all

.PHONY:
			clean
			fclean
			all
			re
			bonus
