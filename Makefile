# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 14:17:23 by gponcele          #+#    #+#              #
#    Updated: 2022/09/28 13:33:36 by gponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= minitalk
NAME_BONUS				= minitalk_bonus
CLIENT					= client
CLIENT_BONUS			= client_bonus
SERVER					= server
SERVER_BONUS			= server_bonus
LIBFT					= ./libft/libft.a
SRC_C					= client.c
SRC_C_BONUS				= client_bonus.c
SRC_S					= server.c server_utils.c
SRC_S_BONUS				= server_bonus.c server_bonus_utils.c
NORM					= @norminette
CC						= gcc
RM						= rm -f
INCLUDES				= -I./includes
CFLAGS					= -Wall -Wextra -Werror
OBJS_C					= $(SRC_C:.c=.o)
OBJS_C_BONUS			= $(SRC_C_BONUS:.c=.o)
OBJS_S					= $(SRC_S:.c=.o)
OBJS_S_BONUS			= $(SRC_S_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_C)
		$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC_C) -o $(CLIENT)

$(SERVER): $(OBJS_S)
		$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC_S) -o $(SERVER)

$(NAME_BONUS): $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
		$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC_C_BONUS) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJS_S_BONUS)
		$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(SRC_S_BONUS) -o $(SERVER_BONUS)

clean:
		rm -rf $(OBJS_S) $(OBJS_C) $(OBJS_S_BONUS) $(OBJS_C_BONUS)

fclean:	clean
		rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re:	fclean all

.PHONY: all clean fclean re