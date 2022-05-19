#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 12:37:06 by gtoubol           #+#    #+#              #
#    Updated: 2022/05/19 13:06:54 by gtoubol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRCS =
OBJS = 		$(SRCS:.c=.o)

NAME = 		push_swap

LIBFT_DIR = libft
LIBFT =		libft/libft.a

CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror
RM =		rm -f

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)

%.o:		%.c $(LIBFT)
			$(CC) $(CFLAGS) -o $@ -c $^ $(LIB)

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
