# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 18:05:04 by aennaqad          #+#    #+#              #
#    Updated: 2024/01/02 10:01:34 by aennaqad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c 

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_B:.c=.o)
NAME = push_swap.a
AR = ar -rcs

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BNS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus : $(OBJS_BNS)
	$(AR) $(NAME) $(OBJS_BNS)

.PHONY: all clean fclean re
