# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 16:52:45 by gponcele          #+#    #+#              #
#    Updated: 2022/09/01 17:55:49 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS					= ft_printf.c ft_print_chars.c ft_print_nbr.c ft_print_others.c ft_isdigit.c \
								ft_atoi.c ft_strlen.c
OBJS					= $(SRCS:.c=.o)
CC						= gcc
RM						= rm -f
CFLAGS					= -Wall -Wextra -Werror
NAME					= libft.a
all:					$(NAME)
$(NAME):				$(OBJS)
								ar rc $(NAME) $(OBJS)
clean:
								$(RM) $(OBJS)

fclean:					clean
								$(RM) $(NAME)

re:								fclean all
.PHONY: 				all clean fclean re
