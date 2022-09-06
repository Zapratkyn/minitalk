# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 14:17:23 by gponcele          #+#    #+#              #
#    Updated: 2022/09/01 16:10:33 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= minitalk
CLIENT					= client
SERVER					= server
LIBFT					= ./libft/libft.a
SRC_C					= client.c
SRC_S					= server.c
NORM					= @norminette
CC						= gcc
RM						= rm -f
INCLUDES				= -I./includes
CFLAGS					= -Wall -Wextra -Werror
OBJS_C					= $(SRC_C:.c=.o)
OBJS_S					= $(SRC_S:.c=.o)
all						= $(NAME)

$(NAME): $(OBJS_C) $(OBJS_S)
		$(MAKE) -C ./libft
		$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC_C) -o $(CLIENT)
		$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC_S) -o $(SERVER)

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS_S) $(OBJS_C)

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(CLIENT) $(SERVER)

re:	fclean all

.PHONY: all clean fclean re