# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 18:05:04 by aennaqad          #+#    #+#              #
#    Updated: 2024/01/27 18:28:09 by aennaqad         ###   ########.fr        #
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

SRCS_B = To_linkedList.c \
			actions.c \
			algo_max_five.c \
			my_argsJoin.c \
			my_atoi.c \
			my_split.c \
			parsing.c \
			tools.c \
			tools_two.c \
			actions_two.c

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = push_swap
AR = ar -rcs

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) push_swap

re: fclean all

.PHONY: all clean fclean re
