# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 18:05:04 by aennaqad          #+#    #+#              #
#    Updated: 2024/01/25 16:40:08 by aennaqad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = To_linkedList.c \
			actions.c \
			algo_Max_three.c \
			algo_max_five.c \
			algo_hundred.c \
			my_argsJoin.c \
			my_atoi.c \
			my_split.c \
			parsing.c \
			push_swap.c \
			tools.c \
			tools_two.c \
			tools_algo_hundred.c \
			actions_two.c

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
OBJS = $(SRCS:.c=.o)
NAME = push_swap.a
AR = ar -rcs
AOUT = push_swap

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

go : all
	$(CC) $(NAME) -o push_swap && make clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) push_swap

re: fclean all

.PHONY: all clean fclean re
