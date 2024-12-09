# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:06:27 by palexand          #+#    #+#              #
#    Updated: 2024/12/09 17:06:47 by palexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## FILES ##
SRCS = main.c ft_moves.c sorted.c free.c ft_atol.c confirm_numbers.c ft_stacks.c 
OBJS = $(SRCS:.c=.o)
NAME = push_swap

## COMPILATION ##
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = Libft/libft.a Printf/libftprintf.a
RM = rm -f
AR = ar rcs

all: deps $(NAME)

deps:
	make -C ./Libft
	make -C ./Printf

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C Libft clean
	make -C Printf clean

fclean: clean
	$(RM) $(NAME)
		make -C Libft fclean
		make -C Printf fclean


re: fclean all

visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git && \
	cd push_swap_visualizer && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	./bin/visualizer	
	
.PHONY: all clean fclean re

