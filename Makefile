#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 12:37:06 by gtoubol           #+#    #+#              #
#    Updated: 2022/05/24 18:51:12 by gtoubol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRCS =		main.c stack_utils.c stack_push.c stack_swap.c stack_rotate.c	\
			stack_reverse_rotate.c ps_error.c args_to_stack.c show_state.c	\
			quick_sort.c sort_divide.c instructions_utils.c	naive_sort.c 	\
			sort_instructions.c sort_utils.c small_sort.c sort_insert.c		\
			stack_calculus.c
OBJS = 		$(SRCS:.c=.o)
BONUS =		checker.c ps_error.c stack_calculus.c stack_push.c 				\
			stack_reverse_rotate.c stack_rotate.c stack_swap.c stack_utils.c\
			checker_instructions.c args_to_stack.c instructions_utils.c
OBJS_BONUS = $(BONUS:.c=.o)

NAME = 		push_swap
NAME_B = 	checker_the_bonus

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

bonus:		$(NAME_B)

$(NAME_B):	$(OBJS_BONUS)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LIBFT):
			make -C $(LIBFT_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_B)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
