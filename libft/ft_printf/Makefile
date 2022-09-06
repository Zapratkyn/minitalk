# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:46:30 by gponcele          #+#    #+#              #
#    Updated: 2022/08/30 12:50:06 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS					=			ft_printf.c \
									ft_print_chars.c \
									ft_print_nbr.c \
									ft_print_others.c 
OBJS					= $(SRCS:.c=.o)
NORM					= @norminette
CC						= gcc
RM						= rm -f
CFLAGS					= -Wall -Wextra -Werror
NAME					= libftprintf.a
all:					$(NAME)
$(NAME):				$(OBJS)
								ar rcs $(NAME) $(OBJS)
clean:
								$(RM) $(OBJS)
fclean:					clean
								$(RM) $(NAME)
re:								fclean $(NAME)
.PHONY					=all clean fclean re