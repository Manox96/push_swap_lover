# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 18:05:04 by aennaqad          #+#    #+#              #
#    Updated: 2024/01/29 16:32:45 by aennaqad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	src/To_linkedList.c \
			src/actions.c \
			src/algo_Max_three.c \
			src/algo_max_five.c \
			src/algo_hundred.c \
			src/my_argsJoin.c \
			src/my_atoi.c \
			src/my_split.c \
			src/parsing.c \
			src/push_swap.c \
			src/tools.c \
			src/tools_two.c \
			src/tools_algo_hundred.c \
			src/actions_two.c

SRCS_B = bonus/To_linkedList_bonus.c \
			bonus/actions_bonus.c \
			bonus/actions_two_bonus.c \
			bonus/checker_bonus.c \
			bonus/my_argsJoin_bonus.c \
			bonus/my_atoi_bonus.c \
			bonus/my_split_bonus.c \
			bonus/parsing_bonus.c \
			bonus/tools_two_bonus.c \
			bonus/utils_bonus_bonus.c \
			bonus/get_next_line/get_next_line.c \
			bonus/get_next_line/get_next_line_utils.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = push_swap
NAME_BNS = checker
AR = ar -rcs
H_MOND = headers/push_swap.h
H_BNS = headers/checker_bonus.h

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

%.o: %.c $(H_MOND) $(H_BNS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(NAME_BNS)

$(NAME_BNS): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_BNS)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)  $(NAME_BNS)


re: fclean all

.PHONY: all clean fclean re
