# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 19:08:58 by marvin            #+#    #+#              #
#    Updated: 2022/11/19 19:08:58 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client
SERVER = server

B_CLIENT = client_bonus
B_SERVER = server_bonus

CLIENT_SRC = srcs/client.c
SERVER_SRC = srcs/server.c

B_CLIENT_SRC = srcs/client_bonus.c
B_SERVER_SRC = srcs/server_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

B_CLIENT_OBJ = $(B_CLIENT_SRC:.c=.o)
B_SERVER_OBJ = $(B_SERVER_SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE =  -I include -I libft

all: $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(CLIENT) $(SERVER) $(B_CLIENT) $(B_SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)

$(B_CLIENT): $(B_CLIENT_OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(B_CLIENT) $(B_CLIENT_OBJ) $(LIBFT)

$(B_SERVER): $(B_SERVER_OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(B_SERVER) $(B_SERVER_OBJ) $(LIBFT)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(B_CLIENT_OBJ) $(B_SERVER_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) -f $(CLIENT) $(SERVER) $(B_CLIENT) $(B_SERVER)
	make fclean -C $(LIBFT_DIR)

re: fclean all