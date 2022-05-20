#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 12:37:06 by gtoubol           #+#    #+#              #
#    Updated: 2022/05/20 17:57:59 by gtoubol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRCS =		main.c stack_utils.c stack_push.c stack_swap.c stack_rotate.c	\
			stack_reverse_rotate.c ps_error.c args_to_stack.c show_state.c	\
			quick_sort.c sort_divide.c instructions_utils.c	\
			sort_instructions.c
OBJS = 		$(SRCS:.c=.o)

NAME = 		push_swap

LIBFT_DIR = libft
LIBFT =		libft/libft.a
LIB =		-Llibft -lft

CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
RM =		rm -f

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)

%.o:		%.c $(LIBFT)
			$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
			make -C $(LIBFT_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
