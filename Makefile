# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:06:27 by palexand          #+#    #+#              #
#    Updated: 2024/12/09 21:36:13 by palexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## FILES ##
SRCS = main.c sources/ft_moves.c sources/sorted.c sources/free.c \
			 sources/ft_atol.c sources/confirm_numbers.c sources/ft_stacks.c 
OBJS = $(SRCS:.c=.o)
NAME = push_swap

## COMPILATION ##
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LIBS = libs/Libft/libft.a libs/Printf/libftprintf.a
RM = rm -f
AR = ar rcs

all: deps $(NAME)

deps:
	make -C ./libs/Libft
	make -C ./libs/Printf

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C libs/Libft clean
	make -C libs/Printf clean

fclean: clean
	$(RM) $(NAME)
		make -C libs/Libft fclean
		make -C libs/Printf fclean


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

