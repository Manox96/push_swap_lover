# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 17:14:20 by aennaqad          #+#    #+#              #
#    Updated: 2024/03/09 19:59:03 by aennaqad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long_Mondatoy/so_long.c \
			so_long_Mondatoy/tools_one.c \
			so_long_Mondatoy/the_game.c \
			so_long_Mondatoy/utils_game.c \
			so_long_Mondatoy/tools_two.c \
			so_long_Mondatoy/tool_game_three.c \
			so_long_Mondatoy/tools_two_game.c\
			so_long_Mondatoy/tools_two_paring.c\
			so_long_Mondatoy/tools_game.c \
			so_long_Mondatoy/tools_parsing.c \
			so_long_Mondatoy/utils_solong.c \
			so_long_Mondatoy/get_next_line/get_next_line.c \
 			so_long_Mondatoy/get_next_line/get_next_line_utils.c \

SRCS_B = so_longBonus/so_long_bonus.c \
			so_longBonus/tools_parsing_bonus.c \
			so_longBonus/tools_game_bonus.c \
			so_longBonus/tools_one_bonus.c \
			so_longBonus/tool_game_three_bonus.c \
			so_longBonus/utils_game_bonus.c \
			so_longBonus/the_game_bonus.c \
			so_longBonus/utils_two_game_bonus.c \
			so_longBonus/utils_game_three_bonus.c \
			so_longBonus/tools_two_paring_bonus.c\
			so_longBonus/animation_coin_bonus.c\
			so_longBonus/game_utils_one_bonus.c\
			so_longBonus/tools_two_bonus.c \
			so_longBonus/tools_two_game_bonus.c\
			so_longBonus/get_next_line_bonus/get_next_line.c \
 			so_longBonus/get_next_line_bonus/get_next_line_utils.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = so_long
NAME_B = so_long_bonus
H_MOND = so_long_Mondatoy/so_long.h
H_BONUS = so_longBonus/so_long_bonus.h
H_GET_M = so_long_Mondatoy/get_next_line/get_next_line.h
H_GET_B = so_longBonus/get_next_line_bonus/get_next_line.h

%_bonus.o: %_bonus.c $(H_BONUS) $(H_GET_B)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(H_MOND) $(H_GET_M)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all
	$(RM) $(OBJS) && clear

reb: fclean bonus
	$(RM) $(OBJS_B) && clear

.PHONY: clean