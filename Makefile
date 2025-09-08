# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 15:27:53 by nguinot-          #+#    #+#              #
#    Updated: 2025/09/08 15:30:41 by nguinot-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex


CC = gcc
CFLAGS = -Wall -Wextra -Werror


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

SRC_BONUS = execute_cmd_bonus.c \
	   get_cmd_path.c \
	   splitcmd.c \
	   split.c \
	   strjoin.c \
	   utilspipex.c \
	   utilsmainbonus.c \
	   utilsmainbonus2.c \
	   utilsmainbonus3.c \
	   utilsmainbonus4.c \
	   mainbonus.c 

OBJS = $(SRCS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	rm -f $(OBJS) $(OBJ_BONUS)


fclean: clean
	rm -f $(NAME) $(NAME)_bonus

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)_bonus

re: fclean all


.PHONY: all clean fclean re
