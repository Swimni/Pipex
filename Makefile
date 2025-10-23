# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 15:27:53 by nguinot-          #+#    #+#              #
#    Updated: 2025/10/23 18:18:26 by nguinot-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_DIR = src
INCLUDES_DIR = includes

SRCS = execute_cmd.c \
       get_cmd_path.c \
       splitcmd.c \
       split.c \
       strjoin.c \
       utilspipex.c \
       utilsmain.c \
       utilsmain2.c \
       utilsmain3.c \
       main.c

OBJS = $(addprefix $(SRC_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

